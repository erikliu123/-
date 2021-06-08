#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<vector<bool>> visited;
int ans;
bool valid_pos(pair<int , int> &start)
{
    if(start.first <0 || start.first >=M || start.second<0 || start.second>=N) return false;
    return true;
}
void dfs(vector<vector<int>> &panel, pair<int , int> start, pair<int , int> end, int steps, long long cursum)
{
    vector<int> direct{-1,0,1,0,-1};
    pair<int , int> next;
    visited[start.first][start.second] = true;
    if(start == end)
    {   
        int tmp = (cursum) /(steps + 1);
        if(ans < tmp){
            ans = tmp;
        }
         visited[start.first][start.second] = false;//NOTICE：这里需要注意设置回去
        return ;

    }
    for(int i=0; i<4; i++)
    {
        next.first = start.first + direct[i];
        next.second = start.second + direct[i+1];
        if(valid_pos(next) && !visited[next.first][next.second])
        {
            
            dfs(panel, next, end, steps + 1, cursum+panel[next.first][next.second]);//确保传进来的坐标一定是OK的

        }

    }
    visited[start.first][start.second] = false;


}
int main()
{
    vector<vector<int>> compute_cost;
    vector<vector<int>> dp;
    cin>>M>>N;
    visited = vector<vector<bool>>(M, vector<bool>(N, false));
    for(int i=0; i<M; i++)
    {
        vector<int> tmp;
        for(int j=0; j<N; j++)
        {
            int x;
            cin >> x;
            tmp.push_back(x);

        }
        compute_cost.push_back(tmp);
    }

    //visited[0][0] = true;
    pair<int, int> start{0,0},end{M-1, N-1};
    dfs(compute_cost, start, end, 0, compute_cost[0][0]);

    cout<<ans<<endl;

    return 0;
}