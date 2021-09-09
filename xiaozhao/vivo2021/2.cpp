/*
回文字符串就是正读和反读都一样的字符串，如“viv”、“nexen”、“12321”、“qqq”、“翻身把身翻” 等。
给定一个非空字符串 str，在最多可以删除一个字符的情况下请编程判定其能否成为回文字符串；如果可以则输出首次删除一个字符所能得到的回文字符串，
如果不行则输出字符串 "false" 。
*/

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

int main()
{

    string str;
    cin>>str;
    for(int i=0; i<str.size(); i++)
    {
        string temp = str.substr(0, i) + str.substr(i+1);
        int left = 0, right = str.size();
        while(left < right)
        {
            if(temp[left] != temp[right]) {
                break;
            }
            --right;
            ++left;
        }
        if(left >= right) {
            cout<<temp<<endl;
            return true;
        }
    }
    cout<<"false"<<endl;

    return 0;
}