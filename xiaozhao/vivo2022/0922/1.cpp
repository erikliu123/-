#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct user
{
    int id;
    double cost, expect;
    bool operator < (const user &a) const
    {
        double x = cost / expect;//越小越好
        double y = a.cost / a.expect;
        return x<y;
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算满足条件：”确保avg_cost <= K，同时能给平台吸引到最多的新用户“ 的用户集合。
返回列表格式，按用户id升序排序
     * @param userIdList int整型vector 用户id列表
     * @param costList double浮点型vector 用户的成本列表，和用户id列表一一对应
     * @param conversionList double浮点型vector 用户转化概率列表，和用户id列表一一对应
     * @param avg_cost double浮点型 约束的最高期望推广成本
     * @return int整型vector
     */
    vector<int> ans;
   // void dfs()
    vector<int> calculateUserList(vector<int>& userIdList, vector<double>& costList, 
                                  vector<double>& conversionList, double avg_cost) {
        // write code here
        //sum(cost) / sum(pi) <= avg_cost
        ans.clear();
        vector<user> all;
        for(int i=0; i<userIdList.size(); i++)
        {
            user tmp={userIdList[i], costList[i], conversionList[i]};
            all.push_back(tmp);
        }
        sort(all.begin(), all.end());
        double sum = 0, sumExpect = 0;
        int people = 0;
         for(int i=0; i<userIdList.size(); i++)
         {
             sum+=all[i].cost;
             sumExpect+=all[i].expect;
             if(sum / sumExpect > avg_cost)
             {
               break;
             }
             ans.push_back(all[i].id);
             ++people;
         }
         sort(ans.begin(), ans.end());
         return ans;

    }
};
int main(){
    
    return 0;
}

