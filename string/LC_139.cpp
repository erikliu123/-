#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
题目描述:
给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。


"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
*/
#define DP_SOLUTION
class Solution {
public:
    unordered_set<string> str;
    bool ans;
    vector<bool> dp;
    bool dfs(string s, int begin, int end)
    {
        if(begin >= end) return true;
       
        for(int i=begin; i<end; i++)
        {
            int ret = false;
            if(str.count(s.substr(begin, i-begin+1)))
            {
               
                if(!dp[i]) {//NOTICE:必须剪枝操作
                    dp[i]=true;
                    ret=dfs(s, i+1, end);
                }
                if(ret) {
                    ans = true;
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        dp=vector<bool>(s.size()+1, false);
        for(auto &i:wordDict){
            str.insert(i);
        }
        
#ifdef DP_SOLUTION
         /*动归*/     
         dp[0]=true;
        for(int i=0; i<s.size(); i++){
            for(int k=0; k<=i && !dp[i+1]; k++){
                if(dp[k] && str.count(s.substr(k, i-k+1))){
                    dp[i+1]=true;
                }
            }

        }
        return dp[s.size()];
       
#else
         /*暴力搜索+剪枝*/
        ans=false;
        dfs(s, 0, s.size());
        return ans;
#endif
    
    }

        
};