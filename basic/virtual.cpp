#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

class A{
    virtual void print(){
        ;
    }
};
class B{

};
int main()
{
    cout<<sizeof(A)<<endl;
    cout<<sizeof(B)<<endl;
    return 0;

}

