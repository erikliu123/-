#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/*
给定一个任意序的正整数数组，对其顺序进行调整，使数组中每对相邻元素差值的绝对值和达到最大，并将此最大值返回。
比如输入数组为[ 5 20 60 30 10]，顺序可调整为[30 10 60 5 20]按这个排序后，可算出相邻元素差值的最大绝对值和为
30 - 10 + 60 - 10 + 60- 5 + 20 - 5= 140;
也可以调整为[20 5 60 10 30]，最大绝对值和为20 - 5 + 60 - 5 + 60 - 10 + 30 = 140
*/
class Solution {
public:
    int getSum(vector<int> &arr) {
        //f[0] = 1, f[1] = 1, f[2] = 2; f[3] = f[0] * f[2] +f [1] * f[1] +f[2] * f[0] 
        sort(arr.begin(), arr.end());
        vector<int> newArr;
        int left = 0, right = arr.size() - 2;
        if(arr.size() < 2)  
            return 0;
        newArr.push_back(arr.back());
        while(left <= right)
        {
            newArr.insert(newArr.begin(), arr[left++]);
            if(left <= right)
                newArr.insert(newArr.end(), arr[left++]);
            if(left <= right)
                newArr.insert(newArr.begin(), arr[right--]);
            if(left <= right)
                newArr.insert(newArr.end(), arr[right--]);
        }
        int ans = 0;
        for(int i=1; i<newArr.size(); i++)
        {
            ans += abs(newArr[i] - newArr[i-1]);
        }
        return ans;

    }
};

int main()
{
    Solution a;
    vector<int> vec{5,10,20,30,60};
    a.getSum(vec);
    return 0;
}
