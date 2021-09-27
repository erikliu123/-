#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

/*
1418. 点菜展示表

给你一个数组 orders，表示客户在餐厅中完成的订单，确切地说， orders[i]=[customerNamei,tableNumberi,foodItemi]，
其中 customerNamei 是客户的姓名，tableNumberi 是客户所在餐桌的桌号，而 foodItemi 是客户点的餐品名称。

请你返回该餐厅的 点菜展示表 。在这张表中，表中第一行为标题，其第一列为餐桌桌号 “Table” ，后面每一列都是按字母顺序排列的餐品名称。
接下来每一行中的项则表示每张餐桌订购的相应餐品数量，第一列应当填对应的桌号，后面依次填写下单的餐品数量。

注意：客户姓名不是点菜展示表的一部分。此外，表中的数据行应该按餐桌桌号升序排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> dishes;//菜品
        map<int, map<string, int>> total;//核心: 桌子上对应的菜品，再到菜的数目
        vector<vector<string>> ans;
        vector<string> header;
        header.push_back("Table");
        for(auto &x: orders)
        {
            if(!dishes.count(x[2]))
                dishes.insert(x[2]);
            total[stoi(x[1])][x[2]]++;
        }
        for(auto &x: dishes){
            header.push_back(x);
        }
        ans.push_back(header);
        
        for(auto &x: total)
        {
            int i=0;
            header[i] = to_string(x.first);
            auto it=dishes.begin();
            for(int w=0; w<dishes.size(); it++, w++)//遍历所有的菜品
            {
                if(x.second.find(*it) != x.second.end())
                {
                    header[w+1]=to_string(x.second[*it]);
                }
                else
                    header[w+1]="0";
            }
             ans.push_back(header);

        }
        return ans;
    }
};