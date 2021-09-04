#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    
    set<vector<int>> mSet;
    vector<pair<int, int>> mNumCnt;

    int mTarget;
    void dfs(int begin, int cursum, vector<int> &tmp)
    {
       
        if(cursum == mTarget)
        {
            mSet.insert(tmp);
            return;
        }
        if(begin >= mNumCnt.size())
            return ;
        
        int most = min((mTarget - cursum) / mNumCnt[begin].first, mNumCnt[begin].second);
        //dfs(candidates, begin+1, cursum, tmp);
        for(int i=0; i<=most; i++)//可以加入 [0, most]个元素
        {
            dfs(begin+1, cursum + i * mNumCnt[begin].first, tmp);
            if(i!=most)
                tmp.push_back(mNumCnt[begin].first);
        }

        for(int i=1; i<=most; i++)
            tmp.pop_back();

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        mSet.clear();
        mNumCnt.clear();

        mTarget = target;
        sort(candidates.begin(), candidates.end());
        for(auto x:candidates)
        {
            if(mNumCnt.empty() || mNumCnt.back().first != x)
            {
                mNumCnt.push_back(make_pair(x, 1));
            }
            else{
                mNumCnt.back().second++;
            }
        }
        vector<int> temp;
        dfs(0, 0, temp);
        
        //return result
        vector<vector<int>> mAns;
        for(auto x: mSet)
        mAns.push_back(x);
        return mAns;
    }
};