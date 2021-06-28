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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
    // if (!head)
    //     return head;
    // head->next = removeElements(head->next, val);
    // return head->val == val ? head->next : head;

        ListNode* new_head = new ListNode(-1, head), *p=new_head->next, *q=new_head;
        while(p)
        {
            if(p->val == val){
                q->next = p->next;    
            }
            else{
                q=p;
            }
            p=p->next;
        }
        return new_head->next;

    }
};