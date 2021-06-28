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


int main()
{
    priority_queue<int, vector<int>, greater<int>> s;
    priority_queue<int> default_queue;
    s.push(1);
    s.push(2);
    
    cout<<s.top()<<endl;
    cout<<endl;
    return 0;

}