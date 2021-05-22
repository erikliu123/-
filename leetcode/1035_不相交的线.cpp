
#include <iostream>
#include <vector>
using namespace std;

/*
在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。

现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足满足：

 nums1[i] == nums2[j]
且绘制的直线不与任何其他连线（非水平线）相交。
请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。

以这种方法绘制线条，并返回可以绘制的最大连线数。

 
提示：

1 <= nums1.length <= 500
1 <= nums2.length <= 500
1 <= nums1[i], nums2[i] <= 2000
 
*/
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        int lines=0;
        for(int i=0; i<nums1.size(); i++)
        {
             for(int j=0; j<nums2.size(); j++)
             {
                 if(nums1[i]==nums2[j]){
                     dp[i+1][j+1] = dp[i][j] + 1;
                 }
                 else{
                     dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                 }
                 lines=max(lines, dp[i+1][j+1]);
             }
        }
        return lines;

    }
};

//解法2，减少空间复杂度
/*
执行用时：20 ms
, 在所有 C++ 提交中击败了59.90%的用户
内存消耗：9.4 MB, 在所有 C++ 提交中击败了98.23%的用户
*/
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dp(nums2.size()+1, 0);
        int lines=0;
        for(int i=0; i<nums1.size(); i++)
        {
            int x = dp[0];
             for(int j=0; j<nums2.size(); j++)
             {
                 int temp=dp[j+1];
                 if(nums1[i]==nums2[j]){
                     dp[j+1] = x + 1;
                 }
                 else{
                     dp[j+1] = max(dp[j+1], dp[j]);
                 }
                 x=temp;
                 lines=max(lines, dp[j+1]);
             }
        }
        return lines;

    }
};