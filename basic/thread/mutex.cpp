#include <iostream>
#include <string>
#include<thread>
#include<vector>
#include<list>
#include <mutex>

using namespace std;

//参考资料：https://zhuanlan.zhihu.com/p/76344819

class A {
public:
    //把收到的消息（玩家命令）送到一个队列中
    void inMsgRecvQueue() {
        for (int i = 0; i < 30; i++)
        {
            my_mutex.lock();
            cout << "inMsgRecvQueue()执行，插入一个元素" << endl;
            msgRecvQueue.push_back(i);//假设这个数字就是我收到的命令，我直接弄到消息队列里面去
            my_mutex.unlock();
        }
        return;
    }

    bool outMgLULProc(int& command) {
        my_mutex.lock();
        if (!msgRecvQueue.empty())
        {
            int command = msgRecvQueue.front();//返回第一个元素，
            msgRecvQueue.pop_front();//移除第一个元素，但不返回
            //这里就考虑处理数据
            my_mutex.unlock();
            return true;
        }
        //一定要记得两个地方都要unlock
        my_mutex.unlock();
        return false;
    }   
     //把数据从消息队列中取出线程：
    void outMsgRecvQueue() {
        int command = 0;
        for (int i = 0; i < 40; i++)
        {
            bool result = outMgLULProc(command);
            if (result == true)
            {
                cout << "outMsgRecvQueue()执行，取出一个元素";
            }
        }
        cout << "end" << endl;
    }
private:
    //这个就是共享数据
    std::list<int> msgRecvQueue;//容器，专门用于代表玩家给我们发送来的命令
    std::mutex my_mutex;//创建一个my_mutex的锁
};

int main() {

    A myobja;
    std::thread myOutMsg(&A::outMsgRecvQueue, &myobja);//第二个参数是 引用,才能保证线程用的是同一个对象这样能够避免多次复制
    std::thread myInMsg(&A::inMsgRecvQueue, &myobja);
    myOutMsg.join();
    myInMsg.join();    
    return 0;   
}