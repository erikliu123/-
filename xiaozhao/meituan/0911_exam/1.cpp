#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/*
小美最近迷上了22这个数字，一天，她发现他的一本书中有一个神秘的大数字。
于是她想知道这个数字中有多少子串代表的数字能被22整除。
*/

int main(){
    string str;
    cin>>str;
    int ans = 0;
    //被22整除的判断，字符串相同且是偶数
    //1562,
    //奇数位 - 偶数相减 % 11 = 0
  
    vector<bool> visit(str.size(), false);
    vector<int> dp(str.size(), 0);
  	bool first = false;
    int startIndex = 0;
    for(int i=1; i<str.size(); i++)
    {
        int num = str[i] - '0';
        if(visit[i-1] && num == 0)
        {
            dp[i] = dp [i-1];//这个地方应该是dp[i-1]+1?
            visit[i] = true;
            continue;
        }
        if(num%2 == 0)
        {
            //判断奇数偶数位数之差 
              //int start_odd = 0, start_even = 1;
            int odd = num;//even = 0;
            bool nega = false;
            for(int k=i-1; k>=0; k--)
            {
                nega = !nega;
                if(k<startIndex && visit[k])
                    break;
                if(nega)
                    odd -= (str[k] - '0');
                else
                    odd += (str[k] - '0');
                if(abs(odd) % 11 == 0 && str[k]!='0')
                {
                    dp[i]++;
                    visit[i] = true;
                    if(!first)
                        {
                            startIndex = i;
                            first = true;
                        }
                }
            }

        }

    }
    
    for(auto x:dp)
    {
        ans += x;
    }
    cout<<ans<<endl;
    return 0;


}