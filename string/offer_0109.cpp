#include <iostream>
#include <vector>

using namespace std;

/*
面试题 01.09. 字符串轮转
字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。
*/
class Solution {
public:
    //return (s1+s1).find(s2) != string::npos;
    bool isFlipedString(string s1, string s2) {//最好的方法：s1+s1中查找s2即可
        string str;
        if(s1.size() != s2.size()){
            return false;
        }
        if(s1.size()==0) return true;

        //vector<int> first_alpha;
        for(int i=0; i<s2.size(); i++)
        {
            if(s2[i]==s1[0])
            {
                int start = (i+1)%s2.size(), start1 = 1;
                bool same = true;
                while(start != i)
                {
                    if(s2[start] != s1[start1]){
                        same  = false;
                        break;
                    }
                    ++start1;
                    start = (start + 1)%s2.size();
                }
                if(same) return true;

            }
        }

        // for(int i=0; i<s1.size(); i++)
        // {
        //     str = s1.substr(i) + s1.substr(0, i); 
        //     if(str == s2) return true;
        // }
        return false;


    }
};