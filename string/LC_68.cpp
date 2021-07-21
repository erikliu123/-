#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

/*
["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]
20
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
                
                int end = i - 1;

                while(jianju!=0 && spaces % jianju != 0)
                {
                    //要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
                    int lease_spaces = jianju*(jianju+1)/2;
                    if(cur_len + lease_spaces <= maxWidth)
                    {
                        break;
                    }
                    --jianju;
                    cur_len = cur_len - words[end].size();
                    --end;
                    spaces = maxWidth - cur_len;
                }
                i = end+1;
                //else{
                tmp = words[start];
                if(i<words.size()){
                    if(jianju != 0 && (spaces % jianju == 0)){
                        for(int k=start+1; k<i; k++)
                        
                        {
                            tmp.insert(tmp.end(), spaces/jianju, ' ');
                            tmp += words[k];
                        
                        }
                    }
                    else{
                        int first_spaces = spaces - jianju*(jianju-1)/2;
                        if(start+1 < i){
                            tmp.insert(tmp.end(), first_spaces, ' ');
                            tmp += words[start + 1];
                        }
                        else{
                            tmp.insert(tmp.end(), first_spaces, ' ');

                        }
                        for(int k=start+2; k<i; k++)
                        
                        {
                            tmp.insert(tmp.end(), --jianju, ' ');
                            tmp += words[k];
                        
                        }

                    }
                }
                else{
                    //左对齐
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
                //}

              
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