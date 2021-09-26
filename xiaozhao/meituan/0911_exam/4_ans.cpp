#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <string.h>

using namespace std;

/*
给一个字符串，求第n长的重复子串
abcabcabc
本身有abc子串,长度3；有abcabcabc子串，长度9
*/

//思考：一个字符串（非aaaa,bbbb这种）的子串可能既是3，又是7吗？
char str[100005];

bool isCycle[100005];

int require(int u, int v){
    memset(isCycle, 0, sizeof(isCycle));

    for(int i = 1; i <= u; i++){//长度尝试

        if(isCycle[i]){
            continue;
        }
        bool flag = true;
        for(int j = 0; j < u - i; j++){
            if(str[j] != str[j + i]){
                flag = false;
                break;
            }
        }
        if(!flag){
            continue;
        }
        for(int j = 1; j * i <= u; j++){//abcabcabc的 isCycle[3] isCycle[6] isCycle[9]都为true?
            isCycle[j * i] = true;
        }

    }

    int cnt = 0;
    int result = -1;

    for(int i = 1; i <= u; i++){

        if(!isCycle[i]){
            continue;
        }
        cnt++;
        if(cnt == v){
            result = i;
            break;
        }
    }

    return result;

}

int main(){

    scanf("%s", str);

    int n = 0;

    scanf("%d", &n);

    int u = 0;
    int v = 0;

    while(n--){
        scanf("%d%d", &u, &v);

        printf("%d\n", require(u, v));

    }
    return 0;
}
