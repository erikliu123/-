#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
/*
https://www.luogu.com.cn/problem/P1064

金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间他自己专用的很宽敞的房间。更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎么布置，
你说了算，只要不超过NN元钱就行”。今天一早金明就开始做预算，但是他想买的东西太多了，肯定会超过妈妈限定的N元。于是，他把每件物品规定了一个重要度，
分为5等：用整数1-5表示，第5等最重要。他还从因特网上查到了每件物品的价格（都是整数元）。他希望在不超过N元（可以等于N元）的前提下，
使每件物品的价格与重要度的乘积的总和最大。
*/
int f[1000010];
int g_fa[100010];
bool cmp(pair<int, int> &a, pair<int, int>&b)
{
    return a.second >b.second;
}
int main(int argc, const char *argv[])
{
    int n, m;
    cin>>m>>n;
    vector<pair<int, int>> bag;
    map<int, vector<int>>child_map;//某个主键对应的附件集合
    int minvalue = 1 << 30;
  
    int ans = 0;
    memset(f, 0, sizeof(f));
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        int value, importance, fa;
        cin>>value>>importance>>fa;
        g_fa[i] = fa-1;
        if(fa != 0){
            child_map[fa-1].push_back(i);
        }
        sum += value;
        bag.push_back(make_pair(value, importance));
       
    }
    if(m > sum) m = sum;

    for(int i=0; i<n; i++){
        if(g_fa[i] < 0){
            for(int v=m; v>=bag[i].first /*- minvalue*/; v--)
            {
                f[v] = max(f[v], f[v - bag[i].first]+bag[i].second*bag[i].first);
                if(child_map[i].size() >= 1 && v>=(bag[child_map[i][0]].first + bag[i].first)){
                    int x = child_map[i][0];
                     f[v] = max(f[v], f[v - bag[x].first - bag[i].first] + (bag[x].first*bag[x].second+bag[i].first*bag[i].second));
                }
                if(child_map[i].size() == 2 && v>=(bag[child_map[i][0]].first + bag[child_map[i][1]].first + bag[i].first)){
                    int x = child_map[i][0];
                    int y = child_map[i][1];
                     f[v] = max(f[v], f[v - bag[i].first -bag[y].first] + (bag[i].first*bag[i].second + bag[y].first*bag[y].second));
                     f[v] = max(f[v], f[v - bag[x].first - bag[i].first -bag[y].first] + (bag[x].first*bag[x].second + bag[i].first*bag[i].second + bag[y].first*bag[y].second));
                }
                
            }
        }
    }
    cout<<f[m]<<endl;

    return 0;
}