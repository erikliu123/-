
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        if(fast)
            fast=fast->next;
        else
            return false;
        while(fast && slow)
        {
            if(fast == slow) return true;
            if(fast->next)
                fast = fast->next->next;
            else
                return false;
            slow = slow->next;
        }
        return false;
        
    }
};