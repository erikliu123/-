#include "btreestore.h"
#include <pthread.h>
#include <malloc.h>
#include <string.h>

#define CIPHER (0x9E3779B9)

typedef uint32_t key_type;
typedef struct
{
    struct{
        key_type key;
        // char *plaintext; //malloc
        // int len;
        struct info value;
    };
    // struct{
    //     key_type *keys;
    //     struct info *data;
    // };

} kv_data;
// typedef struct tree_node
// {
//     int num_child;
//     int *keys; //key[0] doesn't use
//     struct tree_node *child;
//     struct tree_node *parent; //silibing
// } tree_node;

typedef struct tree_node //B tree's node
{
    int valid_keys; //the number of keys
    kv_data *kv;

    struct tree_node *parent;  // pointer of parent
    struct tree_node **childs; // pointer of childrens
} tree_node, *tree_node_t;

typedef struct
{
    pthread_mutex_t mutex;
    int max_nodes;
    //int max_key;
    int nr_cpus;
    tree_node *root;
} btree, *btree_t;

void insert_btree(btree *bt, int i, kv_data *kv, tree_node *p);
int search_btree(btree *bt, key_type k, int *index, tree_node **node);

/* delete related functions */
void restore(btree_t bt, tree_node_t *t, tree_node_t p);
void borrow_from_brother(btree_t bt, tree_node_t p, tree_node_t left_brother, tree_node_t right_brother, tree_node_t parent, int *index);
void merge_left_brother(btree_t bt, tree_node_t left_brother, tree_node_t parent, tree_node_t p, tree_node_t *t, int *index);
void delete_btree_node(btree_t bt, tree_node_t *t, tree_node_t p, int i) ;
void merge_right_brother(btree_t bt, tree_node_t right_brother, tree_node_t parent, tree_node_t p, tree_node_t *t, int *index);

void *init_store(uint16_t branching, uint8_t n_processors)
{
    // Your code here
    btree *s = (btree *)malloc(sizeof(btree));
    if (!s)
        return NULL;
    s->max_nodes = branching;
    s->nr_cpus = n_processors;
    s->root = NULL;
    pthread_mutex_init(&(s->mutex), NULL);
    return (void *)s;
}

tree_node *alloc_bt_node(int num_kvs)
{
    tree_node *t = (tree_node *)malloc(sizeof(tree_node));
    if(t){
        t->valid_keys = 0;
        t->parent = NULL;
        t->childs = (tree_node **)malloc(sizeof(tree_node_t) * (num_kvs+1));//one for overflow
        t->kv = (kv_data *)malloc(sizeof(kv_data) * (num_kvs+1));
        for(int i=0; i < num_kvs + 1; i++) 
            t->childs[i] = NULL;
    }
    return t;
}


void destory_btree(tree_node_t *root)
{
    if(*root)
    {
        for(int i=0; i<=(*root)->valid_keys; i++)
        {
            destory_btree(&(*root)->childs[i]);
            if(i!=0)
                free((*root)->kv[i].value.data);
        }
        free((*root)->childs);
        free((*root)->kv);
        free(*root);
        *root = NULL;
    }

}
void close_store(void *helper)
{
    // Your code here
    btree *bt = (btree *)helper;
    pthread_mutex_lock(&bt->mutex);
    //free all data nodes
    destory_btree(&(bt->root));

    //release lock and destory it
    pthread_mutex_unlock(&bt->mutex);
    pthread_mutex_destroy(&bt->mutex);
    free(helper);
    return;
}

int search_btree(btree *bt, key_type k, int *index, tree_node **node)
{
    tree_node *p = bt->root, *q = NULL;
    int found = 0;
    int i = 0;
    *node = NULL;
    while (p != NULL && found == 0)
    {

        for (i = 0; i < p->valid_keys && p->kv[i + 1].key <= k; i++)
            ;
        *index = i;
        *node = p;
        if (i > 0 && p->kv[i].key == k)
        { //find key
            found = 1; 
            //printf("successfully find %d\n", k);
        }
        else
        {
            q = p;
            p = p->childs[i];
        }
    }
    return found;
}

