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

int main() {
 int n;
 scanf("%d",&n);
 string m[100];
 string suffix;
 int len = 300;
 for(int i=0;i<n;i++){
  getchar();
  getline(cin,m[i]);
  reverse(m[i].begin(),m[i].end());
  if(m[i].size()<len)
   len = m[i].size();
 }
 //suffix=m[0];
    for(int i=0; i<len; ++i){
        bool same=true;
        for(int j=1;j<n;j++){
            if(m[j-1][i]!=m[j][i]){
                same=false;
                break;
            }
        }
        if(same)
        {
            suffix+=m[0][i];
            cout<<suffix<<endl;
        }
        else break;
    }
//  for(int i=1;i<n;i++){
//   //int len=suffix.size();
//   string temp;
//   for(int j=0;j<len;j++){
//    if(suffix[j]==m[i][j])
//     temp+=m[i][j];
//    else
//     break;
//   }
//   /*for(auto it=m[i].begin();it!=m[i].end();it++){
//    if(suffix[it]==(*it))
//     temp+=(*it);
//    else break;
//   }*/
//   if(temp.size()<suffix.size())
//    suffix=temp;
//  }
 reverse(suffix.begin(),suffix.end());
 if(suffix.size()>0)
  //printf("%s",suffix);
  cout<<suffix;
 else
  printf("nai");
 return 0;
}
