#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
给你一个整数数组 arr 。

现需要从数组中取三个下标 i、j 和 k ，其中 (0 <= i < j <= k < arr.length) 。

a 和 b 定义如下：

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
注意：^ 表示 按位异或 操作。

请返回能够令 a == b 成立的三元组 (i, j , k) 的数目。


示例 1：
输入：arr = [2,3,1,6,7]
输出：4
解释：满足题意的三元组分别是 (0,1,2), (0,2,2), (2,3,4) 以及 (2,4,4)

*/
#ifdef O_N_algorithm
/*
NOTICE: 有O(n)的解法
*/
class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> cnt, total;
        int ans = 0, s = 0;
        for (int k = 0; k < n; ++k) {
            int val = arr[k];
            if (cnt.count(s ^ val)) {
                ans += cnt[s ^ val] * k - total[s ^ val];
            }
            ++cnt[s];
            total[s] += k;
            s ^= val;
        }
        return ans;
    }
};

#else
//一开始自己的解法
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> tmp(1 , 0);
        int res=0;
        for(auto &i: arr)
        {
            tmp.push_back(tmp[tmp.size()-1] ^ i);
        }
        for(int i=0; i<arr.size(); i++){
            for(int k=i+1; k<arr.size(); k++)
            {
                if((tmp[k+1] ^ tmp[i]) == 0){
                    res+=(k-i);
                    //for(int j=i+1; j<=k ; j++){
                        // int a=tmp[j] ^ tmp[i];
                        // int b=tmp[k+1] ^ tmp[j];
                    //     if(a==b) res++;
                    // }
                }
            }
        }
        return res;


    }
};
#endif
