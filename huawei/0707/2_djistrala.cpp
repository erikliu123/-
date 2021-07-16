#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
/*
由于疫情影响,动物园进行人流管控,减少人员接触,因此从入口处进入之后，只能选择某一条路单向进行，比如:老虎园的编码为1，
狮子园的编码为2,猴子园的编码为3，天鹅园的编号为4，而从一个地方到另一个地方有一定的距离，则用以下结构表示:老虎园到狮子园,
[1,2,15],狮子园到猴子园，[2,3,7],猴子园到天鹅园,[3,4,9],现在随机给定一个暴点(S作为出发点,判断是否有可能逛完所有累点(N个)。
若不能狂完返回-1,若可以逛完,则返回最长距离。

解答要求
时间限制:C/C++ 1000ms,其语言:2000ms
内存限制C/C++ 256MB.其他语言:512MB

输入
前面每一行表示2个景点的路线和距离,格式如[1,2,15].表示景点1到景点2可通,距离为15。
倒数第2行为景点总数N,
倒数第1行为S表示出发点。说明:
1、动物园不大,景点数范围为:1<N<100，两个景点间的距离范围为:[0,100]
2、两两景点间的路线总条数范围为:[1,5000]

*/
//NOTICE； 求图的最大深度，感觉这种方法不可

map<int, int> edge[101];
int visited[110];
int g_maxpath[110];
int ans=0;
int floyd[110][110];
bool mark[110];
priority_queue<pair<int, int>, vector<pair<int, int>>> pq;//长度，点

int main()
{
    int n;
    ans = -1;
    while (1)
    {
        string str;
        int begin ,end, distance;
        cin>>str;
        if(str[0] == '['){
            sscanf(str.c_str(), "[%d,%d,%d]", &begin, &end, &distance);
            if(!edge[begin].count(end))
            {
                edge[begin][end] = distance;
            }
            else if(edge[begin][end] < distance){
                edge[begin][end] = distance;
            }
        }
        else{
            n = stoi(str);
            break;
        }
    }
    
    int start;
    cin >>start;

    //mark[start] = true;
    
    int valid_points= 1;
    int next = start;
    pq.push(make_pair(1, start));
    g_maxpath[start] = 1;
    while(!pq.empty())
    {
        //找到
        auto it = pq.top();
        pq.pop();
        mark[it.second] = true;
        g_maxpath[it.second] = it.first;
        for(auto &x:edge[it.second])//遍历这个点对应的出度边，
        {
            int dist = g_maxpath[it.second] + 1;
            if(dist > g_maxpath[x.first]){//不管这个x.first有没有被mark过，都要更新
                 g_maxpath[x.first] = dist;    
            }
            if(!mark[x.first])
            {
                pq.push(make_pair(dist, x.first));
            }
        }
    }
    int find = 0;
    for(int i=1; i<=n; i++)
    {
        if(g_maxpath[i] == n)
        {
            find = 1;
            break;
        }
    }
    if(!find)
        cout<<-1<<endl;
    else{
        //迪杰斯特拉应该是错误的想法，不再处理。。。

    }
    
    
    return 0;
}