#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<int, vector<int>> edge2, edge;
  vector<int> time_array;
int record[10000];
bool visited[10000];
int dfs(int start)
{
    int tmp = time_array[start];
    if(visited[start]) 
        return record[start];
    record[start] = tmp;
    for(int  i=0; i<edge[start].size(); i++)
    {
        if(edge[start][i] > 0)
        record[start] = max(record[start], tmp + dfs(edge[start][i]));
    }
    visited[start] = true;
    return record[start];
}

int main()
{
    string str;
  
    cin>>str;
    int num = 0;
    time_array.push_back(0);
    for(int i =0; i<str.size(); i++)
    {
        if(str[i] == ','){
            time_array.push_back(num);
            num = 0;
        }
        else{
            num = num*10 + str[i]-'0';
        }
    }
    time_array.push_back(num);
    cin>>str;
    vector<int> tmp;
    int index = 1;//NOTICE: 
    num = 0;
    for(int i =0; i<str.size(); i++)
    {
        if(str[i] == ','){
            tmp.push_back(num);
            num = 0;
        }
        else if(str[i] == ';')
        {
            tmp.push_back(num);
            if(num != 0){
                edge2[index] = tmp;
            }
            tmp.clear();
            
            ++index;
            num = 0;

        }
        else if(i == str.size() - 1){
            num = num*10 + str[i]-'0';
            tmp.push_back(num);
            if(num != 0){
                edge2[index] = tmp;
            }
            ++index;
        }
        else{
            num = num*10 + str[i]-'0';
        }
    }
    //反转图
    for(map<int, vector<int>>::iterator it=edge2.begin(); it!=edge2.end(); it++){
        for(int i=0; i<it->second.size(); i++){
            edge[it->second[i]].push_back(it->first);
        }

    }
    int len = time_array.size()-1;
    for(int i=1; i<=len; i++)
    {
        //if(edge[i].size() > 0 && !visited[i])
        //{
        if(!visited[i])
            dfs(i);
        
    }
    int ans=0;
    for(int i=1; i<=len; i++){
        // for(int  k=0; k<edge[i].size(); k++)
        // {
        //     record[i] = max(record[i], time_array[i] + record[edge[i][k]]);
        // }
        ans= max(ans, record[i]) ;
    }
    cout<<ans<<endl;

    
    return 0;
}