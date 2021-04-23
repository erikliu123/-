#include <iostream>
#include <vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> speed, report;
    vector<pair<int, int>> ans, final_ans;
    int n;
    cin>>n;
    int  last_time=0;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        speed.push_back(tmp);
    }
    int less=0;
      ans.push_back(make_pair(0, 0));
      
     for(int i=1; i<n; i++){
        if(speed[i]+9 <= (speed[i-1])){
            ++less;
        }
        else {
            
            less=0;
        }
        if(less>=4){//AEB状态触发  
            ans.push_back(make_pair(i-7>=0?i-7:0, i+4));
            last_time = i+4;//计时开始
            //less=0;
        }

        if(i - last_time == 60){
            last_time=i;
            if(less<4)
                ans.push_back(make_pair(i, i));

        }
        
     }
     final_ans.push_back(ans[0]);
     for(int i=1; i<ans.size(); i++){
         //合并ans中的重叠部分
         if(ans[i].first <= ans[i-1].second){
             final_ans[final_ans.size()-1].second=max(final_ans[final_ans.size()-1].second, ans[i].second);

         }
         else  final_ans.push_back(ans[i]);
     }
      for(int i=0; i<final_ans.size(); i++){
          for(int j=final_ans[i].first; j<= final_ans[i].second && j<n; j++){
            if(i==final_ans.size()-1 && (j==final_ans[i].second || j==(n-1)))
                cout<<speed[j];
            else 
              cout<<speed[j]<<",";
          }

      }
      cout<<endl;
    return 0;
}