#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

/**
* Welcome to vivo
*/

#define MAX_NUM 101

int solution(int n, int weight[]) {

    // TODO Write your code here
    // vector<int> dp;
    // int sum = 0;
    // for(int i=0; i<n; i++)
    // {
    //     sum += weight[i];
    // }
    // dp = vector<int>(sum/2 + 1, 0);
    
    // for(int i=0; i<n; i++)
    // {
    //     for(int v=sum/2; v>=weight[i]; v--)
    //     {
    //         dp[v] = max(dp[v], dp[v-weight[i]] + weight[i]);
    //     }
    // }
    // if(abs(sum - 2*dp[sum/2]) <= 1) return 0;
    // else return abs(sum - 2*dp[sum/2]) - 1;

    vector<vector<int>> dp;
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += weight[i];
    }
    dp = vector<vector<int>>(sum/2 + 1, vector<int>(n/2+1, 0));
    
    for(int i=0; i<n; i++)
    {
        for(int v=sum/2; v>=weight[i]; v--)
        {
            //for(int k=n/2; k>0; k--)
            for(int k=0; k<n/2; k++){
                if(k==0 || (k>0 && dp[v-weight[i]][k] > 0))
                dp[v][k+1] = max(dp[v][k+1], dp[v-weight[i]][k] + weight[i]);
            }
        }
    }
   return abs(sum - 2*dp[sum/2][n/2]);
   
   
}

int main()
{    
	string str("");
	getline(cin, str);
	int a[MAX_NUM];
	int i = 0;
	char *p;
	int count = 0;
	
	const char* strs = str.c_str();
	p = strtok((char *)strs, " ");
	while(p)
	{
		a[i] = atoi(p);
		count++;
		p = strtok(NULL, " ");
		i++;
		if(i >= MAX_NUM)
			break;
	}
	
	int result = solution(count, a);
	cout << result << endl;
	return 0;
}