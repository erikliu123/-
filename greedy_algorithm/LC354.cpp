#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

注意：不允许旋转信封。

 
示例 1：

输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出：3
解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
*/
//[[2,100],[3,200],[4,300],[5,500],[5,400],[5,250],[6,370],[6,360],[7,380]]
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) 
        {
            if(a[0] != b[0])
                return a[0] < b[0];
            else
                return a[1] > b[1];
        });//必须从大到小
        int n = envelopes.size();
        int ans = 0;
        vector<int> dp(1, envelopes[0][1]);
        //dp[i] 表示仅使用信封 [0, i](这里是区间的意思，表示前 i+1 个信封)，且以第 i 个信封为顶端信封时的最大高度。
        for(int i=1; i<n; i++)//从大件开始遍历
        {
            if(envelopes[i][1] > dp.back())
            {
                dp.push_back(envelopes[i][1]);
            }
            else{
                auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
            
        }
        
    
        return dp.size();
    }
};

int main()
{
    vector<vector<int>> test{
        {2,3},
        {6,7},
        {4,4},
        {6,4}
    };
    vector<vector<int>> test2{
        {2,100},//pick
        {3,200},//pick
        {4,300},//pick
        {5,500},
        {5,400},
        {5,250},//pick, 问题核心，它此时不能囊括2~3的内容
        {6,370},
        {6,360},//pick 
        {7,380}//pick
    };//
    Solution a;
    a.maxEnvelopes(test2);
    return 0;
}