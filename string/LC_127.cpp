#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

/*
提示：

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord、endWord 和 wordList[i] 由小写英文字母组成
beginWord != endWord

*/

class Solution {
public:
    bool check(string &a, string &b)
    {
        int n = a.size();
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(a[i]!=b[i]) cnt++;
            if(cnt > 1)
                return false;

        }
        return cnt == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> str_set(wordList.begin(), wordList.end());
        map<string, bool> visit;
        if(!str_set.count(endWord))
        {
            return 0;
        }
        int depth = 1;
        queue<string> q;
        q.push(beginWord);
        str_set.erase(beginWord);
        visit[beginWord] = true;//NOTICE: visit要提前标记！！
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                string tmp = q.front();
                q.pop();

                if(tmp == endWord)
                {
                    return depth;
                }
                //visit[tmp] = true; //NOTICE: 把visit放这里这样可能导致队列中有重复的元素如访问到3时，又把2加进来 [1 3 2 2]
                for(auto x: str_set)
                {
                    if(check(x, tmp) && !visit.count(x))
                    {
                        visit[x] = true;
                        q.push(x);
                        //str_set.erase(x);
                       
                    }
                }
                // for(int k=0; k<tmp.size(); k++)
                // {
                //     string str = tmp;
                //     for(int i=0; i<26; i++)
                //     {
                //         if(tmp[k] != 'a'+i)
                //         {
                //             str[k] = 'a'+i;
                //             if(str_set.count(str) && !visit[str])
                //             {
                //                 q.push(str);
                //             }
                //         }
                //     }

                // }
                
            }
            cout<<n<<endl;
            ++depth;

        }
        return 0;



    }
};