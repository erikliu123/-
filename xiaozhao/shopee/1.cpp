#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//123456 -> 123,456
int main(){
    long long num;
    cin>>num;
    string s = to_string(num);
    int cnt = 0;
    string ans = s;
    for(int i=s.size()-1; i>=0; i--)
    {
        cnt++;
        if(cnt % 3 == 0 && i!=0)
        {
            ans.insert(ans.begin() + i, ',');

        }
    }
    cout<<ans<<endl;
    
    return 0;
}