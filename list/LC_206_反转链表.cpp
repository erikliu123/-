
//递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        /* 递归示例
            1->3->5->7->9
            1->3->5->(7<-9)
            1->3->(5<-7)<-9
        */
        head->next->next = head;//一直递归到最后一对节点，才开始操作
      
        head->next = nullptr;
        return newHead;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode-solution-d1k2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。