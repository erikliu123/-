
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string patternStr, matchStr;
    cin >> patternStr >> matchStr;

    int n = matchStr.size(), m = patternStr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && patternStr[j] == '?' || (i > 0 && matchStr[i - 1] == patternStr[j]))
            {
                dp[i][j + 1] = dp[i - 1][j];
            }
            else if (patternStr[j] == '#')
            {
                if (i > 0)
                    dp[i][j + 1] = dp[i - 1][j] || dp[i][j]; //用->dp[i-1][j]  或者  不用->dp[i][j];
                else
                    dp[i][j + 1] = dp[i][j];
            }
            else if (patternStr[j] == '*')
            {

                if (i > 0)
                {
                    dp[i][j + 1] = dp[i - 1][j + 1];
                }

                if (j > 0)
                    dp[i][j + 1] = dp[i][j + 1] || dp[i][j];
            }
            else
                dp[i][j + 1] = false;
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
