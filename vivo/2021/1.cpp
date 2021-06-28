/*
一个完整的软件项目往往会包含很多由代码和文档组成的源文件。编译器在编译整个项目的时候，可能需要按照依赖关系来依次编译每个源文件。
比如，A.cpp 依赖 B.cpp，那么在编译的时候，编译器需要先编译 B.cpp，才能再编译 A.cpp。 假设现有 0，1，2，3 四个文件，0号文件依赖1号文件，
1号文件依赖2号文件，3号文件依赖1号文件，则源文件的编译顺序为 2,1,0,3 或 2,1,3,0。现给出文件依赖关系，如 1,2,-1,1，表示0号文件依赖1号文件，
1号文件依赖2号文件，2号文件没有依赖，3号文件依赖1号文件。请补充完整程序，返回正确的编译顺序。注意如有同时可以编译多个文件的情况，按数字升序
返回一种情况即可，比如前述案例输出为：2,1,0,3
*/

//"1,2,-1,1"
//"2,1,0,3"

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 编译顺序
     * @param input string字符串 
     * @return string字符串
     */
    map<int, vector<int> > edge; 
    vector<int> record;
    void dfs(int start)
    {
        record.push_back(start);
        for(auto x: edge[start]){
            dfs(x);
        }
    }
    string compileSeq(string input) {
        // write code here
        int num=0;
        string ans;
        vector<bool> visited;
        int nega = 1;
        int snum = 0;
        map<int, int> fa; //child's father
        priority_queue<int, vector<int>, greater<int>> next;//
        edge.clear();
        record.clear();
        if(input.size() == 0) return "";
        for(auto x: input)
        {
            if(x==',') {
                fa[num] = snum * nega;
                if(nega > 0){
                    edge[snum].push_back(num);
                }
                ++num;
                nega = 1;
                snum = 0;
            }
            else if(x=='-'){
                nega = -1;
            }
            else{
                snum = snum * 10 + x -'0';
            }
        }
        fa[num] = snum * nega;
        if(nega > 0){
            edge[snum].push_back(num);
        }
        for(auto x:fa)
        {
            if(x.second == -1){
                //dfs(x.first);//注意如有同时可以编译多个文件的情况，按数字升序返回一种
                next.push(x.first);
                while(next.size() > 0)
                {
                    int x = next.top();
                    next.pop();
                    record.push_back(x);
                    for(auto w:edge[x]){
                        next.push(w);
                    }
                }
            }
        }
        if(record.size() >= 1){
            ans = to_string(record[0]);
        }
 
        for(int i=1; i<record.size(); i++)
        {
            ans += ",";
            ans += to_string(record[i]);
        }
        return ans;



    }
};

int main()
{
    Solution a;
    string test="8,2,7,4,6,-1,5,5,6";
    a.compileSeq(test);

    return 0;
}