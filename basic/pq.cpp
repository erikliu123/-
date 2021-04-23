#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
/*
题目描述：
给定两个以升序排列的整形数组 nums1 和 nums2, 以及一个整数 k。
定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2。

找到和最小的 k 对数字 (u1,v1), (u2,v2) ... (uk,vk)。
*/


static bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.first+a.second < b.first+b.second;
}
struct Node{
    int x, y;
    Node( int a= 0, int b= 0 ):
        x(a), y(b) {}
    bool operator<(const Node &b) const{
        return x+y<b.x+b.y;
    }
    bool operator>(const Node &b) const{
        return x+y>b.x+b.y;
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        priority_queue<Node , vector<Node> , greater<Node>> pq;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int index1=0, index2=0;
        while(k){
            if(index2>=nums2.size() || index1>=nums1.size()) {
                if(pq.size()==0) break;
            }
            else if(index2>=nums2.size() || nums1[index1] < nums2[index2]){
                for(int i=index2; i<nums2.size(); i++){
                    pq.push(Node(nums1[index1], nums2[i]));
                }
                ++index1;
            }
            else{
                for(int i=index1; i<nums1.size(); i++){
                    pq.push(Node(nums1[i], nums2[index2]));
                }
                ++index2;
            }
            Node s=pq.top();
            pq.pop();
            --k;
            vector<int> temp{s.x, s.y};
            ans.push_back(temp);
        }
        return ans;

    }
};

int main()
{
    Solution a;
    vector<int> nums1{1,2,3,4,5}, nums2{2,4,6,7,12};
    vector<vector<int>> ans=a.kSmallestPairs(nums1, nums2, 5);
    for(auto it:ans){
        cout<<it[0]<< ","<<it[1]<<" ";
    }
    cout<<endl;

}