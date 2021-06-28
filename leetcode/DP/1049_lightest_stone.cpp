#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
/*
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

示例 1：

输入：stones = [2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
示例 2：

输入：stones = [31,26,33,21,40]
输出：5

*/
class Solution {
public:
    int ans;
    //void dfs(vector<int>& stones, int begin,)
    int lastStoneWeightII(vector<int>& stones) {
        
        int sum = 0;
        for(auto &x: stones) sum+=x;
        vector<int> dp(sum/2+1, 0);
        for(int i=0; i<stones.size(); i++)
        {
            for(int v=sum/2; v>=stones[i]; v--)
            {
                dp[v]=max(dp[v], dp[v-stones[i]]+stones[i]);
            }
        }        
        return abs(sum-2*dp[sum/2]);


        /* 错误想法，通过了55 / 86 个通过测试用例  */
        //选最小的，再选最大和次小的
        //[1,1,2,3,5,8,13,21,34,55,89,14,23,37,61,98] 的结果应该是1，按照这种方法得到的是17
        while(stones.size() > 2)
        {
            int x = stones.size() - 1;
            sort(stones.begin(), stones.end());
            // if(stones[x] == stones[x-1]){
            //      stones.pop_back();
            //      stones.pop_back();
            //      continue;
            // }
            stones[1] = stones[x] -  stones[1];
            stones.pop_back();
            
        }
        if(stones.size() == 2) return abs(stones[0]-stones[1]);
        return stones[0];

        // priority_queue<int> pq;
        // int ans = 0;
        // for(auto &i:stones){
        //     pq.push(i);
        // }
        // while(pq.size() > 1)
        // {
        //     int x=pq.top();
        //     pq.pop();
        //     int y=pq.top();
        //     pq.pop();
        //     cout<<x<<"\t"<<y<<endl;
        //     pq.push(x-y);

        // }
        // if(pq.size() > 0) ans = pq.top();
        // return ans;

    }
};