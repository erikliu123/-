#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;


int main()
{
    vector<int> box;
    string input;
    getline(cin, input);
    int num = 0;
    int ans = 0;
    box.push_back(0);
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
    
    //
    int n = box.size();
    
    for(int i=1; i<n; i++)
    {
        if(box[i] > box[i-1])
        {
            ans += (box[i] - box[i-1]);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}