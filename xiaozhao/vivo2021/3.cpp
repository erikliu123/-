/*
vivo游戏中心的运营小伙伴最近接到一款新游戏的上架申请，为了保障用户体验，运营同学将按运营流程和规范对其做出分析评估。经过初步了解后分析得知，
该游戏的地图可以用一个大小为 n*n 的矩阵表示，每个元素可以视为一个格子，根据游戏剧情设定其中某些格子是不可达的(比如建筑、高山、河流或者其它障碍物
等)，现在请你设计一种算法寻找从起点出发到达终点的最优抵达路径，以协助运营小伙伴评估该游戏的可玩性和上手难度。

输入描述:
第一行表示矩阵大小 n，5 <n < 10000
第二行表示起点和终点的坐标
第三行起是一个用矩阵表示的游戏地图，其中#或者@表示障碍物，其他字母、非0数字、以及符号+、-、* 等等均表示普通可达格子，共有 n 行  n 列 

输出描述:
输出最优路径的长度；若无法到达，则输出-1

输入例子1:
15
0 7 7 7
*5#++B+B+++++$3
55#+++++++###$$
###$++++++#+*#+
++$@$+++$$$3+#+
+++$$+++$+4###+
A++++###$@+$++A
+++++#++$#$$+++
A++++#+5+#+++++
+++$$#$++#++++A
+++$+@$###+++++
+###4+$+++$$+++
+#+3$$$+++$##++
+#*+#++++++#$$+
$####+++++++$##
3$+++B++B++++#5

输出例子1:
13
*/

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

int main()
{
    int n;
    vector<string> grid;
    vector<vector<bool>> visited;
    cin>>n;
    visited =  vector<vector<bool>>(n, vector<bool>(n, false));
    pair<int, int> src, dst;
    //cin>>src.first>>src.second>>dst.first>>dst.second;
    cin>>src.second>>src.first>>dst.second>>dst.first;
    for(int i=0; i<n; i++)
    {
        string tmp;
        cin>>tmp;
        grid.push_back(tmp);
    }
    queue<pair<int, int>> bfs;
    bfs.push(src);
    visited[src.first][src.second] = true;
    int depth = 0;
    vector<int> direct{-1,0,1,0,-1};
    while(!bfs.empty())
    {
        int len = bfs.size();
        for(int i=0; i<len ; i++)
        {
            pair<int, int> pos = bfs.front(), next;
            bfs.pop();
            if(pos == dst){
                cout<<depth<<endl;
                return 0;
            }
            for(int k=0; k<4; k++)
            {
                next.first = pos.first + direct[k];
                next.second = pos.second + direct[k+1];
                if(next.first>=0 && next.first<n && next.second>=0 && next.second<n && !visited[next.first][next.second] 
                    && grid[next.first][next.second]!='#' && grid[next.first][next.second]!='@')
                {
                    visited[next.first][next.second] = true;
                    bfs.push(next);
                }
            } 
        }

        ++depth;
    }
    cout<<-1<<endl;
    return 0;
    

}