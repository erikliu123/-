#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> merge(string s)
    {
        vector<int> tmp;
        for(int i=0; i<s.size(); i++)
        {    
            if(!isdigit(s[i]))
            {
                vector<int> left = merge(s.substr(0, i));
                vector<int> right = merge(s.substr(i+1));
                for(auto x:left)
                {
                    for(auto y:right)
                    {
                        if(s[i] == '+') tmp.push_back(x+y);
                        if(s[i] == '-') tmp.push_back(x-y);
                        if(s[i] == '/') tmp.push_back(x/y);
                        if(s[i] == '*') tmp.push_back(x*y);

                    }
                }
            }
        }
        if(tmp.size() == 0) tmp.push_back(stoi(s));
        return tmp;
    }
    vector<int> diffWaysToCompute(string expression) {
        return merge(expression);

    }
};