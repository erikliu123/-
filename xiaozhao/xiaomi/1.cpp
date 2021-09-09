#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//1A2C3D4E56 A1B2345C6D

int main(){
    string aStr, bStr;
    cin>>aStr>>bStr;
    int m = aStr.size(), n = bStr.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(aStr[i] != bStr[j])
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);

            else{
                 dp[i+1][j+1] = max(dp[i][j]+1, (max(dp[i][j+1], dp[i+1][j])));
            }
        }

    }
    cout<<dp[m][n]<<endl;
    return 0;
}