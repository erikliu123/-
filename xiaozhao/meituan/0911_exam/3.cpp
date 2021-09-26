#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

/*
小美在听歌。歌单给小美推送了一个歌单序列，歌单中的歌会严格按顺序播放。

歌单中有很多歌曲，听每首歌曲会给小美带来ai点愉悦值。但是某些歌曲是一个系列的。如果小美在听这首歌曲之前没有按顺序听过这个系列的所有前面的歌曲，
就会给小美带来-bi的愉悦值（即最后选择这首歌可获得的总愉悦值为ai-bi。）歌单并不会保证这首歌在系列中前面的歌曲都在歌单中。

因此，小美可以预先去除中间的一些歌曲，使得自己更加愉悦。由于去掉歌曲需要花费时间，所以每去掉一首歌曲都会让自己的愉悦值减小k。
由于歌单是智能的，所以其中不会包含重复的歌曲。
请问小美能获得的最大愉悦值是多少？
*/

/*
第一行两个空格隔开的整数n,k(1≤n,k≤10^5)代表歌曲数量和删除歌曲减少的愉悦值。

接下来n行每行包括四个空格隔开的整数ai,bi,ci,di(1≤ai,bi,ci,di≤10^5)分别代表听这首歌获得的愉悦值，
没有按顺序听完这个系列之前的歌所需要扣除的愉悦值，这首歌所在的系列，这首歌在系列中是第几首。
*/
struct song
{
    int happyValue;
    int switchValue;
    int series;
    int index;
};

vector<int> curIndex(100010, 0);
int main()
{
    int n, k;
    cin>>n>>k;
    vector<song> all;
    vector<int> sum;
    //必须按照序列来听 
    for(int i=0; i<n; i++)
    {
        song temp;
        cin>>temp.happyValue>>temp.switchValue>>temp.series>>temp.index;
        all.push_back(temp);
    }
    //尽量避免switch
    int ans = 0;
     for(int i=0; i<n; i++)
     {
        if((all[i].switchValue -  all[i].happyValue) > k && all[i].index != (curIndex[all[i].series] + 1))//删除带来的扣分少的时候
        {
            ans -= k;
        }
        else{//加入歌单
            ans += all[i].happyValue;
            if(all[i].index == (curIndex[all[i].series] + 1))
            {
                curIndex[all[i].series]++;
                
            }
            else{
                ans -= all[i].switchValue;
            }
        }
     }
     cout<<ans<<endl;
     return 0;
}
