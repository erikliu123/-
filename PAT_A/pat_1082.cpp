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
//-123456789
//Sample Output 1:
//Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
//123450001
string wei[]= {"Shi", "Bai", "Qian", "Wan", "Yi"};
map<int, string> names;
string yitoshi[]= {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main()
{

    int n;
//    int stu[5][5]={2};
//    cout<<stu[1][3]<<endl;

    vector<string> ans;
    cin>>n;
    names[1]="Shi";
    names[2]="Bai";
    names[3]="Qian";
    names[4]="Wan";
    names[8]="Yi";
    if(n<0)
    {
        cout<<"Fu ";
        n=-n;
    }
    else if(n==0)
    {
        cout<<yitoshi[0];
    }
    int start=0;
    int last=0, first_zero=0;
    bool haszero=false;

    while(n>0)
    {
        int temp=n%10;
        n=n/10;
        if(temp!=0)
        {
            if(haszero && first_zero!=0)
            {
                ans.push_back(yitoshi[0]);//0
            }

            if(start>4 && start<8 && haszero && first_zero<=4) //10008000的情况
            {
                ans.push_back(names[4]);
            }
            if(start>8 && start<12 && haszero && first_zero<=8) //10008000的情况
            {
                ans.push_back(names[8]);
            }
            if(start>0 && start<=4 || start==8)//十百千
                ans.push_back(names[start]);
            else if(start>4 && start<8)
                ans.push_back(names[start-4]);
            ans.push_back(yitoshi[temp]);
            haszero=false;
        }
        else
        {
            if(!haszero)
                first_zero=start;
            haszero=true;
        }
        ++start;
    }
    for(int i=ans.size()-1; i>=0; i--)
    {
        if(i==0)
            cout<<ans[i];
        else
            cout<<ans[i]<<" ";
    }
    return 0;

}
