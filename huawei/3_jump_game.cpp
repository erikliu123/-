#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;
/*
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。若不能到达。输出-1

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置
*/
int main()
{
    vector<int> station, jumps;//station记录输入的数组
    int n;
    
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        station.push_back(tmp);
        jumps.push_back(INT_MAX);
    }
    int end=0;
    int postion=0;
    int steps;
    for(int i=0; i<station.size()-1; i++)//注意循环边界是station.size()-1
    {
        postion=max(postion, station[i]+i);//position为能到达的最远距离
        if(i == end){
            end=postion;//在上个区间内搜索得到的最远距离
            ++steps;
        }
    }
    if(postion>=station[station.size()-1])
        cout<<steps<<endl;
    else
        cout<<-1<<endl;

    return 0;
}


