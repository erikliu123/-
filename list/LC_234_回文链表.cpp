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
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        //找到中点
        int len = 0;

        for (auto p = head; p; p = p->next)
        {
            len++;
        }
        if (len == 1)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
       
        ListNode *prev = head, *after = head->next;
        ListNode *tmp = NULL;
        if (len & 0x1)//奇数，则翻转slow前面的[start, slow)
            while (after && prev != slow && after != slow)
            {
                tmp = after->next;
                after->next = prev;
                prev = after;
                after = tmp;
            }
        else
        {
            slow = slow->next;//偶数，翻转到[start, slow]
            while (after && prev != slow && after != slow)
            {
                tmp = after->next;
                after->next = prev;
                prev = after;
                after = tmp;
            }
        }
        head->next = NULL;
        //从after开始遍历
        after = prev;
        if (len % 2)
        {
            slow = slow->next;
            while (after)
            {
                if (after->val != slow->val)
                    return false;
                after = after->next;
                slow = slow->next;
            }
        }
        else
        {
            //slow = slow->next;
            while (after)
            {
                if (after->val != slow->val)
                    return false;
                after = after->next;
                slow = slow->next;
            }
        }
        return true;
    }
};