#include<iostream>
#include<cstdio>

using namespace std;
//笔试题测试
class A
{
    public:
    A()
    {
        cout<<"A"<<endl;
    }
    A(const string a)
    {
        cout<<a<<endl;
    }
};

class EmptyWithVirtual
{
    virtual void func()
    {
        ;
    }
};
class B
{
    public:
    B(string tmp):d("d"), c("c"), b("b")//还有拷贝操作
    {
        a = A(tmp);//只跟成员定义的顺序有关，初始化列表不一定会马上初始化...(cache hit的考量)

    }
    A a,b,c,d;
};

class C
{

};
int main()
{
    
    B b("a"); //
    cout<<sizeof(EmptyWithVirtual)<<endl;
    printf("%d\n", static_cast<char>(sizeof(C) + 182));
    return 0;
}