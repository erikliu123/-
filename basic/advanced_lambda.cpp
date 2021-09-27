#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<bits/stream_iterator.h>
using namespace std;

template <
    class InputIterator, class OutputIterator, 
    class UnaryOperator, class Pred
>
OutputIterator transform_if(InputIterator first1, InputIterator last1,
                            OutputIterator result, UnaryOperator op, Pred pred)
{
    /*
    [&](int i){ return  i > 5; },
        [&](int){ return index-1; });
    */
    InputIterator it = first1;
    int i=0;
    while (first1 != last1) 
    {

        if (op(*first1)) {// x > 5?
            cout<<"xxx:"<<*first1<<endl;
            *result = i;
            ++result;
        }
        ++first1;
        ++i;
    }
    return result;
}
/*  目标：找到x中大于5对应的下标  */
int main(){
    
    std::vector<int> x{3, 2, 5, 8, 2, 1, 10, 4, 7};
    std::vector<size_t> result;

    //法1
    //auto it = std::find_if(std::begin(x), std::end(x), [](int i){return i > 5;});
    auto it = x.begin();
    while (it != std::end(x)) {
       
        it = std::find_if(std::next(it), std::end(x), [](int i){return i > 5;});
        if(it != x.end())
        {
             result.emplace_back(std::distance(std::begin(x), it));
        }
    }
    //法2：
    std::vector<size_t> y(x.size());
    std::iota(y.begin(), y.end(), 0);
    
    std::copy_if(y.begin(), y.end(),
                std::ostream_iterator<size_t>(std::cout," "),
                [&](size_t i) { return x[i] > 5; });
    
    //法3
    size_t index = 0;
    vector<size_t> indices;
    transform_if(x.begin(), x.end(), std::back_inserter(indices),
        [&](int i){ return i > 5; },
        [&](int){ return index-1; });

    std::copy(indices.begin(), indices.end(),
              std::ostream_iterator<size_t>(std::cout," "));
    return 0;
}

