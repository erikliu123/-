#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
/*
1239. 串联字符串的最大长度
给定一个字符串数组 arr，字符串 s 是将 arr 某一子序列字符串连接所得的字符串，如果 s 中的每一个字符都只出现过一次，那么它就是一个可行解。
请返回所有可行解 s 中最长长度。

示例 1：

输入：arr = ["un","iq","ue"]
输出：4
解释：所有可能的串联组合是 "","un","iq","ue","uniq" 和 "ique"，最大长度为 4。

提示：

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] 中只含有小写英文字母
*/

//NOTICE: 该问题不具有最优子结构，不可以使用动归，因为dp[i][j]子问题 dp[i+1][j]的最优解，不一定构成dp[i][j]的最优解，
//因为arr[i]不一定能加进来！！
//skill： 转化成异或操作！！快速判断字符串是否有重的
class Solution {
public:
    int ans;
    map<int, int> map_cnt;
    int cnt_num(int a)
    {
        int cnt = 0;
        while(a)
        {
            a=a&(a-1);
            ++cnt;
        }
        return cnt;
        
    }

    void dfs(vector<string>& arr,  int start, int size, int prev)
    {
        // for(int i=start; i<arr.size(); i++)
        // {
            ans = max(ans, size);
            if(start >= arr.size()) return ;
            int after = cnt_num(prev ^ map_cnt[start]);
            //cout <<after<<"\t"<< (cnt_num(prev) + arr[start].size()) <<endl;
            //if(map_cnt[start]!=0 && (after == (cnt_num(prev) + arr[start].size()))){
            if(map_cnt[start]!=0 && ((prev & ~map_cnt[start])== prev)){
                dfs(arr, start + 1, size + arr[start].size(), prev ^ map_cnt[start]);
            }

            dfs(arr, start+1, size, prev);//don't add
        //}



    }
    int maxLength(vector<string>& arr) {  

        for(int i=0; i<arr.size(); i++)
        {
            map_cnt[i] = 0;
            for(int x = 0; x<arr[i].size(); x++)
            {
                if(map_cnt[i] & ( 1 << (arr[i][x] - 'a'))) {
                    map_cnt[i] = 0;
                    break;
                }
                map_cnt[i] |= 1 << (arr[i][x] - 'a');
            }
        } 
        ans = 0;
        dfs(arr, 0, 0, 0);
        return ans;

    }
};