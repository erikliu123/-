#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>

using namespace std;
/*
1743. 从相邻元素对还原数组
存在一个由 n 个不同元素组成的整数数组 nums ，但你已经记不清具体内容。好在你还记得 nums 中的每一对相邻元素。
给你一个二维整数数组 adjacentPairs ，大小为 n - 1 ，其中每个 adjacentPairs[i] = [ui, vi] 表示元素 ui 和 vi 在 nums 中相邻。
题目数据保证所有由元素 nums[i] 和 nums[i+1] 组成的相邻元素对都存在于 adjacentPairs 中，存在形式可能是 [nums[i], nums[i+1]] ，
也可能是 [nums[i+1], nums[i]] 。这些相邻元素对可以 按任意顺序 出现。

返回 原始数组 nums 。如果存在多种解答，返回 其中任意一个 即可。
*/

//思考：如果允许[1,1] [2,2] [1,2]这种，应该怎么还原序列
//应该是先忽略掉自环，然后在还原答案的时候把有自环的加上...但比如[1,1] [1,2], [1,1] ==> 1,1,1,2
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, int> hash;
        unordered_map<int, vector<int>> edge;
        for(auto x: adjacentPairs)
        {
            if(x[0] != x [1]){
                edge[x[0]].push_back(x[1]);
                edge[x[1]].push_back(x[0]);
            }
            
            for(auto y:x)
            {
                hash[y]++;
            }
        }
        vector<int> ans;
        unordered_map<int, bool> visit;
        for(auto &x: hash)
        {
            //int y=x.first;
            if(x.second == 1)//may not exits. 从度为1的顶点开始DFS
            {
                x.second--;
                ans.push_back(x.first);
                visit[x.first] = true;
                break;
            }
        }
        
        for(int i=1; i<=adjacentPairs.size(); i++)
        {
            for(auto x: edge[ans.back()])
            {
                if(!visit[x])
                {
                    visit[x] = true;
                    ans.push_back(x);
                }
            }

        }
        return ans;

    }
};