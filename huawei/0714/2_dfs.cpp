#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int result = 0;
//通过85%
void dfs(vector<int> &num)
{
    int l=0, r=0;
    while (l<num.size())
    {
        if(num[l] > 0)
            break;
        ++l;
    }
    r = l;
    while (r<num.size())
    {
        if(num[r] == 0)
            break;
        ++r;
    }
    if(l < num.size())
    {
        for(int i=l; i<r; i++)
        {
            num[i]--;
        }
        result++;
        dfs(num);

    }
}
int main()
{
    vector<int> box;
    string input;
    getline(cin, input);
    int num = 0;
   // box.push_back(0);
    for(int i = 0; i<input.size(); i++)
    {
        if(isdigit(input[i]))
        {
            num = num*10 + input[i]-'0';
        }
        else if(input[i]==' '){
            box.push_back(num);
            num = 0;
        }
        else{
            cout<<-1<<endl;
            return 0;
        }
    }
    box.push_back(num);
    // box.push_back(0);

    //
    int n = box.size();
    vector<int> shun(n, 0), ni(n, 0);

    dfs(box);
    cout<<result<<endl;
    
    
    return 0;
}