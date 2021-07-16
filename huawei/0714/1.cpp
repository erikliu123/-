#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//通过100%
char map[1000][1000];
int visit[1000][1000];
int m, n;

vector<int> direction {-1,0,1,0,-1,1,-1};
void dfs(pair<int, int> start)
{
    visit[start.first][start.second] = true;
    for(int i=0; i<6; i++)
    {
        pair<int, int> it={start.first+direction[i], start.second+direction[i+1]};
        if(it.first <0 || it.first>=m || it.second <0 || it.second>=n)
        {
            continue;
        }
        else if(!visit[it.first][it.second] && map[it.first][it.second] == 'C')
        {
            dfs(it);
        }
    }

}
int main()
{
    
    cin>>m>>n;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>map[i][j];
        }
    }
    int ans = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j] == 'C' && !visit[i][j])
            {
                ans++;
                dfs(make_pair(i, j));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}