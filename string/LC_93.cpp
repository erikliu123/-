
#include <iostream>
#include <vector>

using namespace std;
/*
题目描述：
给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]

提示：

0 <= s.length <= 3000
s 仅由数字组成
*/


class Solution {
public:
    vector<string> ans;
    void dfs(string &s, vector<int> &tmp, int begin)
    {
        if(begin >= s.size())
        {
            if(tmp.size() == 4)
            {
                string str=to_string(tmp[0]);
                for(int i=0; i<3; i++){
                    str+=".";
                    str+=to_string(tmp[i+1]);
                }
                ans.push_back(str);

            }
            return ;
        }
        int x=0;
        for(int i=begin; i<s.size(); i++)
        {
            x=x*10+s[i]-'0';
            if(x==0){
                tmp.push_back(x);
                dfs(s, tmp, i+1);
                tmp.pop_back();
                break;

            }
            else if(x<256){
                tmp.push_back(x);
                dfs(s, tmp, i+1);
                tmp.pop_back();
            }
            else{
                break;
            }



        }

    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12) return ans;
        vector<int> tmp;
        dfs(s, tmp, 0);
        return ans;



    }
};
/*
题评：

个人认为，充分剪枝的回溯算法和三层嵌套的暴力循环，复杂度是一样的，而不存在什么“暴力循环是O(1)，回溯不是O(1)”的情况。字符串拷贝（构造）在许多语言下应当
都类似于数组拷贝，是一个O(|s|)的操作，暴力循环也无法避免数组拷贝，所以在输出集合生产这件事下，回溯 = 暴力循环。至于递归和循环究竟有多少层，画画递归调用栈
就看出来了，二者是一模一样的（当然递归需要剪枝）。

究其原因，本题说白了是一个每个顶点度最大为3，且半径最大为4的无向图，从中心出发完成遍历。这种图的循环当然好写了，因为规模小呀。而且本题因为状态的出现和
游标推移是完全一致的，所以并不需要构造图，循环显得非常易写。
脱离性能层面，也且不论代码可读性层面，回溯仍是必须要掌握的算法。虽然回溯算法由于“指数爆炸”通常不适用于大规模的计算，但它仍然是算法领域里一个重要组成，
甚至很多时候是最优解。并且，许多时候它逐渐缩小问题规模的思考方式，在特定的问题下，稍加改动就能通向很多其他算法分支——动态规划、记忆化搜索等。
*/