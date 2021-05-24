#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<map>
using namespace std;

/*
树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。

给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 
之间存在一条无向边。

可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。
请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。

树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
 
提示：

1 <= n <= 2 * 10^4
edges.length == n - 1
0 <= ai, bi < n
ai != bi
所有 (ai, bi) 互不相同
给定的输入 保证 是一棵树，并且 不会有重复的边

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-height-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    map<int, int> dist;
     vector<bool> visited;
    int dfs( unordered_map<int, vector<int>> &graph, int start, int parent)
    {
        int ret = 0;
        int key = start*100000+parent;
        if(dist[key]) return dist[key];

        visited[start] = true;
        for(auto &i:graph[start]){

            if(!visited[i])
                ret = max(ret , dfs(graph, i, start));
        

        }
        dist[key] = ret + 1;
        return dist[key];
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int min_depth = n;
        vector<int> root;
        unordered_map<int, vector<int>> graph;
        vector<pair<int, int>> connect;
        
        for(int i=0; i<n; i++){
            connect.push_back(make_pair(i, 0));
        }
        for(auto &i: edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            connect[i[0]].second++;
            connect[i[1]].second++;
        }
        sort(connect.begin(), connect.end(), [](pair<int, int> a, pair<int, int> b){ return a.second>b.second;});
        for(int i=0; i<n; i++){
            visited = vector<bool>(n, false);
            int depth = dfs(graph, i, -1);
             if(depth < min_depth){
                root.clear();
                root.push_back(i);
                min_depth = depth;
            }
            else if(depth == min_depth){
                root.push_back(i);
            }

        }
        return root;

        /*BFS解法在万级别的数量级上会出问题！*/
        for(auto &it: connect)
        {
            queue<int> bfs;
            int i = it.first;
            bfs.push(i);
            int depth = 0;
            vector<bool> visit(n, false);
            visit[i] = true;
            while(!bfs.empty())
            {
                ++depth;
                int len = bfs.size();
                for(int k=0; k<len; k++)
                {
                    int point = bfs.front();
                    bfs.pop();
                    for(int m=0; m<graph[point].size(); m++){
                        int x = graph[point][m];
                        if(!visit[x]){
                            visit[x] = true;
                            bfs.push(x);
                        }
                        
                    }
                }
                if(depth > min_depth) break;
            }
            if(depth < min_depth){
                root.clear();
                root.push_back(i);
                min_depth = depth;
            }
            else if(depth == min_depth){
                root.push_back(i);
            }

        }
        return root;


    }
};

int main()
{
    Solution a;
    vector<vector<int>> edges=vector<vector<int>>{{{3,0},{3,1},{3,2},{3,4},{5,4}}};
    a.findMinHeightTrees(5, edges);
    edges=vector<vector<int>>{{0,1},{1,2},{2,3},{0,4},{4,5},{4,6},{6,7}};
     a.findMinHeightTrees(7, edges);
    return 0;
}