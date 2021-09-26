#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*给一个字符串，求第n长的重复子串
abcabcabc
*/
int main()
{
    string str;
    cin >> str;
    int n;
    cin >> n;
    /*
        2 1
        6 1
        9 2//第二短的前缀
    */

    for (int i = 0; i < n; i++)
    {
        int len, order;
        cin >> len >> order;
        if (order > len)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> next(str.size(), -1);
        //不断暴力模拟
        bool same = true;
        for (int k = 1; k < len; ++k)
        {
            if (str[k] != str[k - 1])
            {
                same = false;
                break;
            }
        }
        if (same)//都是相同的字母组成
        {
            cout << order << endl;
            continue;
        }
        int ok = 0;
        for (int k = 1; k < len; ++k)
        {
            bool found = true;
            if (len % k)
            {
                continue;
            }
            for (int x = k; x < len - 1; x += k){
                if (str.substr(0, k) != str.substr(x, k))
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                ++ok;
                if (ok == order)//找到第order长的重复子串
                {
                    cout << k << endl;
                    continue;
                }
            }
        }
        ++ok;
        if (ok == order)
        {
            cout << len << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}