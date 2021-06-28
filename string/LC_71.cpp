/*
给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。

请注意，返回的 规范路径 必须遵循下述格式：

始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
返回简化后得到的 规范路径 。

 

示例 1：

输入：path = "/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。 

示例 2：
输入：path = "/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根目录是你可以到达的最高级。
*/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        //测试用例1: "/..."
        //测试用例1: "/a//b////c/d//././/.."
        string temp, ans="";
        vector<string> vec;
        for(int i=0; i<path.size(); i++)
        {
            // if(path[i]=='.'){
            //     if (i>0 && path[i-1] == '.'){
            //         if(vec.size()>0) vec.pop_back();
            //     }
            //     else continue;
            // }
            // else if(path[i]=='/'){
            if(path[i]=='/'){
                 if(i>1 && temp==".." ){
                     if(vec.size()>0) vec.pop_back();
                 }
                 else if(i>1 && temp=="." )
                 {
                     ;
                 }
                 else{
                    if(temp.size()>0)
                        vec.push_back(temp);
                 }
                 temp="";
            }
            else
                temp.insert(temp.end(), path[i]);
        }
        if(temp.size()>0){
            if(temp == "..") {
                if(vec.size()>0) 
                    vec.pop_back();
            }
            else if(temp != ".")
                vec.push_back(temp);
        }
        
         for(int i=0; i<vec.size(); i++) {
             ans+="/";
             ans+=vec[i];
         }
         if(ans.size()==0) ans="/";
         return ans;


    }
};