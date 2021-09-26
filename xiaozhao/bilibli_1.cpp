#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

/*
在电话按键上只能按照马的方式走，求走法种类
1 2 3
4 5 6
7 8 9
  0
*/
int main(){
    int n;
    cin>>n;
    int nums[]={0,2,2,2,3,0,3,2,2,2,2};
    unordered_map<int, vector<int>>  mHash=
    {
        {1, {6,8}},
        {2, {7,9}},
        {3, {4,8}},
        {4, {3,9,10}},
        {5, {}},
        {6, {1,7,10}},
        {7, {2,6}},
        {8, {1,3}},
        {9, {2,4}},
        {10, {4,6}},
    };
    
    vector<int> types(11, 1);
     
    int ans = 10;
    for(int i=2; i<=n; i++)
    {
        vector<int> tmp = types;
     
        for(int k=1; k<=10; k++)
        {
            int sum = 0;
            for(auto x:mHash[k])
            {
                  sum = (sum + tmp[x])%1000000007;
            }
            types[k] = sum;
        }
        
    }
    int sum = 0;
    for(int i=1; i<=10; i++)
    {
         sum = (sum + types[i])%1000000007;
    }
    cout<<sum<<endl;

    
    return 0;
}
