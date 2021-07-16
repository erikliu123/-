#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
当小区通信设备上报告警时,系统会自动生成待处理的工单,华为工单调度系统需要根据不同的第略,调度外线工程师(FME) 上站去修复工单对应的问题。
根据与运营商签订的合同,不同严重程度的工单被处理并修复的时长要求不同,这个要求被修复的时长我们称之为SLA时间,假设华为和运营商A签订了运维
合同,部署了一套调度系统,只有1个外线工程师(FME)，每个工单根据问题严重程度会给一个评分,在SLA时间内完成修复的工单、华得工单评分对应的积分,
超过SLA完成的工单不获得积分，但必须完成该工单。运营商最终会根据积分进行付款。
请你设计种调度策略，根据现状得到调度结果完成所有工单，让这个外线工程师处理的工单获得的总积分最多。
假设从某个调度时刻开始,当前王单数量为N,不会产生新的工单,每个工单处理修复耗时为1小时,请设计你的调度策路,完成业务目标,
不考虑外线工程师在小区之间行驶的耗时。
假设有7个工单的SLA时间(小时)和积分如下:

7
1 6
1 7
3 2
3 1
2 4
2 5
6 1

答案: 
15, 依次选择1 7,2 5,3 2,6 1

*/
int n;
long long sum;
vector<pair<int, int>> a;

int main()
{

    scanf("%d", &n);
    a.push_back(make_pair(-1, -1));

    for (int i = 1; i <= n; i++)
    {
        int mid1, mid2;
        scanf("%d%d", &mid1, &mid2);
        a.push_back(make_pair(mid1, mid2));
    }

    sort(a.begin()+1, a.end());

    priority_queue<int, vector<int>, greater<int>> q;

    //丢下的要求最小,那么选择出来的数组和最大,
    //优先队列维护已经选择的元素,并且需要及时的弹出最小的,所以需要一个小根堆for(int i=1 ;
    //核心: 保存前i天的可进行任务对应的至多i个任务的最大值, (用小堆来存放)
    for (int i = 1; i <= n; i++)
    {
        if (q.size() < a[i].first)//比如[1,2] [5,1] [7,1], 显然5,1可以被加入
        {
            q.push(a[i].second);
        }
        else// 说明正在加入的元素需要竞争一个席位,因为优先队列保存的是前i天的可进行任务对应的至多i个任务
        //[1,2] [1,3] [2,4] [2,5] 应该选择的是[2,4] [2,5] 
        {
            if (q.top() < a[i].second)//如果最小值都比不过,不加入
            {
                q.pop();
                q.push(a[i].second);
            }
        }
    }
    sum = 0;
    while (q.size())
    {
        sum += q.top();
        q.pop();
    }

    cout << sum << endl;

    return 0;
    
}