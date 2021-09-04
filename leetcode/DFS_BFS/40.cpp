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
    int mTarget;
    void dfs(vector<int>& candidates, int begin, int cursum, int left, vector<int> &tmp)
    {
        if(cursum + left < mTarget )
            return;
       
        if(cursum == mTarget)
        {
            mSet.insert(tmp);
            return;
        }
      
        for(int i=begin; i<candidates.size(); i++)
        {
            if(cursum + left  < mTarget || cursum + candidates[i] > mTarget)
                break;
            tmp.push_back(candidates[i]);
            left -= candidates[i];
            dfs(candidates, i+1, cursum + candidates[i], left, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        mSet.clear();
        mTarget = target;
        sort(candidates.begin(), candidates.end());
        int sum = accumulate(candidates.begin(), candidates.end(), 0);
        vector<int> temp;
        dfs(candidates, 0, 0, sum, temp);
        
        //return result
        vector<vector<int>> mAns;
        for(auto x: mSet)
        mAns.push_back(x);
        return mAns;
    }
};