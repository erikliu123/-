#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
2014. 重复 K 次的最长子序列
给你一个长度为 n 的字符串 s ，和一个整数 k 。请你找出字符串 s 中 重复 k 次的 最长子序列 。

子序列 是由其他字符串删除某些（或不删除）字符派生而来的一个字符串。

如果 seq * k 是 s 的一个子序列，其中 seq * k 表示一个由 seq 串联 k 次构造的字符串，那么就称 seq 是字符串 s 中一个 重复 k 次 的子序列。

举个例子，"bba" 是字符串 "bababcba" 中的一个重复 2 次的子序列，因为字符串 "bbabba" 是由 "bba" 串联 2 次构造的，而 "bbabba" 是字符串 "bababcba" 的一个子序列。
返回字符串 s 中 重复 k 次的最长子序列  。如果存在多个满足的子序列，则返回 字典序最大 的那个。如果不存在这样的子序列，返回一个 空 字符串。

提示：

n == s.length
2 <= k <= 2000
2 <= n < k * 8
s 由小写英文字母组成
*/

/*
检测步骤：（从len = 7到len = 1）
1. 得到合法的子序列
2. 得到某个子序列对应的全序列（prev_permutation）
3. 合法性子字符串检测

*/
class Solution {
    unordered_map<char, vector<int>> mSequence;
    bool valid(string &substr, string &dst, int k)
    {
        int curpos = -1;
        for(int i=0; i<k; i++)
        {
            for(auto x: substr)
            {
                auto it = upper_bound(mSequence[x].begin(),mSequence[x].end(), curpos);
                if(it == mSequence[x].end())
                {
                    return false;
                }
                curpos = *it;
            }
        }
        return true;
    }
    string last;
    vector<string> tempVec;
    void dfs(string &dst, int begin, int len, string &tmp)
    {
        if(tmp.size() == len)
        {
            if(tmp != last)
            {
                tempVec.push_back(tmp);
            }
            last = tmp;
            return ;
        }
        for(int i=begin; i<dst.size(); i++)
        {
            tmp.push_back(dst[i]);
            dfs(dst, i+1, len, tmp);
            tmp.pop_back();
        }
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> mHash;
        vector<pair<char, int>> cnt;
        int index = 0;
        mSequence.clear();
        for(auto x:s)
        {
            mHash[x]++;
            mSequence[x].push_back(index++);
        }
        for(auto x:mHash)
        {
            if(x.second >= k){
                    cnt.push_back(make_pair(x.first, x.second));//满足条件的字符串
            }
        }
        sort(cnt.begin(), cnt.end(), [](pair<char, int> &a, pair<char, int> &b)
        {
            return (unsigned int)a.first < (unsigned int)b.first;
        });
        string ans;
        //从1尝试到7
        for(int len=7; len>=1; len--)
        {
            //找到次数>=k的
            string tmp, tmp2;
            for(auto x: cnt)
            {
                int temp = x.second;
                while(temp >= k)
                {
                    temp -= k;
                    tmp += x.first;
                }
            }
            if(tmp.size() < len)
            {
                continue;
            }
            sort(tmp.begin(), tmp.end(), greater<char>());
            tempVec.clear();
            dfs(tmp, 0, len, tmp2); //抽取tmp的len个元素, 得到全序列
          
            int count = 0;
            vector<string> tempVec2;
            
            for(int i=0; i<tempVec.size(); i++)
            {
                string next=tempVec[i];
                do{
                    tempVec2.push_back(next);
                    prev_permutation(next.begin(), next.end());
                    //cout<<next<<endl;
                }while(next != tempVec[i]);
            }
            sort(tempVec2.begin(), tempVec2.end(), greater<string>());
            for(int i=0; i<tempVec2.size(); i++)
            {
                string next=tempVec2[i];
               
                if(valid(next, s, k))
                {
                    ans = next;
                    return ans;
                }
                  
               
            }

        }
        return ans;

    }
};