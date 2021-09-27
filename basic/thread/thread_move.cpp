#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

class Fctor {
public:
    void operator()(std::string& msg) {
        std::cout << "from t1: " << msg << std::endl;
        msg = "I love you ";
    }
};

int main() {
    std::string s = "I LOVE YOU";
    std::cout << "Thread1 id: " << std::this_thread::get_id() << std::endl;
    std::thread t1(Fctor(), std::ref(s));//不能写成std::thread t1(Fctor(s))

    std::thread t2 = std::move(t1);
    std::cout << "Thread2 id: " << t2.get_id() << std::endl;//输出线程id
    cout<<"hardware concurrency: "<<t2.hardware_concurrency()<<endl;

    t2.join();
    std::cout << s << std::endl;//如果是引用传递的话，这里值应该是 “进入值传递中”
    return 0;

}