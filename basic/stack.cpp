
#include <iostream>
#include <array>
#include <vector>
#include <stack>

using namespace std;

int main()
{

    stack<int> in;
    in.push(20);
     cout<<in.peek()<<endl;
    cout<<in.top()<<endl;
    in.pop();

    return 0;
}