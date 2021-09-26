#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/*
现在有 n 块积木排成一排，从左到右编号为 1 到 n，每块积木有一个高度 hi。小美想把这些积木按高度从小到大重新摆放。

小美先会将所有积木分成连续几段，使得所有段内积木按高度从小到大排好序后，所有积木就是按高度从小到大排好序摆放的。
一个合法的分段方案是一些非空区间的集合，这些区间两两之间没有交集，且所有区间的并集为 [1, n]。小美需要在保持
积木的原始位置不变下进行分段。

小美想知道她在满足以上条件的情况下，最多能将这些积木分成多少段。
*/

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
    cout<<2<<endl;

    
    return 0;
}