#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
    int n;
    vector<int> res;
    set<int> notExist1, notExist2;
    vector<vector<int>> tree;
public:
    //根左右遍历
    void dfs1(int cur, vector<int>& nums) {
        res[cur] = min(res[cur], *notExist1.begin());
        notExist1.insert(nums[cur]);
        for(int v : tree[cur]) {
            dfs1(v, nums);
        }
    }
    //根右左遍历
    void dfs2(int cur, vector<int>& nums) {
        res[cur] = min(res[cur], *notExist2.begin());
        notExist2.insert(nums[cur]);
        for(int i = (int)tree[cur].size() - 1; i >= 0; --i) {
            int v = tree[cur][i];
            dfs2(v, nums);
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& fa, vector<int>& nums) {//nums[i]互不相同！！如果可以相同的话是有问题的
        n = fa.size();
        res.resize(n, 1e6);
        tree = vector<vector<int>> (n);
        for(int i = 0; i < n; ++i) {
            if(fa[i] >= 0) {
                tree[fa[i]].emplace_back(i);
            }
        }
        unordered_set<int> exist;
        int mx = 0;//最大基因值
        for(int x : nums) {
            mx = max(mx, x);
            exist.insert(x);
        }
        notExist1.clear();
        notExist2.clear();
        for(int i = 1; i <= mx + 1; ++i) {
            if(!exist.count(i)) {
                notExist1.insert(i);
                notExist2.insert(i);
            }
        }
        dfs1(0, nums);
        dfs2(0, nums);
        return res;
    }
};


int main()
{
    Solution a;
    //vector<int> parent{-1,0,1,0,3,3}, nums{5,4,6,2,1,3};
    vector<int> parent{-1,0,0,1,1,2,2}, nums{6,5,4,1,2,1,3};
     parent =  vector<int>{-1,0,0,1,1,2,2,3};
     nums= vector<int>{4,4,1,1,2,3,2,3};
    //vector<int> parent{-1,0,0,2}, nums{1,2,3,4};
    a.smallestMissingValueSubtree(parent, nums);

    return 0;
}
// 作者：Wilson1996
// 链接：https://leetcode-cn.com/problems/smallest-missing-genetic-value-in-each-subtree/solution/er-cha-shu-xian-xu-bian-li-gen-zuo-you-g-8c0m/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。