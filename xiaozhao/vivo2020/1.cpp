
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 实现方案
     * @param m int整型 最少m个键
     * @param n int整型 最多n个键
     * @return int整型
     */
    int result;
    vector<vector<bool>> visited;
    void dfs(pair<int, int> start, int steps, int m, int n)
    {
        if(steps >=m && steps <=n){
            ++result;
        }
        if(steps == n || steps > 9) return;
        visited[start.first][start.second] = true;
        for(int k=0; k<3; k++)
        {
            for(int j=0; j<3; j++)
            {
                if(!visited[k][j]){
                    //括号一定不要偷懒！！
                    if(((k==start.first && abs(j-start.second)==2) || (j==start.second && abs(k-start.first)==2)) 
                                && !visited[(k+start.first)/2][(j+start.second)/2]){
                        continue;
                    }
                    else if(abs(k-start.first)==2 && abs(j-start.second)==2 &&  !visited[(k+start.first)/2][(j+start.second)/2]){
                        continue;
                    }
                    //visited[k][j] = true;
                    dfs(make_pair(k,j), steps+1, m, n);
                    //visited[k][j] = false;

                }
            }
        }
       visited[start.first][start.second] = false;

    }
    int solution(int m, int n) {
        // write code here
        queue<pair<int, int>> bfs;
        
        int ans = 0;
        //中间开始的
        int ways = 0;
        bfs.push(make_pair(0, 0));
        visited = vector<vector<bool>>(3, vector<bool>(3, false));
        visited[0][0] = true; 
        vector<int> direct{1, 0, -1, 0, 1};
        int depth = 1;
        result = 0;
        dfs(make_pair(0,0), 1, m ,n);
        ans += result *4;
        result = 0;
        dfs(make_pair(0,1), 1, m ,n);
        ans += result *4;
        result = 0;
        dfs(make_pair(1,1), 1, m ,n);
        ans += result;
        return ans;

        // while(!bfs.empty())
        // {
        //     int len=bfs.size();
        //     for(int i=0; i<len; i++)
        //     {
        //         auto pos = bfs.front(), next = pos;
        //         bfs.pop();
        //          for(int k=0; k<3; k++)
        //          {
        //             for(int j=0; j<3; j++)
        //             {
        //                 if(!visited[k][j]){
        //                     if((k==pos.first && abs(j-pos.second)==2) || (j==pos.second && abs(k-pos.first)==2)){

        //                     }
        //                     visited[k][j] = true;

        //                 }
        //             }
        //          }
        //         // for(int k = 0; k<4; k++)
        //         // {
        //         //     next.first = pos.first + direct[k];
        //         //     next.second = pos.second + direct[k+1];
        //         //     if(next.)
        //         // }

        //     }
        //     ++depth;
        //     if(depth > )

        // }

        // ways = 0;
        // bfs.push(make_pair(0, 1));

        // ways = 0;
        // bfs.push(make_pair(1, 1)); 
    }
};

int main()
{

    Solution a;
    //a.solution(1,2);
    a.solution(3,3);
    return  0;
}