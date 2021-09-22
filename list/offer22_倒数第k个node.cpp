/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。
*/
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast = head, *q = head;
        if(!fast) return NULL;
        for(int i=1; i<=k; i++)
        {
            if(fast) return NULL;
            fast = fast->next;
            //if(!fast) return NULL;
        }
        while(fast)
        {
            fast = fast->next;
            q = q->next;
        }
        return q;


    }
};


class Solution2 {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast = head, *q = head;
        if(!fast) return NULL;
        for(int i=1; i<k; i++)
        {
            fast = fast->next;
            if(!fast) return NULL;
        }
        while(fast->next)
        {
            fast = fast->next;
            q = q->next;
        }
        return q;


    }
};