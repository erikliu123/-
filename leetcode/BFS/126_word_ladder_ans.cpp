#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <map>
#include <unordered_map>
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
/*
"qa"
"sq"
["si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"]

"hit"
"cog"
["hot","dot","dog","lot","log","cog"]

*/

class Solution
{
public:
    int min_depth;
    vector<bool> visited;
    vector<vector<string>> ans;
    void getPath(unordered_map<string, vector<string>> &bfs_graph, string &dst, vector<string> &tmp)
    {
        if(bfs_graph[dst].empty())
        {
            ans.push_back({tmp.rbegin(), tmp.rend()});//要有花括号！
            return;
        }
        for(auto &i: bfs_graph[dst]){
            tmp.push_back(i);
            getPath(bfs_graph, i, tmp);
            tmp.pop_back();
        }

    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<int> record;
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        visited = vector<bool>(wordList.size(), false);
        if (!word_set.count(endWord))
            return ans;
        word_set.erase(beginWord);
        queue<string> q = queue<string>{{beginWord}};
        unordered_map<string, vector<string>> bfs_graph;
        unordered_map<string , int> steps{{beginWord, 0}};//一开始没想到要用这个变量保存路径
        min_depth = 0;
        int len = beginWord.size();
        bool found = false;
        while (!q.empty())
        {
            ++min_depth;
            int size = q.size();
            for (int ql = 0; ql < size; ql++)
            {
                string cur_head = q.front();
                string cur = cur_head;
                q.pop();

                for (int i = 0; i < len; i++)
                {
                    char origin = cur[i];

                    for (int k = 0; k < 26; k++)
                    {
                        cur[i] = 'a' + k;
                        /*这两个if不可能同时满足！要第一个if满足，必须要历经第二个if*/
                        if (steps[cur] == min_depth) {//当所有word加进来后，word_set为空，但还是可以有新的路径！！
                        /*
                        比如下面这个例子，2->4加进来后,还是可以添加3->4, 5->4
                             1
                           / | \
                          2  3  5
                           \ | /
                             4
                        */
                            bfs_graph[cur].push_back(cur_head);
                        }

                        if (word_set.count(cur))//一个新的点加到图里面
                        {
                            bfs_graph[cur].push_back(cur_head);
                            q.push(cur);
                            word_set.erase(cur);
                            steps[cur] = min_depth;
                            if (cur == endWord)
                            {
                                found = true;
                            }
                        }
                    }
                    cur[i] = origin;
                }
                
            }
            if (found){
                vector<string> svec;
                svec.push_back(endWord);
                getPath(bfs_graph, endWord, svec);
                break;
            }
        }


        return ans;
    }
    
};
int main()
{
    string src="hit", dst="cog";
    vector<string> vec{{"hot","dot","dog","lot","log","cog"}};
    Solution a;
    a.findLadders(src, dst, vec);
    return 0;

}