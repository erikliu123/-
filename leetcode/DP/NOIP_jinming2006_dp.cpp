#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
/*
金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间他自己专用的很宽敞的房间。更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎么布置，
你说了算，只要不超过NN元钱就行”。今天一早金明就开始做预算，但是他想买的东西太多了，肯定会超过妈妈限定的N元。于是，他把每件物品规定了一个重要度，
分为5等：用整数1-5表示，第5等最重要。他还从因特网上查到了每件物品的价格（都是整数元）。他希望在不超过N元（可以等于N元）的前提下，
使每件物品的价格与重要度的乘积的总和最大。
*/
int f[1000010];
bool cmp(pair<int, int> &a, pair<int, int>&b)
{
    return a.second >b.second;
}
int main(int argc, const char *argv[])
{
    int n, m;
    cin>>m>>n;
    vector<pair<int, int>> bag;
    int minvalue = 1 << 30;
  
    int ans = 0;
    memset(f, 0, sizeof(f));
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        int value, importance;
        cin>>value>>importance;
        sum += value;
        bag.push_back(make_pair(value, importance));
       
    }
    if(m > sum) m = sum;

    for(int i=0; i<n; i++){
        for(int v=m; v>=bag[i].first /*- minvalue*/; v--)
        {
            f[v] = max(f[v], f[v - bag[i].first]+bag[i].second*bag[i].first);
            
        }
    }
    
    cout<<f[m]<<endl;

    return 0;
}