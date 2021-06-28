#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;


int main()
{
    int ans = 0;
    string str;
    getline(cin, str);
    str += " ";
    string id;
    bool has_seven = false;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == '\n' || str[i] == ' ')
        {
            if(has_seven)
                ++ans;
            else if((stoi(id) % 7) == 0){
                ++ans;
            }
            has_seven = false;
            id = "";
        }
        else{
            if(str[i] == '7') has_seven = true;
            id = id + str[i];
        }


    }
    cout<<ans<<endl;

    return 0;
}