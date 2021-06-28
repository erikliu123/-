#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
/*
752. 打开转盘锁
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。、每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。

示例 1:

输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。

示例 2:
输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：
无法旋转到目标数字且不被锁定。
*/

/*
["5557","5553","5575","5535","5755","5355","7555","3555","6655","6455","4655","4455","5665","5445","5645","5465","5566","5544","5564","5546","6565","4545","6545","4565","5656","5454","5654","5456","6556","4554","4556","6554"]
"5555"
*/

/*
测试结果：
执行用时：80 ms, 在所有 C++ 提交中击败了89.71%的用户
内存消耗：14.8 MB, 在所有 C++ 提交中击败了95.60%的用户

此题从起点和终点同时遍历，速度会很快！！
单向遍历理论上也可以，但有可能超时
*/

//主要利用了set<string> cur_set,  end_set 作为visited访问数组
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> str(deadends.begin(), deadends.end());
        set<string> cur_set,  end_set;//cur_set从起点开始遍历过的点，end_set从终点开始遍历过的点
        queue<string> q, end_q;//q起点开始的BFS， end_q终点开始的BFS
        q.push("0000");
        cur_set.insert("0000");
        end_set.insert(target);
        end_q.push(target);
        int depth = 0;
        if(str.count(target) ||str.count("0000")) return -1;//起点终点都要判断, 一开始忘记判断"0000"
        if(target == "0000") return 0;
        while(!q.empty() && !end_q.empty())
        {
            int n = q.size();
            for(int i = 0; i<n ;i++)
            {
                auto p = q.front();
                //顺时针
                for(int k=0; k<4; k++)
                {
                    auto temp = p;
                    temp[k] = (temp[k]-'0'+1)%10 + '0';
                    if(!cur_set.count(temp) && !str.count(temp))
                    {
                        q.push(temp);
                        cur_set.insert(temp);
                        if(end_set.count(temp)) return depth + 1;
                    }
                   
                    //if(temp == target) return depth + 1;
                }
                //逆时针旋转
                for(int k=0; k<4; k++)
                {
                    auto temp = p;
                    temp[k] = (temp[k]-'0'+9)%10 + '0';
                    if(!cur_set.count(temp) && !str.count(temp))
                    {
                        q.push(temp);
                        cur_set.insert(temp);
                         if(end_set.count(temp)) return depth + 1;
                    }
                }
                q.pop();
                //cur_set.erase(p); //NOTICE: 不删除会导致死循环！ 比如a周围一格都是可以走的，不删掉这句话这个时候会出现a->a[1]->a->a[1]的死循环

            }
            ++depth;

            n = end_q.size();
            for(int i = 0; i<n ;i++)
            {
                auto p = end_q.front();
                //顺时针
                for(int k=0; k<4; k++)
                {
                    auto temp = p;
                    temp[k] = (temp[k]-'0'+1)%10 + '0';
                    if(!end_set.count(temp) && !str.count(temp))
                    {
                        end_q.push(temp);
                        end_set.insert(temp);
                         if(cur_set.count(temp)) return depth + 1;
                    }
                   
                }
                //逆时针旋转
                for(int k=0; k<4; k++)
                {
                    auto temp = p;
                    temp[k] = (temp[k]-'0'+9)%10 + '0';
                    if(!end_set.count(temp) && !str.count(temp))
                    {
                        end_q.push(temp);
                        end_set.insert(temp);
                        if(cur_set.count(temp)) return depth + 1;
                        //if(temp == target) return depth + 1;
                    }
                }
                end_q.pop();
                //end_set.erase(p);

            }
            ++depth;

        }
        return -1;



    }
};