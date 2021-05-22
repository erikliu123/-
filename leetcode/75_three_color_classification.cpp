#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int p0=0, p2=nums.size()-1;
        /*NOTICE: 和快排不一样，快排必须需要有一个中枢；如果用1作为中枢，可能会有问题，因为数组中不一定存在1 */
        for(int i=0; i<=p2; i++)//不能是i<nums.size()
        {
            while (i <= p2 && nums[i] == 2) {//为了应对[2,1,2]的情况！,必须要while循环
                swap(nums[i], nums[p2]);
                --p2;
            }

            if(nums[i] == 0){
                swap(nums[i], nums[p0]);
                p0++;
            }
        }
        return ;
        /*常规思路*/
        vector<int> cnt(3, 0);
        for(auto &i:nums) cnt[i]++;

        nums.clear();
        for(int i=0; i<cnt.size(); i++)
            nums.insert(nums.end(), cnt[i], i);

    }
};