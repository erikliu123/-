#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0, j = 0;
        int carry = 0;
        string res;
        while (i < a.size() || j < b.size() || carry)
        {
            int mid = 0, mid1 = 0;
            if (i < a.size())
                mid = a[i++] - '0';
            if (j < b.size())
                mid1 = b[j++] - '0';

            int sum = mid + mid1 + carry;
            res += '0' + sum % 2;
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};