int btree_insert(uint32_t key, void *plaintext, size_t count, uint32_t encryption_key[4], uint64_t nonce, void *helper)
{
    // Your code here
    btree *bt = (btree *)helper;
    pthread_mutex_lock(&bt->mutex);
    int index;
    tree_node *node;
    kv_data kv;
    uint64_t *plain_buf;
    int num_blocks = ((count + 1 + 7)/ 8);//reserve '\0'
    //search whether key exists
    int ret = search_btree(bt, key, &index, &node);
    if (ret)
    {
        pthread_mutex_unlock(&bt->mutex);
        return 1;
    }
    //insert kv-pair into B-tree
    kv.key = key;
    kv.value.nonce = nonce;
    kv.value.data = (void *)malloc(num_blocks * sizeof(uint64_t));
    kv.value.size = count;//num_blocks * sizeof(uint64_t);
    for(int i=0; i<4; i++)
    {
        kv.value.key[i] = encryption_key[i];
    }

    plain_buf = (uint64_t *)malloc(num_blocks * 8);
    memset(&plain_buf[num_blocks-1], 0, sizeof(uint64_t));
    memcpy(plain_buf, plaintext, count);

    encrypt_tea_ctr(plain_buf, encryption_key, nonce, (uint64_t *)kv.value.data, num_blocks);
    free(plain_buf);

    
    insert_btree(bt, index, &kv, node);
    pthread_mutex_unlock(&bt->mutex);
    return 0;
}

void new_root(btree *bt, kv_data *kv, tree_node *p, tree_node *q)
{
    tree_node *t = alloc_bt_node(bt->max_nodes);
    t->valid_keys = 1;
    t->parent = NULL;
    t->childs[0] = p;
    t->childs[1] = q;
    t->kv[1] = *kv;
    if (p != NULL)
        p->parent = t;
    if (q != NULL)
        q->parent = t;

    bt->root = t;
}

void insert_btree_node(tree_node *parent, int i, kv_data *kv, tree_node *q)
{
    int j;
    for (j = parent->valid_keys; j > i; j--)
    { //shift right
        parent->kv[j + 1] = parent->kv[j];
        parent->childs[j + 1] = parent->childs[j];
    }
    parent->kv[i + 1] = *kv;
    //printf("key:%d \n", parent->kv[i + 1].key);
    parent->childs[i + 1] = q;
    if (q != NULL)
        q->parent = parent;
    parent->valid_keys++;
}

void split_btree(btree *bt, tree_node *p, tree_node **q)
{
    int i;
    int s = (bt->max_nodes + 1) / 2;
    *q = alloc_bt_node(bt->max_nodes);
    (*q)->childs[0] = p->childs[s]; 
    for (i = s + 1; i <= bt->max_nodes; i++)//not i <= bt->max_nodes
    {
        (*q)->kv[i - s] = p->kv[i];
        (*q)->childs[i-s] = p->childs[i];
    }
    (*q)->valid_keys = p->valid_keys - s;
    //printf("q's children is %d\n", (*q)->valid_keys);
    (*q)->parent = p->parent;
    for (i = 0; i <= (*q)->valid_keys; i++)
        if ((*q)->childs[i] != NULL)
            (*q)->childs[i]->parent = *q;
    p->valid_keys = s - 1; 
}

void insert_btree(btree *bt, int i, kv_data *kv, tree_node *p)
{
    tree_node *q;
    int finish, should_alloc, s;
    kv_data *x; //key
    if (p == NULL) //empty tree
        new_root(bt, kv, NULL, NULL);
    else
    {
        x = kv;
        q = NULL;
        finish = 0;
        should_alloc = 0;
        while (finish == 0 && should_alloc == 0)
        {
            insert_btree_node(p, i, x, q); //insert p->key[i+1] and p->ptr[i+1]
            if (p->valid_keys < bt->max_nodes)
                finish = 1; //insert finish
            else
            {
                s = (bt->max_nodes+1) / 2;
                //printf("split tree\n");
                split_btree(bt, p, &q); //split tree
                x = &p->kv[s];
                if (p->parent)
                { //look for key's insert position
                    p = p->parent;
                    for (i = 0; i < p->valid_keys && p->kv[i + 1].key <= x->key; i++)
                        ;
                }
                else //fail to find key
                    should_alloc = 1;
            }
        }
        if (should_alloc == 1)
            new_root(bt, x, p, q);
    }
}

