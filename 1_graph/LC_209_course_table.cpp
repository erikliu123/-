#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，
表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       unordered_map<int, int> inDegree, outDegree;//其实只需要记录入度数目，不需要出度
       unordered_map<int, vector<int>> graph;
       for(int i=0; i<numCourses; i++)
       {
           inDegree[i] = 0;
       }
        for(auto x:prerequisites)
        {
            inDegree[x[0]]++;
            outDegree[x[1]]++;
            graph[x[1]].push_back(x[0]);
        }
        //查看in degree的有哪些
        int count = 0;
        queue<int> q;
        for(auto x:inDegree)
        {
            if(x.second == 0){
                q.push(x.first);
            }
        }
        while(!q.empty())
        {
            int start = q.front();
            q.pop();
            ++count;
            for(auto x:graph[start])
            {
                --inDegree[x];
                if(inDegree[x] == 0)
                    q.push(x);
            }
            
        }
        //cout<<count<<endl;
        return count == numCourses;



    }
};