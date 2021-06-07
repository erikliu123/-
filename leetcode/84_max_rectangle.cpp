#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
/*
题目描述：
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

输入: [2,1,5,6,2,3]
输出: 10
*/
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> elems;
        //vector<int> copy_temp;
        int max_area=0;
        
        heights.insert(heights.begin(), 0);
        heights.insert(heights.end(), 0);//确保遍历完最后一个数组元素后，可以出栈检查
        elems.push(0);
        for(int i=1; i<heights.size(); i++)
        {
            while( heights[elems.top()] > heights[i]){//NOTICE: 可以不用判断栈为空，即使是heights全0也不会导致栈空！ while(!elems.empty() && heights[elems.top()] > heights[i])
                int curheight=heights[elems.top()];
                elems.pop();
                //cout<<"size: "<<elems.size()<<endl;
                //if(!elems.empty())
                    max_area=max(max_area, curheight*(i-1-elems.top()));
               // else
                   // max_area=max(max_area, curheight*i);
                // cout<<max_area<<endl;
            }
            elems.push(i);//NOTICE: 是push下标不是heights[i]!!!
        }

        return max_area;
#ifdef CLUMSY_WAY
        //普适粗糙的一种写法
        for(int i=0; i<heights.size(); i++)
        {
            while(!elems.empty() && heights[elems.top()] > heights[i]){
                //
                int curheight=heights[elems.top()];
                elems.pop();
                cout<<"size: "<<elems.size()<<endl;
                if(!elems.empty())
                    max_area=max(max_area, curheight*(i-1-elems.top()));
                else
                    max_area=max(max_area, curheight*i);
               // cout<<max_area<<endl;
            }
          
            elems.push(i);//是push下标不是heights[i]!!!
        }
        int i=heights.size();
        while(!elems.empty()){
            //
            int curheight=heights[elems.top()];
            elems.pop();
            if(!elems.empty())
                max_area=max(max_area, curheight*(i-1-elems.top()));
            else
                max_area=max(max_area, curheight*i);
        }

        return max_area;
#endif

    }
};

int main()
{
    vector<int> height{2,1,5,6,2,3};
    Solution a;
    auto it=a.largestRectangleArea(height);
    cout<<it<<endl;
    return 0;
}