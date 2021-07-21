#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;
/*
给定一个字符串数组，将字母异位词组合在一起。可以按任意顺序返回结果列表。

字母异位词指字母相同，但排列不同的字符串。

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]


1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        //[capture] (params) mutable->return-type {statement}
       
        auto arrayHash = [] (const array<int, 26>& arr) {//
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                hash<int> hash_int;
                //cout<<num<<"\t"<<hash_int(num)<<endl;
                return (acc << 1) ^ hash_int(num);//fn是一个仿函数
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/group-anagrams/solution/zi-mu-yi-wei-ci-fen-zu-by-leetcode-solut-gyoc/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main()
{
    Solution a;
    vector<string> str{"abcde", "debac", "bba", "aab"};
    a.groupAnagrams(str);
}