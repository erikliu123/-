
/*
148. 排序链表
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：
你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 
*/
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
    ListNode* quickSort(ListNode* head)
    {
        if(!head) return nullptr;
        if(!head->next) return head;
         bool sorted = true;
        int prev = head->val;
        for(auto x=head->next; x; x=x->next)//必须判断有序
        {
            if(x->val < prev){
                
                sorted = false;
            }
            prev = x->val;
        }
        if(sorted)
            return head;

        int pivot = head->val;
        ListNode tmp1(0), tmp2(0);
        ListNode *low = &tmp1, *high = &tmp2;
        for(ListNode* x = head->next; x; x=x->next)
        {
            if(x->val <= pivot){
                low->next = x;  
                low = x;
            }
            else{
                high->next = x;
                high = x;
            }
        }
        low->next = NULL;
        high->next = NULL;
        ListNode *front = quickSort(tmp1.next);
        ListNode *back = quickSort(tmp2.next);
        //弄到tail
        ListNode *q = front;
        if(q)
        {
            while(q->next)
            {
                q = q->next;
            }
            q->next = head;
        }
        head->next = back;
        if(!front)
            return head;
        else
            return front;

    }
    ListNode* sortList(ListNode* head) {
        //快排...
        if(!head)
            return nullptr;
       
        
        return quickSort(head);

    }
};