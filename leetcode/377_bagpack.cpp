#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
常见的背包问题有
1、组合问题。2、True、False问题。3、最大最小问题。
以下题目整理来自大神CyC，github地址：
github
我在大神整理的基础上，又做了细分的整理。分为三类。
1、组合问题：
377. 组合总和 Ⅳ
494. 目标和
518. 零钱兑换 II

2、True、False问题：
139. 单词拆分
416. 分割等和子集
3、最大最小问题：
474. 一和零
322. 零钱兑换
*/

class Solution {
public:
    //unordered_map<int, int> cnt;
    vector<int> dp;
    int ans;
    /*
    测试用例1： [5,1,8] 24
    测试用例2：（暴力搜索超时）
    [10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111]
999
    */
    int DFS(vector<int>& nums, int target, vector<int> &tmp)
    {
        
        if(dp[target] >= 0) return dp[target];
        int res=0;
        for(int i=0; i<nums.size() ; i++)
        {
            //tmp.push_back(nums[i]);
            if(target >= nums[i])
                res+=DFS(nums,  target-nums[i], tmp);
            //tmp.pop_back();
        }
        dp[target]=res;
        return res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        ans=0;
        vector<int> temp;
        dp=vector<int>(target+1, 0);
        dp[0] = 1;//很重要
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < nums.size(); j++){
                if(i >= nums[j] && dp[i - nums[j]] < INT_MAX){//NOTICE：判断溢出！
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];

        //带记忆的暴力搜索法
        sort(nums.begin(), nums.end());
        DFS(nums, target, temp);
        return dp[target];
    }
};

int main()
{
    Solution a;
    vector<int> small_test{1,2,3};
    vector<int> bigtest{10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,
    370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,
    760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
    int target=999;
    cout<<a.combinationSum4(small_test, 4)<<endl;//[1,2,3] 7
    cout<<a.combinationSum4(bigtest, 999)<<endl;
    return 0;
}