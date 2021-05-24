#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <map>
#include <unordered_map>
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
    vector<vector<int>> ans;
    set<vector<int>> cmp;
    void bfs(vector<int>& candidates, int cursum, int target, int begin, int left, vector<int> &tmp)
    {
        if(cursum == target)
        {
            if(!cmp.count(tmp))
            {
                cmp.insert(tmp);
                ans.push_back(tmp);
            }
        }
        for(int i=begin; i<candidates.size(); i++){
            if(cursum + left < target) break; //NOTICE:如果存在负数的话，这个判断要去掉
            if(cursum + candidates[i] > target) break; //如果存在负数的话，这个判断要去掉 [-1,-1,4]
            left -= candidates[i];
            tmp.push_back(candidates[i]);
            bfs(candidates, cursum + candidates[i], target, i+1, left, tmp);
            tmp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum=0;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        for(auto &i:candidates) sum += i;
        bfs(candidates, 0, target, 0, sum, tmp);
        return ans;
        

    }
};