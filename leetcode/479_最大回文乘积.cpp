#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        int hi = pow(10, n)-1, low = pow(10, n-1);
        if(n == 1) return 9;
        for(int i=hi; i>low; i--)
        {
            string str=to_string(i);
            string s2(str.rbegin(), str.rend());
            long long  mult = stoll(str+s2);
            for(long long k=hi; k*k>=mult; k--)
            {
                if(mult % k ==0) return mult%1337;
            }

        }
        return 0;


    }
};