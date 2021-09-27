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
            std::unique_lock<std::mutex> uniqLock(my_mutex);
            cout << "inMsgRecvQueue() executed..." << endl;
            msgRecvQueue.push_back(i);
            uniqLock.unlock();//提前释放锁，减少锁的覆盖区间
            usleep(100);
        }
        return;
    }
    bool outMgLULProc(int &command)
    {

        std::unique_lock<std::mutex> uniqLock(my_mutex);
        if (!msgRecvQueue.empty())
        {
            int command = msgRecvQueue.front(); 
            msgRecvQueue.pop_front();        
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
    std::list<int> msgRecvQueue; 
    std::mutex my_mutex;         
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