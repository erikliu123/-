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

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。


示例 1：

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
*/
bool compare(ListNode* a, ListNode *b)
{
    return a->val > b->val;//NOTOICE: 要想形成小堆，必须要是大于！  和sort相反
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, decltype(&compare)> pq(&compare);
        ListNode* head=new ListNode(), *p=head;
        int n=lists.size();
        int finish_lists = 0, should_finish=0;
        for(int i=0; i<n; i++){
            if(lists[i]!=NULL) {
                should_finish++;
                pq.push(lists[i]);
            }
        }
        while(finish_lists < should_finish)
        {
            ListNode *item=pq.top();
            //cout<<item->val<<" ";
            pq.pop();
            p->next = item;
            p=item;
            if(item->next)
                pq.push(item->next);
            else
                finish_lists++;
            item->next = NULL;
        }
        p=head->next;
        delete head;
        return p;

    }
};
