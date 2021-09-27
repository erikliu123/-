#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;
class LRUCache {
    list<pair<int, int>> mList;
    unordered_map<int, list<pair<int, int>>::iterator> mMap;//key 指向 链表结点以便进行value的查询
    int cap;
public:
    
    LRUCache(int capacity) {
        //记录key, value
        cap = capacity;
        mMap = unordered_map<int, list<pair<int, int>>::iterator>(100010);
    }
    
    int get(int key) {
        auto it = mMap.find(key);
        if(it != mMap.end())
        {
            auto y = *(it->second);
            mList.erase(it->second);
            mList.push_front(y);
            mMap[key] = mList.begin();
            return y.second;

        }
        else{
            return -1;
        }

    }
    
    void put(int key, int value) {
        auto it = mMap.find(key);
        if(it != mMap.end())
        {   
            auto y = *it;
            mMap.erase(it);
            mList.erase(y.second);

        }
        else{
            if(mList.size() == cap)//淘汰最后一个元素
            {
                auto x = mList.back();
                mMap.erase(x.first);
                mList.pop_back();
            }

        }
        mList.push_front(make_pair(key, value));
        mMap[key] = mList.begin();

    }
};