int btree_retrieve(uint32_t key, struct info *found, void *helper)
{
    // Your code here
    btree *bt = (btree *)helper;
    int index;
    tree_node *node;
    //search whether key exists
    pthread_mutex_lock(&bt->mutex);
    int ret = search_btree(bt, key, &index, &node);
    if (!ret)
    {
        pthread_mutex_unlock(&bt->mutex);
        return 1;
    }
    *found = node->kv[index].value;
    pthread_mutex_unlock(&bt->mutex);
    return 0;
}

int btree_decrypt(uint32_t key, void *output, void *helper)
{
    // Your code here
    btree *bt = (btree *)helper;
    int index;
    tree_node *node;
    struct info *in;
    //search whether key exists
    pthread_mutex_lock(&bt->mutex);
    int ret = search_btree(bt, key, &index, &node);
    if (!ret)
    {
        pthread_mutex_unlock(&bt->mutex);
        return 1;
    }
    in = &(node->kv[index].value);
    decrypt_tea_ctr((uint64_t *)(in->data), in->key, in->nonce, (uint64_t *)output, (in->size + 7)/8);
    //printf("analysis of decrypt: %s\n", output);
    pthread_mutex_unlock(&bt->mutex);
    return 0;
}

int btree_delete(uint32_t key, void *helper)
{
    // Your code here
    btree *bt = (btree *)helper;
    pthread_mutex_lock(&bt->mutex);
    int index;
    tree_node *node;
    //search whether key exists
    int ret = search_btree(bt, key, &index, &node);
    if (ret == 0)//don't exist
    {
        pthread_mutex_unlock(&bt->mutex);
        return 1;
    }
    //TODO:
    delete_btree_node(bt, &bt->root, node, index);

    pthread_mutex_unlock(&bt->mutex);
    return -1;
}


int num_node(tree_node_t root)
{
    int ret = 0;
    if(root!=NULL)
    {
        ret ++;
        for(int i=0; i<=root->valid_keys; i++){
            ret += num_node(root->childs[i]);
        }
        
    }
    return ret;
}
void record_node(tree_node_t root, struct node *list, int *index)
{
    if(root!=NULL)
    {
        list[*index].num_keys = root->valid_keys;
        list[*index].keys = (key_type *)malloc(root->valid_keys * sizeof(key_type));
        for(int i=0; i<root->valid_keys; i++)
        {
            //printf("[%d, %llx]", root->kv[i+1].key, root->kv[i+1].value.nonce);
            list[*index].keys[i] = root->kv[i+1].key;
        }
        //putchar('\n');
        (*index) ++;
        for(int i=0; i<=root->valid_keys; i++){
            record_node(root->childs[i], list, index);
        }
        
    }

}
uint64_t btree_export(void *helper, struct node **list)
{
    // Your code here
    btree *bt = (btree *)helper;
    struct node *bt_node;
   
    int index = 0, num;
    pthread_mutex_lock(&bt->mutex);
    num = num_node(bt->root);
    if(num == 0){
        *list = NULL;
        return 0;
    }
    *list = (struct node *)malloc(num * sizeof(struct node));
    //printf("nodes: %d\n", num);
    record_node(bt->root, *list, &index);
    pthread_mutex_unlock(&bt->mutex);
    return num;
}

