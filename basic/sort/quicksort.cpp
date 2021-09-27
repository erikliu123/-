#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//剑指 Offer II 076. 数组中的第 k 大的数字
//https://leetcode-cn.com/problems/xx4gT2/
class Solution {
public:
    void quick_sort(vector<int>& nums, int lo, int high, int k)
    {
        
        int low = lo, hi = high;
        if(low >= hi) return;
        if(nums[lo] < nums[high]) swap(nums[lo], nums[high]);//避免最极端的情况
        int x = nums[lo];//注意访问位置！
        while(low < hi)
        {
            while(low < hi && nums[hi]<=x) --hi; //NOTICE 也可以nums[hi]<x, [99,99]
            if(low < hi) nums[low++] = nums[hi];

            while(low < hi && nums[low]>=x) ++low;
            if(low < hi) {
                nums[hi--] = nums[low];
                //--hi;
            }


        }
        nums[low] = x;
        if(low == k) return;
        quick_sort(nums, lo, low-1, k);
        quick_sort(nums, low+1, high, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        //sort(nums.begin(), nums.end());
        //return nums[nums.size()-k];
        quick_sort(nums, 0, nums.size()-1, k-1);
        // for(auto x:nums)
        //     cout<<x<<" ";
        return nums[k-1];

    }
};