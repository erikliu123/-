#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <numeric>
using namespace std;


class Solution {
public:
    vector<int> weight;
    vector<int> sums;
    int sum;
    Solution(vector<int>& w) : weight(std::move(w)){
        sums = weight;
        partial_sum(sums.begin(), sums.end(), sums.begin());
        sum = 0;
        for(auto &i:weight) {
            sum += i;
            i = sum;
        }


    }
    
    int pickIndex() {
#ifdef SIMPLE
        int x=rand()%(sums[sums.size()-1]) + 1;
        return lower_bound(sums().begin(), sums.end(), x) - sums.begin();

#elif defined(FIRST_UP_EQUAL)
        int x=rand()%sum;
        //找到数组中第一个大于x的下标
        int left = 0, right=weight.size();
        while(left<right)
        {
            int mid = (left + right)/2;
            if(weight[mid] > x) right = mid; //保持a[right] > x
            else left = mid+1;

        }
#else
        int x=rand()%sum + 1;
        //找到数组中第一个大于等于x的下标
        int left = 0, right=weight.size();
        while(left<right)
        {
            int mid = (left + right)/2;
            if(weight[mid] >= x)  right = mid;
            else left = mid + 1;//保持a[right] >= x

        }
        return left;
#endif


    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main()
{
    vector<int> test{1,3,4,5};
    Solution a(test);
    a.pickIndex();
    return 0;
}