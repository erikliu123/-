#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;
/*
给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，
使得每行恰好有 maxWidth 个字符。
要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:
单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
*/

/*
易错样例:
["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]
20
["ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"]
16
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> single_word;
        int start = 0;
        int cur_len = words[0].size();//pure word's len
        for(int i=1; i<words.size() || cur_len>0; i++)
        {
            int len = cur_len;
            if(i<words.size())
                len = cur_len + words[i].size();
                
            if(i<words.size() && i-start + len <= maxWidth)//at lease (i - start) spaces
            {
                cur_len = len;
            }
            else{
                int spaces = maxWidth - cur_len;
                int jianju;
                if(i<words.size())
                    jianju = i - start -1;
                else
                    jianju = i - start;
                string tmp;

                tmp = words[start];//第一个单词无脑加即可
                if(i<words.size()){
                    if(jianju != 0 && (spaces % jianju == 0)){//间距能均匀的用完
                      
                        for(int k=start+1; k<i; k++)
                        
                        {
                            tmp.insert(tmp.end(), spaces/jianju, ' ');
                            tmp += words[k];
                        
                        }
                    }
                    else if(jianju == 0){//只有一个单词
                        tmp.insert(tmp.end(), spaces, ' ');
                    }
                    else{
                        /*NOTICE: 间距不均匀，间距的计算需要稍微复杂的逻辑, 
                            如果有四个空格，三个间距，那么ceil(4/3)=2，但是只能分1个2出来,然后给其他的两个间距1
                            更简单的逻辑似乎4%3就行了。。。
                        */
                        int prev_spaces = (spaces + jianju -1) / jianju;//
                        int last_spaces = prev_spaces - 1;
                        int interval = prev_spaces * jianju - spaces;//
                        for(int k=start+1; k<start+1+jianju - interval; k++)

                        {
                            tmp.insert(tmp.end(), prev_spaces, ' ');
                            tmp += words[k];
                        }
                         for(int k=start+1+jianju - interval; k<i; k++){
                            tmp.insert(tmp.end(), last_spaces, ' ');
                            tmp += words[k];
                         }
                    }
                }
                else{
                    //最后一次操作, 左对齐
                    int spaces = i - start -1;
                    for(int k=start+1; k<i; k++)
                        
                    {
                        tmp.insert(tmp.end(), 1, ' ');
                        tmp += words[k];
                    
                    }
                    tmp.insert(tmp.end(), maxWidth - cur_len - spaces, ' ');


                }
                ans.push_back(tmp);
                start = i;
                if(i<words.size())
                    cur_len = words[i].size();
                else
                    cur_len = 0;
            }
        }
        return ans;
        //last line or last two line?

    }
};



int main()
{
    Solution a;
    vector<string> ans;
    vector<string> str;
    //vector<string> str{"This", "is", "an", "example", "of", "text", "justification."};

    //ans = a.fullJustify(str, 16);
    str=vector<string>{"Science","is","what","we","understand","well","enough","to","explain","to","a",
    "computer.","Art","is","everything","else","we","do"};
    ans = a.fullJustify(str, 20);
    return 0;
}