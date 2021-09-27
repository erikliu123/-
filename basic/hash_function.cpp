
#include <iostream>
#include <vector>
#include <bits/stl_algo.h>
#include <unordered_set>
#include <bits/stream_iterator.h>

using namespace std;

//自定义哈希函数
struct pairhash{
    size_t operator() (const pair<int, int>& p) const {
        auto fn = hash<int>();
        return (fn(p.first) << 16) ^ fn(p.second);
    }
    //pairhash operator=(pairhash) 
};

unordered_set<pair<int, int>, pairhash> hashSetA;
int main()
{
    std::hash<float> hash_int;// Function object to hash int
    std::vector<int> vec{-5, -2, 2, 5, 10};
    //ostream_iterator tmp = ostream_iterator<int>(std::cout," ");
    std::transform(std::begin(vec), std::end(vec), ostream_iterator<int>(std::cout," \t"), hash_int);
    return 0;
}