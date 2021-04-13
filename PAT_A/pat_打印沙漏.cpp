#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include <unordered_map>
#include <cmath>

using namespace std;

int main()
{
    int n;
    char a;
    scanf("%d %c",&n,&a);
    int k=(int)sqrt(1.0*(n+1)/2); //k为正三角的高度
    for(int i=1; i<=k; i++)  //先输出倒三角 k行
    {
        for(int m=0; m<i-1; m++)
            printf(" ");
        for(int j=0; j<(k*2-i*2+1); j++)
            printf("%c",a);
        for(int m=0; m<i-1; m++)
            printf(" ");
        printf("\n");
    }
    for(int i=2; i<k; i++)  //输出正三角k-1行 最后一行单独输出 控制最后一行没有多的换行符输出
    {
        for(int m=0; m<k-i; m++)
            printf(" ");
        for(int j=0; j<(i*2-1); j++)
            printf("%c",a);
        for(int m=0; m<k-i; m++)
            printf(" ");
        printf("\n");
    }
    if((n-k*k*2+1)!=0)     //单独输出最后一行 若有多的符号 则换行输出多的符号数
    {
        for(int j=0; j<(k*2-1); j++)
            printf("%c",a);
        printf("\n");
        printf("%d",n-k*k*2+1);
    }
    else       //若没有多的符号 则直接输出最后一行 不换行
        for(int j=0; j<(k*2-1); j++)
            printf("%c",a);
    return 0;
}

