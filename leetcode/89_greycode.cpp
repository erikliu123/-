#include<vector>
#include<set>
using namespace std;

class Solution {
public:
/*
执行用时：92 ms, 在所有 C++ 提交中击败了5.25%的用户
内存消耗：21.9 MB, 在所有 C++ 提交中击败了7.63%的用户
*/
    vector<int> grayCode(int n) {
         vector<int> ans;
         set<int> gray;
         ans.push_back(0);
         gray.insert(0);
         int tmp = 0;
         for(int i=0; i<(1<<n)-1; i++)
         {
             int k=0;
             for(; k<32; k++)
             {
                 int mask=1<<k;
                 if(!gray.count(tmp ^ mask)){
                     tmp = tmp ^mask ;
                     gray.insert(tmp);
                     ans.push_back(tmp);
                     break;
                 }


             }

         }
         return ans;

    }
    //递归解法，易于理解
    vector<int> grayCode(int n) {//递归解法
        if(n == 1)  return vector<int> {0,1};
        vector<int> ans = grayCode(n-1);
        int size = ans.size();
        for(int i =size-1;i>=0;i--)
        {
            ans.push_back(ans[i]^1<<(n-1));
        }
        return ans;
    }

};


//NOTICE:更好的解法, 利用数电所学
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int powN = 1 << n;
        for(int i = 0; i < powN; ++i)
            ans.push_back(i^i>>1);
        return ans;
    }
};

// 作者：Xiaohu9527
// 链接：https://leetcode-cn.com/problems/gray-code/solution/c5xing-dai-ma-xiang-xi-jie-xi-dui-xin-sh-xrkw/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。