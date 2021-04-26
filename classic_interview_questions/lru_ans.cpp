#include <unordered_map>
#include <list>
#include <vector>
using namespace std;
struct Node
{
    Node(int k = 0, int v = 0) : key(k), val(v) {}
    int key;
    int val;
};
class LRUCache
{
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int>> &operators, int k)
    {
        // write code here
        cap = k;
        vector<int> ans;
        for (auto &input : operators)
        {
            if (input[0] == 1)
            {
                put(input[1], input[2]);
            }
            else
            {
                ans.push_back(get(input[1]));
            }
        }
        return ans;
    }
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    //删除
    int remove(list<Node>::iterator &ite)//删除list的尾部元素，同时删除哈希表中的元素
    {
        int key = ite->key;
        int val = ite->val;
        L.erase(ite);
        H.erase(key);
        return val;
    }
    // 添加
    void add(int key, int val)
    {
        L.push_front(Node(key, val));
        H[key] = L.begin();
        if (L.size() > cap)
        {
            auto last = L.end();
            --last;
            remove(last);
        }
    }
    void put(int x, int y)
    {
        auto ite = H.find(x);
        //已经存在，删除了再添加到头部
        if (ite != H.end())
            remove(ite->second);
        {
        }
        add(x, y);
    }
    int get(int x)
    {
        int val = 0;
        //已经存在，删除了再添加到头部
        auto ite = H.find(x);
        if (ite != H.end())
        {
            val = remove(ite->second);
            add(x, val);
            return val;
        }
        return -1;
    }
 
private:
    list<Node> L;
    unordered_map<int, list<Node>::iterator> H;
    int cap;
};