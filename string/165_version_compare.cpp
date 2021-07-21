#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
给你两个版本号 version1 和 version2 ，请你比较它们。

版本号由一个或多个修订号组成，各修订号由一个 '.' 连接。每个修订号由 多位数字 组成，可能包含 前导零 。
每个版本号至少包含一个字符。修订号从左到右编号，下标从 0 开始，最左边的修订号下标为 0 ，下一个修订号下标为 1 ，以此类推。
例如，2.5.33 和 0.1 都是有效的版本号。

比较版本号时，请按从左到右的顺序依次比较它们的修订号。比较修订号时，只需比较 忽略任何前导零后的整数值 。也就是说，
修订号 1 和修订号 001 相等 。如果版本号没有指定某个下标处的修订号，则该修订号视为 0 。例如，版本 1.0 小于版本 1.1，
因为它们下标为 0 的修订号相同，而下标为 1 的修订号分别为 0 和 1 ，0 < 1 。

返回规则如下：
如果 version1 > version2 返回 1，
如果 version1 < version2 返回 -1，
除此之外返回 0。

*/
class Solution {
public:
    
    int compareVersion(string version1, string version2) {
        // int points1 = 0, points2 = 0;
        // for(auto x: version1){
        //     if(x=='.')
        //         ++points1;
        // }
        // for(auto x: version2){
        //     if(x=='.')
        //         ++points2;
        // }
        // // if(points1!=points2)
        // //     return -1;
        int num1 = 0, start2 = 0;
        int num2 = 0;
        for(int i=0; i<version1.size() || num1>0; i++)
        {
            if(version1.size()==i || version1[i] == '.'){
                if(start2<version2.size()){
                    for( ;start2<version2.size() && version2[start2]!='.'; start2++)
                    {   
                        num2 = num2*10 + version2[start2]-'0';
                    }
                }
                //if(num1 != num2) return     
                ++start2;
                if(num1 != num2) {
                    if(num1>num2) return 1;
                    else return -1;
                }
                num2 = 0;
                num1 = 0;
            }
            else{
                num1 = num1*10 + version1[i]-'0';
            }
            
        }
        //如果后面数字都是0, 则返回0
        ///num2 = 0;
         if(start2<version2.size()){

            for( ;start2<version2.size() ; start2++)
            {   
                if(version2[start2]!='.')
                    num2 = num2*10 + version2[start2]-'0';
                else{
                    if(num2 > 0) return -1;
                    num2 = 0;
                }
            }
        }
        return num2 > 0? -1:0;
        

    }
};