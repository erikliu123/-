#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

//while(left<right){
//    int mid=(left+right)/2;
//    if(arr[mid]>x) right=mid-1;
//    else if(arr[mid]<x) left=mid+1;
//    else return mid;
//
//}
int total[1000];
int main()
{
    vector<int> num;//ans;
    set<int, greater<int>> ans;
    int n;
    cin>>n;
    for(int i=0; i<n ;++i){
        int temp;
        cin>>temp;
        num.push_back(temp);
        while(temp!=1){
            if(temp<=100) total[temp]++;
            if(temp&0x1) temp=(temp*3+1)>>1;
            else temp=temp>>1;
        }
    }
    int cnt=0;
     for(int i=num.size()-1; i>=0 ;--i){
            if(total[num[i]]==1){
                ans.insert(num[i]);
            }

     }
     int i=0;
     for(auto it=ans.begin(); it!=ans.end() && i<ans.size(); it++, i++){
        if(i!=ans.size()-1){
            cout<<*it<<" ";
        }
        else cout<<*it;
     }
     cout<<endl;

    return 0;
}
