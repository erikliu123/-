#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
    vector<bool> visited;
    unordered_map<string, int> map_point;
    unordered_map<int, string> reverse_map;
    map<int, vector<int>> edge;
    set<vector<string>> ways;
    void dfs(vector<vector<string>>& tickets, int start, int steps, vector<string> &tmp)
    {
        visited[start] = true;
        tmp.push_back(reverse_map[start]);
        //++steps;
        if(steps >= tickets.size())
        {
            ways.insert(tmp);
            //cout<<"find one"<<endl;
        }
        else{
            for(int i=0; i<edge[start].size(); i++)
            {
                //if(!visited[edge[start][i]])
                //{
                    dfs(tickets, edge[start][i], steps+1, tmp);
                //}
            } 

        }
        tmp.pop_back();
        visited[start] = false;
    }
    /*
[["AXA","EZE"],["EZE","AUA"],["ADL","JFK"],["ADL","TIA"],["AUA","AXA"],["EZE","TIA"],["EZE","TIA"],["AXA","EZE"],["EZE","ADL"],["ANU","EZE"],["TIA","EZE"],["JFK","ADL"],["AUA","JFK"],["JFK","EZE"],["EZE","ANU"],["ADL","AUA"],["ANU","AXA"],["AXA","ADL"],["AUA","JFK"],["EZE","ADL"],["ANU","TIA"],["AUA","JFK"],["TIA","JFK"],["EZE","AUA"],["AXA","EZE"],["AUA","ANU"],["ADL","AXA"],["EZE","ADL"],["AUA","ANU"],["AXA","EZE"],["TIA","AUA"],["AXA","EZE"],["AUA","SYD"],["ADL","JFK"],["EZE","AUA"],["ADL","ANU"],["AUA","TIA"],["ADL","EZE"],["TIA","JFK"],["AXA","ANU"],["JFK","AXA"],["JFK","ADL"],["ADL","EZE"],["AXA","TIA"],["JFK","AUA"],["ADL","EZE"],["JFK","ADL"],["ADL","AXA"],["TIA","AUA"],["AXA","JFK"],["ADL","AUA"],["TIA","JFK"],["JFK","ADL"],["JFK","ADL"],["ANU","AXA"],["TIA","AXA"],["EZE","JFK"],["EZE","AXA"],["ADL","TIA"],["JFK","AUA"],["TIA","EZE"],["EZE","ADL"],["JFK","ANU"],["TIA","AUA"],["EZE","ADL"],["ADL","JFK"],["ANU","AXA"],["AUA","AXA"],["ANU","EZE"],["ADL","AXA"],["ANU","AXA"],["TIA","ADL"],["JFK","ADL"],["JFK","TIA"],["AUA","ADL"],["AUA","TIA"],["TIA","JFK"],["EZE","JFK"],["AUA","ADL"],["ADL","AUA"],["EZE","ANU"],["ADL","ANU"],["AUA","AXA"],["AXA","TIA"],["AXA","TIA"],["ADL","AXA"],["EZE","AXA"],["AXA","JFK"],["JFK","AUA"],["ANU","ADL"],["AXA","TIA"],["ANU","AUA"],["JFK","EZE"],["AXA","ADL"],["TIA","EZE"],["JFK","AXA"],["AXA","ADL"],["EZE","AUA"],["AXA","ANU"],["ADL","EZE"],["AUA","EZE"]]
    */
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        visited = vector<bool>(tickets.size(), false);
        int i = 0;
        ways.clear();
        map_point.clear();
        reverse_map.clear();

        map_point["JFK"] = 0;
        reverse_map[0] = "JFK";
        int start = 0;
        for(auto &x:tickets)
        {
            if(map_point.find(x[0]) == map_point.end())
            {
                map_point[x[0]] = ++start;
                reverse_map[start] = x[0];

            }
            if(map_point.find(x[1]) == map_point.end())
            {
                map_point[x[1]] = ++start;
                reverse_map[start] = x[1];

            }
        }
        for(auto &x:tickets){
            edge[map_point[x[0]]].push_back(map_point[x[1]]);
        }
        vector<string> tmp;
        //tmp.push_back("JFK");
        dfs(tickets, 0, 0, tmp);
            
        return *(ways.begin());
    }
};


int main()
{
    Solution a;
    vector<vector<string>> str;
    str.push_back(vector<string>{"JFK","SFO"});
    str.push_back(vector<string>{"JFK","ATL"});
    str.push_back(vector<string>{"SFO","ATL"});
    str.push_back(vector<string>{"ATL","JFK"});
    str.push_back(vector<string>{"ATL","SFO"});
    a.findItinerary(str);
    return 0;
}