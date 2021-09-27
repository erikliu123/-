#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <list>
#include <mutex>
#include <unistd.h>

using namespace std;
class A
{
public:
    //把收到的消息（玩家命令）送到一个队列中
    void inMsgRecvQueue()
    {
        for (int i = 0; i < 100; i++)
        {
            std::lock_guard<std::mutex> sbguard(my_mutex);
            cout << "inMsgRecvQueue() executed..." << endl;
            msgRecvQueue.push_back(i); //假设这个数字就是我收到的命令，我直接弄到消息队列里面去
            usleep(100);
        }
        return;
    }
    bool outMgLULProc(int &command)
    {

        //把数据从消息队列中取出线程：
        //NOTICE:lock_guard
        std::lock_guard<std::mutex> sbguard(my_mutex);
        //lock_guard构造函数里面执行了mutex::lock()
        //lock_guard析构函数里面执行了mutex::unlock()
        if (!msgRecvQueue.empty())
        {
            int command = msgRecvQueue.front(); //返回第一个元素，
            msgRecvQueue.pop_front();           //移除第一个元素，但不返回
            //这里就考虑处理数据

            return true;
        }

        return false;
    }
    //把数据从消息队列中取出线程：
    void outMsgRecvQueue()
    {
        int command = 0;
        usleep(200);
        for (int i = 0; i < 100; i++)
        {
            bool result = outMgLULProc(command);
            if (result == true)
            {
                cout << "outMsgRecvQueue() execute, extract the first one\n";
            }
            usleep(100);
        }
        cout << "end" << endl;
    }

    //这个就是共享数据
    std::list<int> msgRecvQueue; //容器，专门用于代表玩家给我们发送来的命令
    std::mutex my_mutex;         //创建一个my_mutex的锁
}; 
int main()
{

    A myobja;
    std::thread myOutMsg(&A::outMsgRecvQueue, &myobja); //第二个参数是 引用,才能保证线程用的是同一个对象这样能够避免多次复制
    std::thread myInMsg(&A::inMsgRecvQueue, &myobja);
    myOutMsg.join();
    myInMsg.join();
    return 0;
}