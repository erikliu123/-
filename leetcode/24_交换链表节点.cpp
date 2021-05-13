#include <iostream>
#include <queue>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//TODO: 加快思考速度
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *phead= new ListNode(), *p=phead, *prev=phead;
        phead->next = head;
        p=p->next;

        while(p && p->next)
        {
            ListNode *after = p->next, *next = p->next->next;
            prev->next = after;
            //p->next = after->next;
            after->next = p;
            prev = p;
            p->next = NULL;//思考：，如果不设置NULL，应该怎么做，参考Solution2

            p=next;
        }
        if(p) prev->next = p;
        return phead->next;


    }
};


class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *phead= new ListNode(), *p=phead, *prev=phead;
        phead->next = head;
        p=p->next;

        while(p && p->next)
        {
            ListNode *after = p->next, *next = p->next->next;
            prev->next = after;
            //p->next = after->next;
            after->next = p;
            prev = p;
            p->next = next;//减少最后的if判断

            p=next;
        }
        //if(p) prev->next = p;
        return phead->next;


    }
};