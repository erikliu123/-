#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <cctype>
#include <unordered_map>

using namespace std;

const int maxn=100010;

int main()
{
    char a[maxn],p[maxn]= {},t[maxn]= {};
    scanf("%s",a);
    int n=strlen(a);
    int pc=0,tc=0;
    int count=0;
    for(int i=0,j=n-1; i<n,j>=0; i++,j--)
    {
        if(a[i]=='P')
        {
            pc++;
        }
        if(a[j]=='T')
        {
            tc++;
        }
        if(a[i]=='A')
        {
            p[i]=pc;
        }
        if(a[j]=='A')
        {
            t[j]=tc;
        }
    }
    for(int i=0; i<n; i++)
        if(a[i]=='A')
            count=(count + (long long)p[i]*t[i])%1000000007;
    printf("%d",count%1000000007);
    return 0;
}
