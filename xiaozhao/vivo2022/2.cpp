#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    int volume;
    vector<int> dp;
    vector<int> value;
    vector<int> cost;
    string str;
    cin>>volume;
    dp = vector<int>(volume+1 , 0);
    
    cin>>str;
    int num = 0;
    for(int i =0; i<str.size(); i++)
    {
        if(str[i] == ','){
            cost.push_back(num);
            num =  0;
        }
        else{
            num = num*10 + str[i]-'0';
        }
    }
    cost.push_back(num);
    cin>>str;
    num = 0;
    for(int i =0; i<str.size(); i++)
    {
        if(str[i] == ','){
            value.push_back(num);
            num =  0;
        }
        else{
            num = num*10 + str[i]-'0';
        }
    }
    value.push_back(num);
    int n = value.size();
    for(int i =0; i<n; i++)
    {
        for(int v=volume; v>=cost[i]; --v){
            dp[v] = max(dp[v], dp[v-cost[i]] + value[i]);
        }
    }
    cout<<dp[volume]<<endl;
    
    return 0;
}