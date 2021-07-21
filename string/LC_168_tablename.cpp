#include <iostream>
#include <vector>
using namespace std;

/*
给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。

例如：
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

*/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        for (; columnNumber > 0; columnNumber /= 26) {
            columnNumber--;
            ans += columnNumber % 26 + 'A';
        }
        return { ans.rbegin(),ans.rend() };
    }
};
