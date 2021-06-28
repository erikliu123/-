#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3) return 0;
        stack<int> stack;
        //pos.push(0);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            while( !stack.empty() && height[i] > height[stack.top()])
            {
                int top_index = stack.top();
                stack.pop();
                if(!stack.empty())
                {
                    ans = ans + (i-stack.top()-1)*(min(height[i], height[stack.top()]) - height[top_index]);
                    //cout<<ans<<endl;
                }
              

            }
            stack.push(i);
            
        }
        return ans;


    }
};