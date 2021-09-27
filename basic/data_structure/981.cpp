#include <iostream>
#include <map>
using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    //map<string, map<int, string, cmp>> 
    map<string, map<int, string, greater<int>>> time_maper;//key -> [time, string]
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        time_maper[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = time_maper.find(key);
        if(it == time_maper.end()){
            return "";
        }
        auto ans = it->second.lower_bound(timestamp);//找到其下边界即可
        return ans->second;
        
        int x = it->second.begin()->first;
       // x = 100000000 - x;
        if(x <= timestamp)
            return it->second.begin()->second;
        else
            return it->second[timestamp];

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main()
{
    string key="liu", value = "jiahong";
    int timestamp = 2;
    TimeMap* obj = new TimeMap();
    obj->set(key,value,timestamp);
    string param_2 = obj->get(key,timestamp);
    return 0;
}