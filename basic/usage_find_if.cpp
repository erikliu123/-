#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
/*find_if的使用*/
int main()
{
    vector<int> total{1,2,3,6,7,8};
    auto index=find_if(total.begin(), total.end(), bind2nd(greater<int>(), 5));
    cout<<*index<<endl;
    index=find_if(total.begin(), total.end(), bind2nd(greater_equal<int>(), 8));
    cout<<*index<<endl;
    return 0;
}