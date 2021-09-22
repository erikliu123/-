#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回最多能挑选出多少个武将，使得两两之间均存在碾压关系。
     * @param heroes int整型vector<vector<>> 武将属性值列表
     * @return int整型
     */
    bool validPair(int a, int b, vector<vector<int> >& heroes)
    {
        if(a == b)
            return false;
        int aWin = 0, bWin = 0;
        for(int i=0; i<heroes[0].size(); i++)
        {
            if(heroes[a][i] <= heroes[b][i])
                return false;

        }
        return true;
    }
    
    int dfs(int start)
    {
        int depth = 1;
        int child = 0;
        visit[start] = true;
        if(dp[start] != -1)
             return dp[start];
        for(auto x:edge[start])
        {
            
            int ret = dfs(x);
            child = max(child, ret);
            
        }
        dp[start] = child+1;
        return child+1;
    }
    int maxRollingHeroes(vector<vector<int> >& heroes) {
        //两两之间存在碾压关系
        int n=heroes.size();
        int m=heroes[0].size();
        
        visit = vector<bool>(n, false);
        dp = vector<int>(n, -1);
        vector<int> in(n, 0);
         for(int i=0; i<n; i++)
            edge[i].clear();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                //比较两个人是不是互相碾压的
                if(validPair(i, j, heroes))//i碾压j
                {
                    edge[i].push_back(j);
                    in[j]++;
                }

                if(validPair(j, i, heroes))//j碾压i
                {
                    edge[j].push_back(i);
                     in[i]++;
                }

            }
        }
        //dfs遍历
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(in[i] == 0 && !visit[i])
            {
                int ret = dfs(i);
                ans = max(ans, ret);
            }
        }
        if(ans == 1)
              return 0;
        return ans;

    }
    
private:
    vector<bool> visit;
    vector<int> edge[1510];
    vector<int> dp;
};