
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/*
我们称一个长度为n的序列为正则序列，当且仅当该序列是一个由1~n组成的排列，即该序列由n个正整数组成，取值在[1,n]范围，
且不存在重复的数，同时正则序列不要求排序

有一天小团得到了一个长度为n的任意序列，他需要在有限次操作内，将这个序列变成一个正则序列，每次操作他可以任选序列中的一个数字，
并将该数字加一或者减一。

请问他最少用多少次操作可以把这个序列变成正则序列？

输入描述:
输入第一行仅包含一个正整数n，表示任意序列的长度。(1<=n<=20000)
输入第二行包含n个整数，表示给出的序列，每个数的绝对值都小于10000。

*/
//贪心法：从小到大排序后，然后和目标元素相减
int main(){

    int n,x,y;
    vector<int> score;
    cin>>n;
   
    for(int i=0; i<n; i++)
    {
        int tmp;
        cin>>tmp;
        score.push_back(tmp);
    }
    sort(score.begin(), score.end(), less<int>());
    long long ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += abs(i+1 - score[i]);
    }
    cout<<ans<<endl;
    return 0;
}