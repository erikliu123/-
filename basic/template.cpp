#include <iostream>
#include <string>
#include <queue>
template<typename T, T... Elements> class Foo0 {};
template<auto... VS> class Foo1 { };
template<auto V1, decltype(V1)... VS> class Foo2 { };

namespace gdwg {
	template <class N, class E>
	class graph {
	public:
		struct value_type {
			N from;
			N to;
			E weight;
		};

		// Your member functions go here
	private:
	};
} // namespace gdwg

//联合体不能定义string
// union test
// {
//     std::string a;
//     //int b;
// };


int main(){
    //匿名union
    // union {
    //         char cval;
    //         int ival;
    //         double dval;
    //         std::string sval;
    // };
    std::queue<int> q; 
    gdwg::graph<std::string, int> x;
    //Foo0<1, 'a', true> vals1;
    Foo0<int, 1, 2, 3> vals2;
    //Foo0<> vals3;
    Foo1<1, 2, 3> vals4;
    Foo1<1, 'a', true> vals5;
    Foo1<> vals6;
    //Foo2<> vals7;
    Foo2<1, 'a', true> vals8;
    Foo2<1, 2, 3> vals9;

    
    return 0;
}