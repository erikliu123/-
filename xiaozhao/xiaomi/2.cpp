#include <iostream>
#include <algorithm>
#include <vector>
#include <ctype.h>

using namespace std;
//1A2C3D4E56 A1B2345C6D
//3 2 1 2 3 2 2 1 3
//3 3 2 2 1 2 2 2 2 2
int main()
{
    string str;
    while (getline(cin, str))
    {
        //
        vector<int> vec;
        for (auto x : str)
        {
            if (isdigit(x))
                vec.push_back(x - '0');
        }
        if (vec.size() == 0)
        {
            cout << "\n";
            return 0;
        }
        int left = 0, right = vec.size() - 1;
        while (left < right)
        {
            if (vec[left] == 1)
                ++left;
            else if (vec[left] == 3)
            {
                swap(vec[left], vec[right--]);
            }
            else
                ++left;
        }

        left = 0;
        while(right >=0 && vec[right]==3) --right;//NOTICE: 忽略此逻辑会导致如果没有1的时候有问题 （2会和3交换...） [2 2 2 3]
        while (left < right)
        {
            if (vec[left] == 1)
                ++left;
            else if (vec[left] == 2)// 
            {
                swap(vec[left], vec[right--]);
            }
            else
                ++left;
        }
        for (auto x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}