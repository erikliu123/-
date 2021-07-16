#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

vector<vector<int>> edge;
vector<int> ans;

void solution(int n, int k)
{
    map<int, set<int>> map;
    //priority_queue<int, vector<int>, greater<int>> pq;
    set<int> pq;
    for(auto v: edge)
    {
        // map.insert({v[0], v[1]});
        // map.insert({v[1], v[0]});
        map[v[0]].insert(v[1]);
        map[v[1]].insert(v[0]);
    }
    
    for(int i=1; i<=n; i++)
    {
        if(map.count(i) && map[i].size() == 1)
        {
            pq.insert(i);
        }
    }
    int x=k;
    while(k--)
    {
        int nums = *pq.begin();
        pq.erase(pq.begin());
        ans.push_back(nums);
        //int nums_2 = *map[nums].begin();//不能保证找到最小的?
        for(int i=1; i<=n; i++)
        {
            if(map.count(i) &&  map[i].count(nums))
            {
                map[i].erase(nums);
            }
        }
        map.erase(nums);
        for(int i=1; i<=n; i++){
            if(map.count(i) && map[i].size() == 1 && !pq.count(i))
            {
                pq.insert(i);
            }
        }
        
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n-1; i++)
    {
        int start, end;
        cin>>start>>end;
        edge.push_back({start, end});

    }
    solution(n, k);  
    sort(ans.begin(), ans.end());
    for(int i=0; i<k-1; i++){
        cout<<ans[i]<<" ";
    }
    if(k>0)
        cout<<ans[k-1]<<endl;

    return 0;

}