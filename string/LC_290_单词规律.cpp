#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
/*
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false

*/

//和LC205题类似，一样的模板
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> hash;
        set<string> already_has;//为了防止 a->b c->b 这样的映射！
        vector<string> t;
        
        int start = 0;
        string temp;
        
        for(auto x:s)
        {
            if(x==' '){
                if(temp.size() >0) t.push_back(temp);
                temp = "";
            }
            else
            temp.push_back(x);
        }
        if(temp.size() >0) t.push_back(temp);

        if(t.size()!=pattern.size())
            return false;
        for(auto x:pattern)
        {
            if(!hash.count(x) )
            {
                    if(already_has.count(t[start])) return false;
                    hash[x] = t[start];
                    already_has.insert(t[start]);
                //}
            }
            else if(hash.count(x) && hash[x]!=t[start] )
                return false;

            ++start;
        }
        return true;
    }
};