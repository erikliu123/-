#include <iostream>
#include <vector>

using namespace std;
/*
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
提示：a + b 意味着字符串 a 和 b 连接。

*/

//暴力搜索在递归深度较深时，必须考虑剪枝！！！！！
class Solution {
public:
    bool find;
    vector<vector<int>>dp;
    /*
    "abababababababababababababababababababababababababababababababababababababababababababababababababbb"
"babababababababababababababababababababababababababababababababababababababababababababababababaaaba"
"abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbb"
    */
    /*
    "aabcc"
    "dbbca"
    "aadbbbaccc"
    */
    bool dfs(string &s1, string &s2, string &s3, int start1, int start2)
    {
        bool flag1 = false, flag2=false;
        if(find) return true;
        if(dp[start1][start2] != -1) return dp[start1][start2] ;
        if(start1 == s1.size() && start2==s2.size()) {
            find =true;
            return true;
        }
        
        //  if(start1 == s1.size()) //加了后不一定更快，substr构造也需要时间
        //  {
        //      return s3.substr(start2+start1) == s2.substr(start2);
        //  } 
        //   if(start2 == s2.size())
        //  {
        //      return s3.substr(start2+start1) == s1.substr(start1);
        //  } 
        if(start1 < s1.size())
        {
            if(s3[start1 + start2] == s1[start1]){
                 //dp[start1][start2+1] = 1;
                flag1 = dfs(s1, s2, s3, start1+1, start2);
            }

        }
        if(start2 < s2.size())
        {
             if(s3[start1 + start2] == s2[start2]){
                  //dp[start1][start2+1] = 1;
                 flag2 = dfs(s1, s2, s3, start1, start2+1);
             }
        }
        dp[start1][start2] = flag1 | flag2;
        return dp[start1][start2];


    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<int> cnt1(26, 0),cnt2(26, 0);//cnt3(26, 0);
        if(s1.size() + s2.size() != s3.size()) return false;
        for(auto &i : s1)
            cnt1[i-'a']++;
        for(auto &i : s2)
            cnt1[i-'a']++;
        for(auto &i : s3)
            cnt2[i-'a']++;
        dp=vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1, -1));
        for(int i=0; i<26; i++){
            if(cnt1[i]!=cnt2[i])
            {
               // cout<<"unmatched in alphabets!!!"<<endl;
                return false;
            }
        }
        // if(s1.size() > 60){
        //     reverse(s1.begin(), s1.end());
        //      reverse(s2.begin(), s2.end());
        //       reverse(s3.begin(), s3.end());
        // }
        return dfs(s1, s2, s3, 0, 0);

    }
};