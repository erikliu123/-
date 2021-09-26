#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std;

vector<int> edges(110010,0);
map<int, int> ans;
set<pair<int,int>> edgeMap;
int main(){
    
    int stations, routes, swaps;
    cin>>stations>>routes>>swaps;
    for(int i=0; i<routes; i++)
    {
        int x,y;
        cin>>x>>y;
        //两个地铁站之间可能有多条线路直接连接
        if(x > y)
            swap(x,y);
        // if(edgeMap.count(make_pair(x, y)))
        // {
        //     continue;
        // }
        edgeMap.insert(make_pair(x, y));
        edges[x]++;
        edges[y]++;
    }
      for(int i=0; i<stations; i++)
        ans[i+1] = edges[i+1];
    for(int i=0; i<swaps; i++)
    {
        int x,y;
        cin>>x>>y;
        swap(ans[x], ans[y]);

    }
    for(int i=0; i<stations; i++)
    {
        cout<<ans[i+1]<<" ";
    }
    cout<<endl;
    return 0;
}