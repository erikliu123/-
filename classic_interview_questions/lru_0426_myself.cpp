#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    int max_size;
    int elems;
    struct cache_line
    {
        //bool valid;//可以不要，一开始不要忘list中添加元素，通过哈希表的size判断即可
        int key, value;
        cache_line()
        {
            //valid = false;
        }
    };
    list<cache_line> cache_list;//Cache line
    //map<int, pair<int, cache_line*>> search;
    unordered_map<int, int> search;//unordered map消耗的空间会少，时间和map差不多
    LRUCache(int capacity) {
        //cache_line tmp;
        max_size = capacity;
        elems = 0;
        // for(int i=0; i<capacity; i++)
        // {
        //     cache_list.push_back(cache_line());
        // }

    }
    
    int get(int key) {
        if(search.find(key) != search.end()) {
            int res = search[key];
            //cache_list.erase(search[key].second);
            auto it =  cache_list.begin();
            for( ; it != cache_list.end(); it++)
            {
                if(it->key == key){
                    break;
                }
            }
            //NOTICE: 不要erase了后再令temp=*it，相当于野指针访问！
            cache_line temp=*it;
            cache_list.erase(it);
            cache_list.push_front(temp);
            return res;
            
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(search.find(key) != search.end()) {
            int res = search[key];
            search[key]=value;
            auto it =  cache_list.begin();
            for( ; it != cache_list.end(); it++)
            {
                if(it->key == key){
                    break;
                }
            }
            cache_line temp=*it;
            temp.value = value;
            cache_list.erase(it);
            cache_list.push_front(temp);
    
            return ;
        }
        if(cache_list.size() == max_size)
        {
            /*删除队尾的元素*/
            auto last = --cache_list.end();
            cache_line temp=*last;
            search.erase(temp.key);
            temp.key = key;
            temp.value = value;
            cache_list.erase(last);
            cache_list.push_front(temp);
            
        }
        else{
        
            cache_line temp;
            temp.key = key;
            temp.value = value;
            cache_list.push_front(temp);

        }
        search[key] = value;
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and ccache_listed as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
    LRUCache lru(2);
    lru.put(3, 1);

    lru.put(2, 1);
    lru.put(5, 2);
    lru.get(5);
    return 0;

}