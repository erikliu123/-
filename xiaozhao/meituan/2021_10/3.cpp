#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
/*
小美和小团所在公司的食堂有N张餐桌，从左到右摆成一排，每张餐桌有2张餐椅供至多2人用餐，公司职员排队进入食堂用餐。
小美发现职员用餐的一个规律并告诉小团：当男职员进入食堂时，他会优先选择已经坐有1人的餐桌用餐，只有当每张餐桌要么空着要么坐满2人时，
他才会考虑空着的餐桌；

当女职员进入食堂时，她会优先选择未坐人的餐桌用餐，只有当每张餐桌都坐有至少1人时，她才会考虑已经坐有1人的餐桌；

无论男女，当有多张餐桌供职员选择时，他会选择最靠左的餐桌用餐。现在食堂内已有若干人在用餐，另外M个人正排队进入食堂，
小团会根据小美告诉他的规律预测排队的每个人分别会坐哪张餐桌。

输入描述:
第一行输入一个整数T（1<=T<=10），表示数据组数。
每组数据占四行，第一行输入一个整数N（1<=N<=500000）；

第二行输入一个长度为N且仅包含数字0、1、2的字符串，第i个数字表示左起第i张餐桌已坐有的用餐人数；
第三行输入一个整数M（1<=M<=2N, 且保证排队的每个人进入食堂时都有可供选择的餐桌）；
第四行输入一个长度为M且仅包含字母M、F的字符串，若第i个字母为M，则排在第i的人为男性，否则其为女性。
*/

int main(){
    int T;
    cin>>T;
    
    while(T--)
    {
        int tables;
        string str;
        vector<int> tablePeople, ans;
        scanf("%d", &tables);//NOTICE: 用cin或者cout会导致超时！！！
        cin>>str;
        priority_queue<int, vector<int>, greater<int>> pq[2]; 
        int index = 0;
        //每桌的人数
        for(auto x:str){
            if(x!='2'){
                pq[x-'0'].push(index);
                tablePeople.push_back(x-'0');
            }
            index++;
        }
        int n;
        scanf("%d", &n);
        cin>>str;//男女顺序

        for(auto x:str)
        {
            int res;
            if(x == 'M')//男生先找有一人的
            {
                if(pq[1].empty())
                {
                     res = pq[0].top();
                     pq[1].push(res);
                     pq[0].pop();

                }
                else{
                    res = pq[1].top();
                    pq[1].pop();
                }     
            }
            else{
                if(!pq[0].empty())
                {
                    res = pq[0].top();
                    pq[1].push(res);
                    pq[0].pop();

                }
                else{
                    res = pq[1].top();
                    pq[1].pop();
                }
                

            }
            ans.push_back(res+1);
        }
        for(int i=0; i<ans.size(); i++)
            printf("%d\n", ans[i]);

    }

    
    return 0;
}