void encrypt_tea(uint32_t plain[2], uint32_t cipher[2], uint32_t key[4])
{
    // Your code here
    uint32_t sum = 0;
    uint32_t tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
    uint32_t delta = CIPHER;
    cipher[0] = plain[0];
    cipher[1] = plain[1];
    for(int i=0; i<1024; i++)
    {
        sum = (sum + delta);
        tmp1 = ((cipher[1] << 4) + key[0]);
        tmp2 = (cipher[1] + sum);
        tmp3 = ((cipher[1] >> 5) + key[1]);
        cipher[0] = (cipher[0] + (tmp1 ^ tmp2 ^ tmp3));
        tmp4 = ((cipher[0] << 4) + key[2]);
        tmp5 = (cipher[0] + sum);
        tmp6 = ((cipher[0] >> 5) + key[3]);
        cipher[1] = (cipher[1] + (tmp4 ^ tmp5 ^ tmp6));
    }
    return;
}

void decrypt_tea(uint32_t cipher[2], uint32_t plain[2], uint32_t key[4])
{
    // Your code here
    uint32_t sum = CIPHER << 10;
    uint32_t delta = CIPHER;
    uint32_t tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
    for(int i=0; i<1024; i++)
    {
        tmp4 = ((cipher[0] << 4) + key[2]);
        tmp5 = (cipher[0] + sum);
        tmp6 = ((cipher[0] >> 5) + key[3]);
        cipher[1] = (cipher[1] - (tmp4 ^ tmp5 ^ tmp6)); 
        tmp1 = ((cipher[1] << 4) + key[0]);
        tmp2 = (cipher[1] + sum);
        tmp3 = ((cipher[1] >> 5) + key[1]);
        cipher[0] = (cipher[0] - (tmp1 ^ tmp2 ^ tmp3)); 
        sum = (sum - delta);
    }
    plain[0] = cipher[0];
    plain[1] = cipher[1];
    return;
}

void encrypt_tea_ctr(uint64_t *plain, uint32_t key[4], uint64_t nonce, uint64_t *cipher, uint32_t num_blocks)
{
    // Your code here
    for(int k=0; k<num_blocks; k++)
    {
         uint64_t tmp1 = ((uint64_t)k) ^ nonce, tmp2;
         encrypt_tea((uint32_t *)&tmp1, (uint32_t *)&tmp2, key);
         //printf("before crypt[%llx], after crypt[%llx]\n", tmp1, tmp2);
         cipher[k] = plain[k] ^ tmp2;

    }
    return;
}

void decrypt_tea_ctr(uint64_t *cipher, uint32_t key[4], uint64_t nonce, uint64_t *plain, uint32_t num_blocks)
{
    // Your code here
    for(int k=0; k<num_blocks; k++)
    {
        uint64_t tmp1 = ((uint64_t)k) ^ nonce, tmp2;
        encrypt_tea((uint32_t *)&tmp1, (uint32_t *)&tmp2, key);
        //decrypt_tea((uint32_t *)&tmp1, (uint32_t *)&tmp2, key);
        //printf("crypt text [%llx], after decrypt[%llx]\n", tmp1, tmp2);
        plain[k] = cipher[k] ^ tmp2;

    }
    return;
}


void delete_btree_node(btree_t bt, tree_node_t *t, tree_node_t p, int i) {
    if (p->childs[i] != NULL) {//internal node
        tree_node_t leaf = p;
        if (NULL == p) {
            return;
        }
        leaf = leaf->childs[i]; //
        while (NULL != leaf->childs[0]) {
            //find leftest sub node
            leaf = leaf->childs[0];
        }
        p->kv[i] = leaf->kv[1];
        p = leaf;
        delete_btree_node(bt, t, p, 1); //delete leftest key
    } 
    else{//leaf node  
        int k;
        for (k = i; k < p->valid_keys; k++) {
            p->kv[k] = p->kv[k + 1];
            p->childs[k] = p->childs[k + 1];
        }
        p->valid_keys--;
        if (p->valid_keys < (bt->max_nodes- 1) / 2) {
            restore(bt, t, p); // adjust B-tree
        }
    }
}


