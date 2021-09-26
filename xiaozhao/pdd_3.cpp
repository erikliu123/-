#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/*
多多君最近在研究无限数字集合,其中一种生成无限数字集合的方式是:
1.初始状态集合中只有一个种子元素A。
2.对于集合中的每个元素X,有X+B也属于该集合。
3.对于集合中的每个元素X,有X*C也属于该集合。

多多君想知道，对于给定的参数A、B和C,数字Q是否属于该集合。
*/
//因为Q=a*C^x + b*C^y;
bool isValid(int a, int b, int c, int target)
{
    int x = a;
    while(target -x >= 0)
    {
        if((target - x)%b == 0)   return true;
        if(x <= INT_MAX/c)
            x=x*c;
        else break;
    }
    return false;
}
int main(){
    int T,A,B,C;
    cin>>T;
    //T=100;
    for(int i=0; i<T; i++)
    {
        int num;
        cin>>A>>B>>C>>num;
        if(num < A) cout<<"0"<<endl;
        else if(C==1) cout<<((num-A)%B==0)<<endl;
        else{
            cout<<isValid(A,B,C,num)<<endl;
        }
    }
    return 0;
}