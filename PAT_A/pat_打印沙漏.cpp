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
    int k=(int)sqrt(1.0*(n+1)/2); //kΪ�����ǵĸ߶�
    for(int i=1; i<=k; i++)  //����������� k��
    {
        for(int m=0; m<i-1; m++)
            printf(" ");
        for(int j=0; j<(k*2-i*2+1); j++)
            printf("%c",a);
        for(int m=0; m<i-1; m++)
            printf(" ");
        printf("\n");
    }
    for(int i=2; i<k; i++)  //���������k-1�� ���һ�е������ �������һ��û�ж�Ļ��з����
    {
        for(int m=0; m<k-i; m++)
            printf(" ");
        for(int j=0; j<(i*2-1); j++)
            printf("%c",a);
        for(int m=0; m<k-i; m++)
            printf(" ");
        printf("\n");
    }
    if((n-k*k*2+1)!=0)     //����������һ�� ���ж�ķ��� ���������ķ�����
    {
        for(int j=0; j<(k*2-1); j++)
            printf("%c",a);
        printf("\n");
        printf("%d",n-k*k*2+1);
    }
    else       //��û�ж�ķ��� ��ֱ��������һ�� ������
        for(int j=0; j<(k*2-1); j++)
            printf("%c",a);
    return 0;
}

