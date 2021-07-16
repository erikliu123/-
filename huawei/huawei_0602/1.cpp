#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct myrank{
    int start, len;
    bool operator<(const myrank &b) const{
        if(len != b.len) return len > b.len;
        return start<b.start;
    }
};
int main()
{
    string str, ans;
    vector<myrank> all;
    cin >> str;
    int n=str.size();
    //找到最长子串
    for(int len=2; len<=n/2; len++)
    {
        for(int i=0; i<n-len; i++)
        {
            if(str.substr(i, len) == str.substr(i+len, len))
            {
                myrank s;
                s.len = len;
                s.start = i;
                all.push_back(s);

            }
        }
    }
    sort(all.begin(), all.end());
    //压缩
    for(auto &i: all)
    {
        int cnt = 2;
        
        int len = i.len;
        //
        bool flag = false;
       
        for(int k=i.start+1; k<i.start+len; ++k){
            if(str[k] != str[k-1]) {
                flag = true;
                break;
            }
        }
        if(!flag) continue;//same alphabets "aaaaaa"
        int sublen = len;
        while(sublen%2 == 0)
        {
            if(str.substr(i.start, sublen/2) != str.substr(i.start+sublen/2, sublen/2)) 
                break;
            sublen/=2;
            cnt *= 2;
        }
        i.len = sublen;
       
        for(int k=i.start+len; k<n-len; k+=len){
             if(str.substr(k, len) == str.substr(k+len, len)) ++cnt;
             break;
        }
        int k;
        if(!islower(str[i.start]))//"A" OR "123" 
            continue;
        for(k=i.start; k<i.start + i.len && islower(str[k]); k++)
        {
            str[k] ^= 32;//变成大写字母
        }
        int start=k;
        int ncnt =cnt;
        while(cnt){
            str[k++]= cnt%10+'0';
            cnt/=10;
        }
        reverse(str.begin()+start, str.begin()+k-1);
        for(; k<i.start + ncnt*i.len; ++k)
        {
            str[k] = '*';
        }
        
    }
    int cnt = 1;
    for(int i=1; i<=n; i++)
    {
        if(i==n || islower(str[i])){
            if(i!=n && str[i]==str[i-1])
                cnt ++;
            else {
                if(cnt > 2){
                    int start = i-cnt+1, end = start;
                    while(cnt){
                        str[end++]= cnt%10+'0';
                        cnt/=10;
                    }
                    for(; end < i; end++) str[end] = '*';
                    reverse(str.begin()+start, str.begin()+end);
                }
                cnt = 1;

            }
        }
        else{
             if(cnt > 2){
                    int start = i-cnt+1, end = start;
                    while(cnt){
                        str[end++]= cnt%10+'0';
                        cnt/=10;
                    }
                    for(; end < i; end++) str[end] = '*';
                    reverse(str.begin()+start, str.begin()+end);
            }
            cnt = 1;
            
        }
        
    }
    for(auto i=str.begin(); i!=str.end(); ){
        if(*i == '*')  str.erase(i);
        else i++;
    }
    cout<<str<<endl;
    return 0;
    

}
