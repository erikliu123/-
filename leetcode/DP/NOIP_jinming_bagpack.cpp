#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
/*
https://www.luogu.com.cn/problem/P3985

金明今天很不开心，家里购置的二手房就要领钥匙了，房里并没有一间他自己专用的很宽敞的房间。更让他不高兴的是，妈妈昨天对他说：“你需要购买
哪些物品，怎么布置，你说了不算（有很大的限制），而且不超过W元钱。”。今天一早金明就开始做预算，但是他想买的东西太多了，肯定会超过妈妈
限定的W元。于是，他把每件物品规定了一个重要度整数p_ip 

输入格式
输入的第1行，为两个正整数，用一个空格隔开：

n W （其中W表示总钱数，n为希望购买物品的个数。）

从第2行到第n+1行，第j行给出了编号为j-1的物品的基本数据，每行有2个非负整数v p （其中v表示该物品的价格，p表示该物品的重要度）

输出格式
输出只有一个正整数，为不超过总钱数的物品的重要度的总和的最大值
*/
int f[1000010];
bool cmp(pair<int, int> &a, pair<int, int>&b)
{
    return a.second >b.second;
}
int main(int argc, const char *argv[])
{
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> bag;
    int minvalue = 1 << 30;
  
    int ans = 0;
    memset(f, 0, sizeof(f));
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        int value, importance;
        cin>>value>>importance;
        if(minvalue > value){
            minvalue = value;
        }
        sum += value;
        bag.push_back(make_pair(value, importance));
       
    }
    if(m > sum) m = sum;
    if(m/minvalue == m/(minvalue+3)){//NOTICE：贪心算法，数学上需要思考为什么可以
        //选最大的
        int index = 0;
        sort(bag.begin(), bag.end(), cmp);
        for(int x=(m/minvalue); x>0 && index<bag.size(); x--)
        {
            ans += bag[index++].second;

        }
        cout << ans<< endl;
        return 0;


    }
    else{
        for(int i=0; i<n; i++){
            for(int v=m; v>=bag[i].first /*- minvalue*/; v--)
            {
                f[v] = max(f[v], f[v - bag[i].first]+bag[i].second);
                
            }
        }
    }
    cout<<f[m]<<endl;

    return 0;
}