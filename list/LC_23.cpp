
#include<queue>
#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
bool compare(ListNode* a, ListNode *b)//表示儿子和父亲的关系那样才正常
{
    return a->val > b->val;//NOTOICE: 要想形成小堆，必须要是大于！ 和sort相反
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(), *temp=head;
        //vector<int> myindex(lists.size(), 0);
        priority_queue<ListNode*, vector<ListNode*>, decltype(&compare)> pq(&compare);//不要忘记pq(&compare)
        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i]){
                pq.push(lists[i]);
            }

        }
        while(pq.size() > 0)
        {
            ListNode *p = pq.top();
            if(p->next) {
                pq.push(p->next);
            }
            pq.pop();
            p->next = NULL;
            temp->next = p;
            temp = p;
        }

        return head->next;

    }
};

int main()
{

    ListNode p[5];
    vector<ListNode *> node;
    for(int i=0; i<5; i++)
    {
        //ListNode temp;
        node.push_back(&p[i]);
        ListNode *tmp = new ListNode(100-i);
        tmp->next = p[i].next;
        p[i].next = tmp;
    }
    Solution a;
    ListNode *s = a.mergeKLists(node);



    
    return 0;
}