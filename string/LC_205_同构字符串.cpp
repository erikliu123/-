#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
/*
205. 同构字符串
给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，

相同字符只能映射到同一个字符上，字符可以映射到自己本身。
*/

//两个哈希表即可，保存a<->b的双射规则
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash;
        set<char> already_has;//为了防止 a->b c->b 这样的映射！
        vector<int> dp_s(256, 0), dp_t(256, 0);
        int start = 0;
        for(auto x:s)
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