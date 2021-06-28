
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。


示例 1：
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成
*/

//用滑动窗口的方式去思考

class Solution {
public:
    string minWindow(string s, string t) {
        int len = INT_MAX;
        unordered_map<char, int> t_cnt, temp_cnt;//t_cnt记录每个字符应该有的个数， temp_cnt记录当前扫描区间内有各个字符的个数
        queue<int> q;
        string ans;
        int cur_cnt = 0;
        for(auto x: t)
        {
            t_cnt[x]++;
        }
        for(int i=0; i<s.size(); i++)
        {
            if(t_cnt.find(s[i]) != t_cnt.end())
            {
                q.push(i);
                if(temp_cnt[s[i]] < t_cnt[s[i]]){
                    
                    ++cur_cnt;
                }
                temp_cnt[s[i]]++;
                while(cur_cnt == t.size())
                {
                    int index = q.front();
                    if(len > (i-q.front()+1))
                    {
                        len = (i-q.front()+1);
                        ans = s.substr(index, len);
                    }
                   
                    --temp_cnt[s[q.front()]];
                    if(temp_cnt[s[index]] < t_cnt[s[index]]){
                        --cur_cnt;
                    }
                     q.pop();
                }
                
            }

        }
        return ans;

    }
};