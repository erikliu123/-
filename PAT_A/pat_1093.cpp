
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

int cntp[100010], cnta[100010],cntt[100010];
int total;
int main()
{
    string s;
    cin>>s;
    int left=0;
    int p=0, a=0, t=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='T')     ++t;
        else if(s[i]=='P') ++p;
        else if(s[i]=='A') ++a;
        cntp[i]=p;
        cnta[i]=a;
        cntt[i]=t;
    }
    //int hasp=0, hasa=0, hast=0;
    int lastp=-1,lasta=-1;
    int x=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='A') {
            //++hasa;
            x+=cntp[i];
        }
        if(s[i]=='T') {
           // if(hasa)
            total=((long long)total+x)%1000000007;//PPATTT (2+2+2)
            //x=0;
            //hasa=0;
        }
    }
/*³¬Ê±Ëã·¨*/
//     while(left < s.size()){
//         while(left < s.size() && s[left]!='P'){ left++;}
//         int next=++left;
//         while(next < s.size()){
//             while(next < s.size() && s[next]!='A'){ next++;}
//             if(next!=s.size()){
//                 if(cnt[s.size()-1]==cnt[next]) break;
//                 total=(total+cnt[s.size()-1]-cnt[next])%1000000007;
//                 ++next;
//             }
//         }
//     }
    cout<<total<<endl;
    return 0;
}
