#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

/*
2013. 检测正方形
给你一个在 X-Y 平面上的点构成的数据流。设计一个满足下述要求的算法：

添加 一个在数据流中的新点到某个数据结构中。可以添加 重复 的点，并会视作不同的点进行处理。
给你一个查询点，请你从数据结构中选出三个点，使这三个点和查询点一同构成一个 面积为正 的 轴对齐正方形 ，统计 满足该要求的方案数目。
轴对齐正方形 是一个正方形，除四条边长度相同外，还满足每条边都与 x-轴 或 y-轴 平行或垂直。

实现 DetectSquares 类：

DetectSquares() 使用空数据结构初始化对象
void add(int[] point) 向数据结构添加一个新的点 point = [x, y]
int count(int[] point) 统计按上述方式与点 point = [x, y] 共同构造 轴对齐正方形 的方案数。
*/
class DetectSquares {
public:
    vector<pair<int, int>> mPoint;
    unordered_map<int, map<int, int>> mX, mY;
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        mX[point[0]][point[1]]++;//横坐标到纵坐标
        mY[point[1]][point[0]]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        /* +表示point, 123表示选点的顺序
            2    +

            3    1
        */
        for(auto x: mX[point[0]])//横坐标相等，选1
        {
            int absY = abs(x.first - point[1]);//
            if(absY == 0)
                continue;
            //找纵坐标有没有相等的
            for(int i=0; i<2; i++){
                int heng = point[0] + absY;
                if(mY.count(point[1]) && mY[point[1]].count(heng))//找到点2
                {
                    if(mX.count(heng) && mX[heng].count(x.first))//找到点3
                    {
                        ans += x.second * mX[heng][x.first] * mX[heng][point[1]];
                    }

                }
                absY *= -1;
            }
        }
        return ans;

    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */