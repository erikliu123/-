/*
现给定任意正整数 n，请寻找并输出最小的正整数 m（m>9），使得 m 的各位（个位、十位、百位 ... ...）之乘积等于n，若不存在则输出 -1。
*/
class Solution {
public:
    /**
     * 输入一个整形数值，返回一个整形值
     * @param n int整型 n>9
     * @return int整型
     */
    int solution(int n) {
        // write code here
        string s;
        map<int, int> record;
        while(n > 1)
        {
            int i=2;
            for(; i<10 && i<=n; i++)
            {
                if(n%i == 0){
                    record[i] ++;
                    n/=i;
                    break;
                }
            }
            if(i>=10) {
                return -1;
            }
        }
        //2,2,3,3,3 的时候，结果应当是269，而不是349!
        record[9] += record[3]/2; 
        record[3] %= 2;
        record[8] += record[2]/3; 
        record[2] %= 3;
        
        record[6] += min(record[3], record[2]);//NOTICE:关键
        record[3] -=  record[6];
        record[2] -= record[6];
       
        record[4] += record[2]/2; 
        record[2] %= 2;
        int ans = 0;
        for(auto x:record)
        {
            for(int i=0; i<x.second; i++){
                ans = ans *10 +x.first;
            }
        }
        return ans;
        
    }
};