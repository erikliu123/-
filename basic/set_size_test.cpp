
#include <iostream>
#include <vector>
#include <mutex>
#include <set>


int main(){
    std::mutex mtx;
    std::set<int> testSet;
    std::cout<<sizeof(mtx)<<"\t"<<sizeof(testSet)<<std::endl;
    //sizeof
    return 0;
}