#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mymap;
        vector<vector<string>> ans;
        for(int i=0; i<strs.size(); i++)
        {
            string temp=strs[i];
            sort(temp.begin(), temp.end());
            mymap[temp].push_back(strs[i]);
        }
        for(auto it=mymap.begin(); it!=mymap.end(); it++){
            ans.push_back(it->second);
        }
        return ans;

    }
    // vector<vector<string>> groupAnagrams(vector<string>& strs)
    // {
    //     map<string, vector<string>>


    // }
};