void restore(btree_t bt, tree_node_t *t, tree_node_t p) {
    tree_node_t parent, left_brother, right_brother; 
    parent = p->parent;
    if (parent != NULL){
        int i;
        for (i = 0; i <= parent->valid_keys; i++) {
            if (parent->childs[i] == p) {
                break;
            }
        }
        if (i > 0) {
            left_brother = parent->childs[i - 1];
        } else {
            left_brother = NULL;
        }
        if (i < parent->valid_keys) {
            right_brother = parent->childs[i + 1];
        } else {
            right_brother = NULL;
        }

        if ((left_brother != NULL && left_brother->valid_keys >= (bt->max_nodes+ 1) / 2) ||
            (right_brother != NULL && right_brother->valid_keys >= (bt->max_nodes+ 1) / 2)) {
            borrow_from_brother(bt, p, left_brother, right_brother, parent, &i);
        } else {
            // merge with left or right brother
            if (left_brother != NULL) {
                merge_left_brother(bt, left_brother, parent, p, t, &i); // 与左兄弟合并
            } else if (right_brother != NULL) {
                merge_right_brother(bt, right_brother, parent, p, t, &i);
            } else  {
                //change root 
                for (int j = 0; j <= p->valid_keys + 1; j++) {
                    if (p->childs[j] != NULL) {
                        *t = p->childs[j];
                        break;
                    }
                }
                (*t)->parent = NULL;
            }
        }
    } else {// root node
        tree_node_t a;
        for (int j = 0; j <= p->valid_keys + 1; j++) {
            if (p->childs[j] != NULL) {
                a = p;
                p = p->childs[j];
                a->childs[j] = NULL;
                free(a);
                break;
            }
        }
        *t = p;
        (*t)->parent = NULL;
    }
}


void borrow_from_brother(btree_t bt, tree_node_t p, tree_node_t left_brother, tree_node_t right_brother, tree_node_t parent, int *index) {
    int i = *index;
    if (left_brother != NULL && left_brother->valid_keys >= (bt->max_nodes+ 1) / 2) {
        for (int j = p->valid_keys + 1; j > 0; j--) {
            // shift right
            if (j > 1) {
                p->kv[j] = p->kv[j - 1];
            }
            p->childs[j] = p->childs[j - 1];
        }
        p->childs[0] = left_brother->childs[left_brother->valid_keys];
        if (p->childs[0] != NULL) {
            p->childs[0]->parent = p;
        }
        left_brother->childs[left_brother->valid_keys] = NULL;
        p->kv[1] = parent->kv[i]; // 被删结点存父结点关键字
        parent->kv[i] = left_brother->kv[left_brother->valid_keys]; // 父结点的key变为被删结点左兄弟的最大关键字
        left_brother->valid_keys--;
        p->valid_keys++;
    } else if (right_brother != NULL && right_brother->valid_keys >= (bt->max_nodes+ 1) / 2) { // 右兄弟有富余关键字
        p->kv[p->valid_keys + 1] = parent->kv[i + 1];
        p->childs[p->valid_keys + 1] = right_brother->childs[0];    // 子树指针指向右兄弟最左边的子树指针
        if (p->childs[p->valid_keys + 1] != NULL) {
            p->childs[p->valid_keys + 1]->parent = p;
        }
        p->valid_keys++;
        parent->kv[i + 1] = right_brother->kv[1];        // 父结点从右兄弟借关键字
        for (int j = 0; j < right_brother->valid_keys; j++) {
            if (j > 0) {
                right_brother->kv[j] = right_brother->kv[j + 1];
            }
            right_brother->childs[j] = right_brother->childs[j + 1];
        }
        right_brother->childs[right_brother->valid_keys] = NULL;
        right_brother->valid_keys--;
    }
}


