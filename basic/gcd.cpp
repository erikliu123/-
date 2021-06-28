
#include <iostream>
#include <queue>

using namespace std;
int xGCD(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int x1, y1, gcd = xGCD(b,a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main()
{

    int x,y;
    int gcd = xGCD(100,15,x,y);
    cout<<gcd<<endl;
    cout<<x<<"\t"<<y<<endl;
    return 0;
}