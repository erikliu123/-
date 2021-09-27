#include <iostream>
#include <thread>
#include <mutex>
#include <stack>

using namespace std;
static int g_var=0;
void func1()
{
    cout<<"thank you"<<endl;
    int a=100;
    a= (1123*122)%666;
    return ;
}

void condition_v()
{
    mutex a;
    a.lock();

    g_var ++;
    a.unlock();

}


int main()
{
    thread a1(func1);
    a1.join();

    // thread temp[10];
    // for(int i=0; i<10; i++)
    // {
    //     temp[i] = thread(condition_v)
    // }
    return 0;
}