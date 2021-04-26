#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include<iterator>
using namespace std;

struct Node{
    int key;
    int value;
    int freq;
    long long timestamp;
    bool operator<(const Node &b){
        if(freq != b.freq)
            return freq < b.freq;//计数少的在上面
        return timestamp < b.timestamp;//时间戳大的在上面
    }

};
class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        curtime = 0;
        minfreq = 0;
        key_table.clear();
        freq_table.clear();
    }
    
    int get(int key) {
        if (cap == 0) return -1;
        auto it = key_table.find(key);
        if (it == key_table.end()) return -1;
        list<Node>::iterator node = it -> second;
        int val = node -> val, freq = node -> freq;
        freq_table[freq].erase(node);
        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        // 插入到 freq + 1 中
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 缓存已满，需要进行删除操作
            if (key_table.size() == cap) {
                // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq);
                }
            } 
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            // 与 get 操作基本一致，除了需要更新缓存的值
            list<Node>::iterator node = it -> second;
            int freq = node -> freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) minfreq += 1;
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }

//private:
    int cap;
    long long curtime;
    int  minfreq;
    priority_queue<Node> pq;//淘汰
    //unordered_map<int, priority_queue<Node>::iterator> table;//查找表
    unordered_map<int, list<Node>::iterator> freq_table;//查找表
    unordered_map<int, list<Node>> key_table;
};

int main()
{
    return 0;
}
