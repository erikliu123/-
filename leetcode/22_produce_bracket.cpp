#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。


示例 1：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
*/

class Solution {
public:
    set<string>  ans;
    //NOTICE:保持左括号大于等于右括号即可
    void DFS(int left_bracket, int right_bracket, int n, string &tmp)
    {
        if(left_bracket < n)
        {
            tmp.push_back('(');
            DFS(left_bracket+1, right_bracket, n, tmp);

            tmp.pop_back();
            if(left_bracket > right_bracket){
                tmp.push_back(')');
                DFS(left_bracket, right_bracket+1, n, tmp);
                tmp.pop_back();
            }

        }
        else{
            string temp=tmp;
            if(right_bracket < left_bracket) {
                temp.insert(temp.end(), left_bracket-right_bracket, ')');

            }
            ans.insert(temp);

        }
    }
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string> result;
        DFS(0, 0, n, str);
        for(auto it:ans){
            result.push_back(it);
        }
        return result;

    }
};

int main()
{
    Solution a;
    auto it=a.generateParenthesis(4);
    for(auto q:it){
        cout<<q<<endl;
    }
    return 0;
}