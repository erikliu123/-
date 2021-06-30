#include <iostream>
#include <vector>
using namespace std;
/*
"aab"
"c*a*b"

"mississippi"
"mis*is*p*."
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
       
        for(int i=0; i<s.size(); i++)//错误解法: dp[2][0]无法变成true!!
        {
            for(int j=0; j<p.size(); j++){
                 
                if(p[j] == '.' || (s[i]==p[j])) //&&(j+1<p.size() && p[j+1]!='*') || j+1>=p.size()))
                {
                    dp[i+1][j+1] = dp[i][j];
                }
                else if(p[j] == '*')
                {
                    dp[i+1][j+1] = dp[i+1][j];
                    if(j>0 && (p[j-1]==s[i] || p[j-1]=='.'))
                        dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j+1] || dp[i][j-1];
                    else{
                        dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j-1];

                    }
                }
                else{
                    dp[i+1][j+1] = false;
                }
            }
        }
        return dp[s.size()][p.size()];


    }
};

int main()
{
    Solution a;
    string test_str="mississippi";
    string test_pattern=".*";//"mis*is*ip*i";
    test_str="aab";
    test_pattern="c*a*b";
    a.isMatch(test_str, test_pattern);
    return 0;
}