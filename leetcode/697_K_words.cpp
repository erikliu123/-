#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

/*
给一非空的单词列表，返回前 k 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

示例 1：

输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。

*/

#define MYSELF
#ifdef MYSELF
static unordered_map<string, int> map_cnt;   
static bool compare(string &a, string &b)
{
    if(map_cnt[a] != map_cnt[b]){
        return map_cnt[a] > map_cnt[b];//如果是真，则交换
    }
    return a<b;

}

class Solution {
    
    priority_queue<string, vector<string>, decltype(&compare)> pq;
public:    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map_cnt.clear();
        pq=priority_queue<string, vector<string>, decltype(&compare)>(&compare);
        vector<string> res(k);
        for(auto &i:words){
            map_cnt[i]++;
        }
        for(auto &i:map_cnt){//NOTICE: auto &比 auto快很多，因为不要复制！！
            pq.push(i.first);
            if(pq.size() > k){//去除不可能的元素！
                pq.pop();
            }
        }
        for (int i = k - 1; i >= 0; i--) {
            res[i] = pq.top();
            pq.pop();
        }
           
        //reverse(res.begin(), res.end());
        return res;
        

    }
};
#else

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto& word : words) {
            cnt[word]++;
        }
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> que(cmp);
        for (auto& it : cnt) {
            que.emplace(it);
            if (que.size() > k) {//NOTICE: 这一步很重要！！
                que.pop();
            }
        }
        vector<string> ret(k);
        for (int i = k - 1; i >= 0; i--) {
            ret[i] = que.top().first;
            que.pop();
        }
        return ret;
    }
};

#endif

