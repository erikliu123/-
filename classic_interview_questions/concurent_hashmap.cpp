#include <iostream>
#include <vector>
#include <mutex>
#include <set>

template<typename K, typename V, typename Hash = std::hash<K>>
class ConcurrentHashMap : NonCopyable
{
public:
    ConcurrentHashMap(unsigned bucketNumber = kDefaultBucketNum, const Hash &hash = Hash())
    : table_(bucketNumber),
              hash_(hash)
    {
    }

    template<typename Predicate>
    bool for_one(const K &key, Predicate &p)
    {
       return table_[hashcode(key)].for_one(key, p);
    }

    template<typename Predicate>
    void for_each(Predicate &p)
    {
        for (auto &bucket : table_)
        {
            bucket.for_each(p);
        }
    }

    void insert(const K &key, V &&value)
    {
        table_[hashcode(key)].insert(key, std::move(value));
    }

    void put(const K &key, V &&value)
    {
        table_[hashcode(key)].put(key, std::move(value));
    }

    void erase(const K &key)
    {
        table_[hashcode(key)].erase(key);
    }

    std::size_t size() const
    {
        std::size_t size = 0;
        for (auto &bucket : table_)
        {
            size += bucket.size();
        }
        return size;
    }

    std::size_t count(const K &key) const
    {
        return table_[hashcode(key)].count(key);
    }

private:
    static const unsigned kDefaultBucketNum = 31;  //Prime Number is better

    class Bucket
    {
    public:
        void insert(const K &key, V &&value)
        {
            std::lock_guard<std::mutex> lock(mutex_);
            item_.emplace(key, std::move(value));
        }

        void put(const K &key, V &&value)
        {
            std::lock_guard<std::mutex> lock(mutex_);
            item_.erase(key);
            item_.emplace(key, std::move(value));
        }

        void erase(const K &key)
        {
            std::lock_guard<std::mutex> lock(mutex_);
            item_.erase(key);
        }

        template<typename Predicate>
        bool for_one(const K &key, Predicate &p)
        {
            std::lock_guard<std::mutex> lock(mutex_);
            const ConstIterator it = item_.find(key);
            return it == item_.end() ? false : (p(it->second), true);
        }

        template<typename Predicate>
        void for_each(Predicate &p)
        {
            std::lock_guard<std::mutex> lock(mutex_);
            std::for_each(item_.begin(), item_.end(), p);
        }

        std::size_t size() const
        {
            std::lock_guard<std::mutex> lock(mutex_);
            return item_.size();
        }

        std::size_t count(const K &key) const
        {
            std::lock_guard<std::mutex> lock(mutex_);
            return item_.count(key);
        }

    private:
        using Item = std::map<K, V>;
        using ConstIterator = typename Item::const_iterator;
        Item item_;
        mutable std::mutex mutex_;
    };

    inline std::size_t hashcode(const K &key)
    {
        return hash_(key) % table_.size();
    }

    std::vector<Bucket> table_;
    Hash hash_;
};

int main(){
    ConcurrentHashMap<int, int> myHash;
    myHash.insert(100, 1);
    std::mutex mtx;
    std::set<int> s;
    std::cout<<sizeof(mtx)<<"\t"<<sizeof(s)<<std::endl;
    //sizeof
    return 0;
}