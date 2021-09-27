#include <iostream>
#include <functional>
//#include <bits/std_function.h>

using namespace std;
void print_num(int x)
{
    cout<<x<<"\t";
}
int main()
{
        int m = [](int x) { return [](int y) { return y * 2; }(x)+6; }(5);
        cout << "m:" << m << endl;            //输出m:16

        cout << "n:" << [](int x, int y) { return x + y; }(5, 4) << endl;            //输出n:9
        auto gFunc = [](int x)  { return [=](int y) { return x + y; }; };
        auto lFunc = gFunc(4);
        cout << lFunc(5) << endl;

        auto hFunc = [](const function<int(int)>& f, int z) { return f(z) + 1; };
        auto a = hFunc(gFunc(7), 8);
        cout<<"a:"<<a<<endl;

        int a1 = 111, b = 222;
        auto func = [=, &b]()mutable { a1 = 22; b = 333; cout << "a1:" << a1 << " b:" << b << endl; };

        func();
        cout << "a1:" << a1 << " b:" << b << endl;

        a = 333;
        auto func2 = [=, &a] { a = 444; cout << "a:" << a << " b:" << b << endl; };
        func2();

        auto func3 = [](int x) ->function<int(int)> { return [=](int y) { return x + y; }; };
        function<void(int)> f_display_42 = [](int x){print_num(x);};
        f_display_42(44);
        return 0;
}