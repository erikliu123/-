
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<numeric>
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
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode * head;
#ifdef MAP    
    map<int,  ListNode *> map_list;
#endif
    int len;
    Solution(ListNode* head):head(head){
        len = 0;
        for(auto p = head; p; p = p->next)
        {
#ifdef MAP   
            map_list[len] = p;
#endif
            len ++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int x=rand()%len;
#ifdef MAP           
        return map_list[x]->val;
#else        
        auto p = head;
        while(x--)
        {
            p = p->next;            

        }
        return p->val;
#endif        

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */