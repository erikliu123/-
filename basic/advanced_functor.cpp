#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

class CompareObject{
public:
    void operator()(){
        cout << "fanghanshu" << endl;
    }

    void operator()(int number,int number2){
        cout << "fanghanshu2" << endl;
    }
};

// 查看c++ for_each源码自定义
class ShowActionObj{
public:
    void operator()(int content){
        //next = 100;
        cout << "custom fanghanshu" << content << endl;
    }
};
// 回调方式
void showAction(int content){
    cout << "custom yiyuanweici" << content << endl;

}

int main(){

    // 谓词 == 仿函数

    CompareObject fun1;

    fun1();


    set<int> setVar;
    setVar.insert(10);
    setVar.insert(20);
    setVar.insert(30);
    setVar.insert(40);
    setVar.insert(50);
    setVar.insert(60);

    for_each(setVar.begin(),setVar.end(),ShowActionObj());
    cout << "---" << endl;
    for_each(setVar.begin(),setVar.end(),showAction);

    return 0;
}