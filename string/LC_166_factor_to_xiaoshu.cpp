#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
166. 分数到小数
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。
如果小数部分为循环小数，则将循环的部分括在括号内。
如果存在多个答案，只需返回 任意一个 。
对于所有给定的输入，保证 答案字符串的长度小于 10^4 。

示例 1：

输入：numerator = 1, denominator = 2
输出："0.5"


特殊测试样例:
-1
-2147483648
*/
class Solution {
public:
    string fractionToDecimal(int numerat, int denominat) {
        string ans;
        if(numerat == 0)
        {
            ans = "0";
            return ans;
        }
        bool nega = (numerat > 0) ^ (denominat > 0);
        long long numerator = abs(numerat);
        long long denominator = abs(denominat);//因为可能有-2147483648的输入，只能设一个long long
        swap(numerator, denominator);
        map<int, int> yushu;
        if(denominator >= numerator)
        {
            ans = to_string(denominator/numerator);
        }
        denominator = denominator % numerator;
        if(denominator)
        {
            if(ans.size()==0) ans = "0";
            ans += ".";
        }
        string xiaoshu;
        int index = 0;
        while(denominator)//找到一个循环小数
        {
            if(yushu.count(denominator)){
                int start = yushu[denominator];
                xiaoshu.insert(xiaoshu.begin()+start, '(');
                xiaoshu.insert(xiaoshu.end(), ')');

                break;
            }
            yushu.insert(make_pair(denominator, index));
            /*求商*/
            denominator*=10;
            string tmp = to_string(denominator/numerator);
            xiaoshu += tmp;
            
            denominator = denominator % numerator;
            index ++;//商的位数增加
            
        }
        
        ans += xiaoshu;
        if(nega)
            ans.insert(ans.begin(), '-');
        return ans;


    }
};