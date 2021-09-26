
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;
/*
小美最近迷上了22这个数字，一天，她发现他的一本书中有一个神秘的大数字。
于是她想知道这个数字中有多少子串代表的数字能被22整除。
*/

//和LC523类似
int main(){
    string str;
    cin>>str;
    int ans = 0;

    unordered_map<int, int> mHash;
    mHash[0] = 1;
    //int sum = 0;//必须要从第二位才开始算，否则12会被误判！
    //for(auto x:str)
    int sum = str[0] - '0';
    for(int i=1; i<str.size(); i++)//NOTICE:从下标1开始
    {
        auto x =str[i];
        
        sum = (sum*10 + x-'0')%11;
        if(mHash.count(sum) && ((x-'0') & 0x1) == 0)
        {
            cout<<x<<"\t"<<mHash[sum]<<endl;
            ans+=mHash[sum];
        }
        mHash[sum]++;
    }
    cout<<ans<<endl;
    return 0;

}