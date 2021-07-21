#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，
识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

示例 1：
输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
示例 2：

输入：s = "AAAAAAAAAAAAA"
输出：["AAAAAAAAAA"]

*/
class Solution {
public:
    int char_toint(char a)
    {
        switch (a)
        {
        case 'A':
            return 0;
            //break;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
        default:
            return -1;
            break;
        }
    }
    vector<string> findRepeatedDnaSequences(string s) {
        //哈希长度
        set<string> ans;
        vector<string> vec;
        unordered_map<int, int> hash;
        //unordered_map<char, vector<int>> hash;
        if(s.size() < 11){
            return vec;
        }
        const int dest_len = 10;
        int hash_value = 0;
        for(int i=0; i<10; i++)
        {
            hash_value = (hash_value<<2) | char_toint(s[i]);
        }
        hash.insert(make_pair(hash_value, 0));
        for(int i=10; i<s.size(); i++)
        {
            hash_value = hash_value & (0x3ffff);
            hash_value = (hash_value<<2) | char_toint(s[i]); 
            if(hash.count(hash_value))
            {
                ans.insert(s.substr(hash[hash_value], 10));
            }
            else{
                 hash.insert(make_pair(hash_value, i-10));
            }


        }

        for(auto &x: ans)
            vec.push_back(x);
        return vec;
        

    }
};