void merge_left_brother(btree_t bt, tree_node_t left_brother, tree_node_t parent, tree_node_t p, tree_node_t *t, int *index) {
    int i = *index;
    left_brother->kv[left_brother->valid_keys + 1] = parent->kv[i];    // 从父结点拿下分割本节点与左兄弟的关键字
    left_brother->childs[left_brother->valid_keys + 1] = p->childs[0];
    if (left_brother->childs[left_brother->valid_keys + 1] != NULL) {
        left_brother->childs[left_brother->valid_keys + 1]->parent = left_brother;    // 给左兄弟的结点，当此结点存在时需要把其父亲指向指向左结点
    }
    left_brother->valid_keys++; //左兄弟关键数加1
    for (int j = 1; j <= p->valid_keys; j++) {
        // 把本结点的关键字和子树指针赋给左兄弟
        left_brother->kv[left_brother->valid_keys + j] = p->kv[j];
        left_brother->childs[left_brother->valid_keys + j] = p->childs[j];
        if (left_brother->childs[left_brother->valid_keys + j] != NULL) {
            left_brother->childs[left_brother->valid_keys + j]->parent = left_brother;
        }
    }
    left_brother->valid_keys += p->valid_keys;
    parent->childs[i] = NULL;
    free(p);    // 释放p结点
    for (int j = i;j < parent->valid_keys; j++) {
        // 左移
        parent->kv[j] = parent->kv[j + 1];
        parent->childs[j] = parent->childs[j + 1];
    }
    parent->childs[parent->valid_keys] = NULL;
    parent->valid_keys--;        // 父结点关键字个数减1
    if (*t == parent) {
        // 如果此时父结点为根，则当父结点没有关键字时才调整
        if (0 == parent->valid_keys) {
            for (int j = 0;j <= parent->valid_keys + 1; j++) {
                if (parent->childs[j] != NULL) {
                    *t = parent->childs[j];
                    break;
                }
                (*t)->parent = NULL;
            }
        }
    } else {
        // 如果父结点不为根，则需要判断是否需要重新调整
        if (parent->valid_keys < (bt->max_nodes- 1) / 2) {
            restore(bt, t, parent);
        }
    }
}

void merge_right_brother(btree_t bt, tree_node_t right_brother, tree_node_t parent, tree_node_t p, tree_node_t *t, int *index) {
    int i = *index;
    for (int j = (right_brother->valid_keys); j > 0; j--) {
        if (j > 0) {
            right_brother->kv[j + 1 + p->valid_keys] = right_brother->kv[j];
        }
        right_brother->childs[j + 1 + p->valid_keys] = right_brother->childs[j];
    }
    right_brother->kv[p->valid_keys + 1] = parent->kv[i + 1];    // 把父结点的分割两个本兄弟和右兄弟的关键字拿下来使用
    for (int j = 0; j <= p->valid_keys; j++) {
        // 把本结点的关键字及子树指针移动右兄弟中去
        if (j > 0) {
            right_brother->kv[j] = p->kv[j];
        }
        right_brother->childs[j] = p->childs[j];
        if (right_brother->childs[j] != NULL) {
            right_brother->childs[j]->parent = right_brother;    // 给右兄弟的结点需要把其父结点指向右兄弟
        }
    }
    right_brother->valid_keys += (p->valid_keys + 1);
    parent->childs[i] = NULL;
    free(p); // 释放p结点
    for (int j = i;j < parent->valid_keys;j++) {
        if (j > i) {
            parent->kv[j] = parent->kv[j + 1];
        }
        parent->childs[j] = parent->childs[j + 1];
    }
    if (1 == parent->valid_keys) {
        // 如果父结点在关键字减少之前只有一个结点，那么需要把父结点的右孩子赋值给左孩子
        parent->childs[0] = parent->childs[1];
    }
    parent->childs[parent->valid_keys] = NULL;
    parent->valid_keys--;                    // 父结点关键字数减1
    if ((*t) == parent) {
        //如果此时父结点为根，则当父结点没有关键字时才调整
        if (0 == parent->valid_keys) {
            for (int j = 0; j <= parent->valid_keys + 1; j++) {
                if (parent->childs[j] != NULL) {
                    (*t) = parent->childs[j];
                    break;
                }
            }
            (*t)->parent = NULL;
        }
    } else {
        //如果父结点不为根，则需要判断是否需要重新调整
        if (parent->valid_keys < (bt->max_nodes - 1) / 2) {
            restore(bt, t, parent);
        }
    }
}
