#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    //此方法超时!
    vector<string> findRepeatedDnaSequences(string s) {
        //KMP匹配
        set<string> ans;
        vector<string> vec;
        const int dest_len = 10;
        for(int i=0; i<(int)s.size()-dest_len; i++)
        {
            if(s.substr(i+1).find(s.substr(i, 10))!=string::npos)
            {
                ans.insert(s.substr(i, 10));      
            }

        }
        for(auto &x: ans)
            vec.push_back(x);
        return vec;
        

    }
};