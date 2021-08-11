#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
/*
给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

注意：不允许旋转信封。

 
示例 1：

输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出：3
解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b)
        {
            return a[0] < b[0];
        });
        int maxheight = 1;
        //
        multiset<int> height;
        unordered_map<int, int> hash;
        int maxCol = 1;
         hash[envelopes[0][0]] = envelopes[0][1];
        for(int i=0; i<envelopes.size(); i++)
        {
            //插入高度后查看
            bool insert = true;
            //cout<<*it<<endl;
            
            if(i>0 && envelopes[i-1][0] != envelopes[i][0])
            {
                hash[envelopes[i][0]] = envelopes[i][1];
                ++maxCol;
            }
            else if(i>0){
                if(hash[envelopes[i][0]] > envelopes[i][1])
                {
                    height.erase(hash[envelopes[i][0]]);
                    hash[envelopes[i][0]] = envelopes[i][1];
                }
                else 
                insert = false;
            }
             auto it = height.lower_bound(envelopes[i][1]);
            if(it == height.end())
            {
                maxheight = height.size() + 1;//max((int)height.size() + 1, maxCol);
            }
            else
            {
                maxheight = max(maxheight, (int)distance(height.begin(), it));

            }
            if(insert)
            height.insert(envelopes[i][1]);

        }
        return maxheight;


    }
};
int main()
{
    vector<vector<int>> test{
        {2,3},
        {6,7},
        {4,4},
        {6,4}
    };
    vector<vector<int>> test2{
        {2,100},//pick
        {3,200},//pick
        {4,300},//pick
        {5,500},
        {5,400},
        {5,250},//pick, 问题核心，它此时不能囊括2~3的内容
        {6,370},
        {6,360},//pick 
        {7,380}//pick
    };//
    Solution a;
    a.maxEnvelopes(test2);
    return 0;
}