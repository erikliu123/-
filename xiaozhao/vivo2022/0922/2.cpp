#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 未来空闲工作日
     * @return int整型
     */
    vector<int> mType{1,2,4};
    set<vector<int>> mAns;
    void dfs(int curSum, int target, vector<int> &tmp)
    {
        if(curSum > target)
        {
            return ;
        }
        if(curSum == target)
        {
            mAns.insert(tmp);
            return ;
        }
        for(int i=0; i<3; i++)
        {
            tmp.push_back(i);
            dfs(curSum+mType[i], target, tmp);
            tmp.pop_back();
        }

    }
    int workSchedule(int n) {
        // write code here
        vector<int> tmp;
        dfs(0, n, tmp);
        return mAns.size();
        
    }
};

int main()
{
    Solution a;
    a.workSchedule(3);
    return 0;
}