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


输入
前面每一行表示2个景点的路线和距离,格式如[1,2,15].表示景点1到景点2可通,距离为15。
倒数第2行为景点总数N,
倒数第1行为S表示出发点。说明:
1、动物园不大,景点数范围为:1<N<100，两个景点间的距离范围为:[0,100]
2、两两景点间的路线总条数范围为:[1,5000]

*/

map<int, int> edge[101];//每一个顶点对应的[对策顶点, 长度]
int ans;
int max_distance[110][110];
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
             max_distance[begin][end] = 1; 
             max_distance[end][begin] = 1; 
        }
        else{
            n = stoi(str);
            break;
        }
    }
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            if(max_distance[k][i]!=1)
            {
                if(i!=k)
                    max_distance[k][i] = -1;
            }
            //max_distance[k][i] = max_distance[k][i]
        }
    }

    int start;
    cin >>start;
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(max_distance[i][k]>=0 && max_distance[k][j]>=0)
                    max_distance[i][j] = max(max_distance[i][j], max_distance[i][k] + max_distance[k][j]);
            }
        }

    }

    

    
    return 0;
}