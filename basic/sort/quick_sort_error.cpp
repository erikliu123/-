#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void quick_sort(vector<int>& nums, int lo, int high, int k)
    {
        int x = nums[lo];//ERROR: 递归之后，可能会有lo > high，这个时候会发生非法访存！！
        int low = lo, hi = high;
        if(low >= hi) return;
        while(low < hi)
        {
            while(low < hi && nums[hi]<x) --hi;
            if(low < hi) nums[low++] = nums[hi];

            while(low < hi && nums[low]>x) ++low;
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

int main()
{
    vector<int> test{99,99};
    Solution a;
    a.findKthLargest(test, 1);
    return 0;
}