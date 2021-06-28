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
//#define DP_SOLUTION
class Solution {
public:
    unordered_set<string> str;
    bool ans;
    vector<string> ret;
    bool bfs(string &s, int begin, int end, vector<int> &tmp)
    {
        if(begin >= end) {
            string st=s;
            int space=0;
            for(int i=tmp.size()-1; i>=0; i--)
            {
                if(tmp[i]<s.size()){
                    st.insert(st.begin()+tmp[i]+space, ' ');
                    //space++;
                }

            }
            ret.push_back(st);
            return true;
        }
       
        for(int i=begin; i<end; i++)
        {
            int ret = false;
            if(str.count(s.substr(begin, i-begin+1)))
            {
                tmp.push_back(i+1);
                bfs(s, i+1, end, tmp);
                tmp.pop_back();
                
            }
        }
        return false;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(s.size()+1, false));
        for(auto &i:wordDict){
            str.insert(i);
        }
        
#ifdef DP_SOLUTION
         /*动归*/   
        bool find=false;
        for(int i=0; i<s.size()+1; i++) {
            //dp[i][0]=true;
            dp[0][i]=true;
        }

        for(int i=0; i<s.size(); i++){
            for(int k=0; k<=i; k++){
                if(dp[i][k] && str.count(s.substr(k, i-k+1))){
                    dp[i+1][k]=true;
                    if(i==s.size()-1){
                        find = true;
                    }
                }
            }
        }
        if(find)
        {
             vector<int> mid;
            bfs(dp, s.size(), s, mid);
        }

        return ret;
        //return dp[s.size()];
       
#else
         /*暴力搜索+剪枝*/
        ans=false;
        vector<int> mid;
        bfs(s, 0, s.size(), mid);
        return ret;
#endif
    
    }

        
};



int main()
{
    Solution a;
    vector<string> vec{"cat", "cats", "ans", "sand", "dog"};
    string test_str="catsanddog";
//     "catsanddog"
// ["cat","cats","and","sand","dog"]
    a.wordBreak(test_str, vec);
    return 0;
}