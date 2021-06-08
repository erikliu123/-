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
    if(start == end)
    {   
        int tmp = (cursum + panel[end.first][end.second]) /(steps + 1);
        if(ans < tmp){
            ans = tmp;
        }
        return ;

    }
    for(int i=0; i<4; i++)
    {
        next.first = start.first + direct[i];
        next.second = start.second + direct[i+1];
        if(valid_pos(next) && !visited[next.first][next.second])
        {
            visited[next.first][next.second] = true;
            dfs(panel, next, end, steps + 1, cursum+panel[start.first][start.second]);
            visited[next.first][next.second] = false;

        }

    }



}
int main()
{
    vector<vector<int>> compute_cost;
    vector<vector<int>> dp;
    cin>>M>>N;
    dp=vector<vector<int>>(M+1, vector<int>(N+1, 0));
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

    visited[0][0] = true;
    pair<int, int> start{0,0},end{M-1, N-1};
    dfs(compute_cost, start, end, 0, 0);

    cout<<ans<<endl;
    // for(int i=0; i<M; i++)
    // {
        
    //     for(int j=0; j<N; j++)
    //     {
    //         dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]) + compute_cost[i][j];

    //     }
    // }
    // cout<<dp[M][N]/(M+N-1)<<endl;

    return 0;
}