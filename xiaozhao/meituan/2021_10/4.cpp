#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

/*
小团有一个由N个节点组成的二叉树，每个节点有一个权值。定义二叉树每条边的开销为其两端节点权值的乘积，二叉树的总开销即每条边的开销之和。
小团按照二叉树的中序遍历依次记录下每个节点的权值，即他记录下了N个数，第i个数表示位于中序遍历第i个位置的节点的权值。之后由于某种原因，
小团遗忘了二叉树的具体结构。在所有可能的二叉树中，总开销最小的二叉树被称为最优二叉树。现在，小团请小美求出最优二叉树的总开销。


输入描述:
第一行输入一个整数N（1<=N<=300），表示二叉树的节点数。

第二行输入N个由空格隔开的整数，表示按中序遍历记录下的各个节点的权值，所有权值均为不超过1000的正整数。

输出描述:
输出一个整数，表示最优二叉树的总开销。
*/

int dp[320][320][320];
int arr[320];

int dp2[320][320][320];
//子问题的拆解，谁是根，再划分成左右孩子问题
int dfs(int left, int right, int root)
{
    int res = 1 << 30;
    if (left > right)
        return 0;
    if (dp[left][right][root] != -1)
        return dp[left][right][root];
    for (int i = left; i <= right; i++)
    {
        int ret = dfs(left, i - 1, i) + dfs(i + 1, right, i) + arr[root] * arr[i];
        res = min(res, ret);
    }
    dp[left][right][root] = res;
    return res;
}

int main()
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    //memset(dp, -1, sizeof(dp));
    //cout<<dfs(1, n, 0)<<endl;

    /*动态规划的写法*/
    //   链接：https://www.nowcoder.com/questionTerminal/0d939e874a004f449a370aca1346dd5c
    // for (int i = 0; i < n - 1; i++)
    // {
    //     dp[i][i + 1][i] = arr[i] * arr[i + 1];
    //     dp[i][i + 1][i + 1] = dp[i][i + 1][i];
    // }
    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i < n - k; i++)//求解子问题[i, i+k]
        {
            for (int m = i; m <= i + k; m++)//m作为根的时候
            {
                int left = i == m ? 0 : dp[i][m - 1][i] + arr[i] * arr[m];
                for (int l = i + 1; l < m; l++)//找左子树的根
                {
                    left = min(left, dp[i][m - 1][l] + arr[l] * arr[m]);
                }
                int right = m == i + k ? 0 : dp[m + 1][i + k][i + k] + arr[i + k] * arr[m];
                for (int r = m + 1; r < i + k; r++)//找右子树的根
                {
                    right = min(right, dp[m + 1][i + k][r] + arr[r] * arr[m]);
                }
                dp[i][i + k][m] = left + right;
            }
        }
    }
    int res = dp[0][n - 1][0];
    for (int i = 1; i < n; i++)
    {
        res = min(res, dp[0][n - 1][i]);
    }
    return 0;
}