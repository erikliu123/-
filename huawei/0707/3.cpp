#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;
/*
科科最近在学习中国象棋，今日的目标是钻研马走日。给定张棋盘，棋盘上的棋子有三种类型，马的起始位置，马要到达的目标位置和其他
的棋子。
其他的棋子可能会限制马的前进路线，限制条件如下:
1.马走日的路径上不能被绊马脚:
2.马不能到达有棋子的位置。
可是科科是个象棋新手， 请你帮他计算出达到目标位置至少要走多少步，如果不能到达输出-1。
马每次跳跃最多可以有八个方向，但是如果前进方向有棋子，则会被绊马脚。

例如下图，马的上方有棋子，则红色图形的点于能到达，五角星的位置是马可以达到的位置。
输入
棋盘宽度w (1<=w<=150)，棋盘高度h(1<=h<=150)
棋局，二维数组char[wl]lh]
其中，表示没有棋子，#表示有棋子，H表示马当前位置，T表示马要到
达的位置
输出
输出一一个整教，代表马从H到达T最少需要的步数。没有路径则输出-1。
样例1
复制输入:
5 13
........H...#
........#....
....#........
.#...........
..........T#.
复制输出:
4

*/

char chess[160][160];
int visited[160][160];
int main()
{
    int n,m;
    cin>>n>>m;
    pair<int, int> start, end;
    vector<int> direct{-1,2,1,2,-1,-2,1,-2,-1};
    for(int i=0; i<n; i++)
    {
        scanf("%s", chess[i]);
        int len = strlen(chess[i]);
        for(int j=0; j<len; j++)
        {
            if(chess[i][j] == 'H')
            {
                start = make_pair(i,j);
            }
            else if(chess[i][j] == 'T')
            {
                end = make_pair(i,j);
            }

        }

    }
    queue<pair<int, int>> q;
   
    int ans = 0;
    if(start == end) {//入队之前先判断是不是和终点相等
        cout<<0<<endl;
        return 0;
    }
    q.push(start);
    visited[start.first][start.second] = true;
    while(!q.empty())
    {
        int qsize = q.size();
        ++ans;
        for(int i=0; i<qsize; i++)
        {
            auto it = q.front();
            
            q.pop();
            //next step
            for(int k=0; k<8; ++k)
            {
                pair<int, int> next = {it.first + direct[k], it.second + direct[k+1]};
                pair<int, int> obstable ;
                if(next.first <0 || next.first>=n || next.second<0 || next.second>=m || chess[next.first][next.second] =='#') continue;
                if(abs(direct[k]) == 2)
                {
                    obstable = {it.first + ((direct[k]>0)?1:-1), it.second};
                }
                else{
                    obstable = {it.first, it.second+((direct[k+1]>0)?1:-1)};

                }
                if(chess[obstable.first][obstable.second] != '#')
                {
                    if(chess[next.first][next.second] == 'T')
                    {
                         cout<<ans<<endl;
                        return 0;
                    }
                    if(!visited[next.first][next.second])
                    {
                        visited[next.first][next.second] = true;
                        q.push(next);

                    }
                   
                    
                }
                
            }

        }
    }

    cout<<-1<<endl;
    return 0;

}