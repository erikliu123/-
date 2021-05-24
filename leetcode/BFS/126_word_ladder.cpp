#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
/*
按字典 wordList 完成从单词 beginWord 到单词 endWord 转化，一个表示此过程的 转换序列 是形式上像 beginWord -> s1 -> s2 -> ... -> sk 这样的单词序列，并满足：

每对相邻的单词之间仅有单个字母不同。
转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词。注意，beginWord 不必是字典 wordList 中的单词。
sk == endWord
给你两个单词 beginWord 和 endWord ，以及一个字典 wordList 。请你找出并返回所有从 beginWord 到 endWord 的 最短转换序列 ，如果不存在这样的转换序列，返回一个空列表。每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回。

示例 1：

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
输出：[["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
解释：存在 2 种最短的转换序列：
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
示例 2：

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
输出：[]
解释：endWord "cog" 不在字典 wordList 中，所以不存在符合要求的转换序列。
 

提示：

1 <= beginWord.length <= 7
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord、endWord 和 wordList[i] 由小写英文字母组成
beginWord != endWord
wordList 中的所有单词 互不相同

*/

//这个解法只通过了19/32！
class Solution {
public:
    int min_depth;
    vector<bool> visited;
    vector<vector<string>> ans;
    //通过了 19/32
    int diff(string &a, string &b){
        if(a.size() != b.size()) return false;
        int cnt=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]!=b[i]) ++cnt;

        }
        return cnt;
    }

    bool valid(string &a, string &b){
        if(a.size() != b.size()) return false;
        int cnt=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]!=b[i]) ++cnt;
            if(cnt>1) return false;

        }
        return cnt==1;
    }
    void bfs(string &beginWord, string &endWord, vector<string>& wordList, int step, vector<int>& record)
    {
        if(step > min_depth){
            return ;
        }
        vector<pair<int, int>> bfs_order;
        
        if(beginWord == endWord){
            if(step < min_depth){
                ans.clear();
                min_depth = step;
                //记录字符串
            }
            vector<string> str_vec;
            for(auto &i:record) str_vec.push_back(wordList[i]);
                ans.push_back(str_vec);
            return ;
        }
        
        for(int i=0; i<wordList.size(); i++)
        {
            //只相差一个字符
            if(!visited[i] && valid(wordList[i], beginWord))
            {
                int dist=diff(wordList[i], endWord);
                bfs_order.push_back(make_pair(i, dist));
               
            }

        }
        sort(bfs_order.begin(), bfs_order.end(), [](pair<int, int> x,pair<int, int> y){return x.second<y.second;});
        for(auto &i: bfs_order)
        {
            visited[i.first]=true;
            record.push_back(i.first);
            bfs(wordList[i.first], endWord, wordList, step+1, record);
            record.pop_back();
            visited[i.first]=false;
        }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<int> record;
        set<string> wordset(wordList.begin(), wordList.end());
        visited=vector<bool>(wordList.size(), false);
        if(!wordset.count(endWord)) 
            return ans;
        min_depth=wordList.size()+1;
        bfs(beginWord, endWord, wordList, 0, record);
        for(auto &i:ans) i.insert(i.begin(), beginWord);
        return ans;

    }
};
