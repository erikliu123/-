#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

// struct pair_hash {
//     template <class T1, class T2>
//     std::size_t operator()(const std::pair<T1, T2> &p) const {
//         return hash_val(p.first, p.second);
//     }
// };

// 作者：youngforest
// 链接：https://www.zhihu.com/question/30921173/answer/1248680260
// 来源：知乎
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

vector<int> row_cnt, col_cnt, grid_cnt;//已填数字的统计
/*NOTICE: 使用pair<int, int>作为哈希表的键需要额外实现哈希函数！！*/
//unordered_map<pair<int, int>, bool, pair_hash> row_map, col_map, grid_map;//pair<num, i>, 表示 num是否在第i列/行中出现

map<pair<int, int>, bool> row_map, col_map, grid_map;//pair<num, i>, 表示 num是否在第i列/行中出现
 bool compare(pair<int, int> &a, pair<int, int> &b)
{
    int cnt1 = row_cnt[a.first]+col_cnt[a.first]+grid_cnt[a.first/3*3 + a.second/3];
    int cnt2 = row_cnt[b.first]+col_cnt[b.first]+grid_cnt[b.first/3*3 + b.second/3];
    if(cnt1 != cnt2) cnt1 < cnt2;//构建大堆
    if(a.first != b.first) return a.first>b.first;
    return a.second>b.second;

}

class Solution {
public:
    
    vector<pair<int, int>> holes;
    priority_queue< pair<int, int>, vector<pair<int, int>>, decltype(&compare)> pq; //NOTICE:第二个参数不能是vector<pair<int, int>>*, priority_queue< pair<int, int>, vector<pair<int, int>> *, ...

    bool has_find;
    void DFS(vector<vector<char>>& board){
        
        if(pq.size() == 0) {
            has_find = true;
            return;
        }
        //排序
        pair<int, int> item = pq.top();
        pq.pop();
        //找到合适的item。
        bool isvalid = false;
        char before = board[item.first][item.second];
        for(int i=1; i<=9; i++){
            if(row_map[make_pair(i,item.first)] || col_map[make_pair(i, item.second)] || grid_map[make_pair(i, item.first/3*3 + item.second/3)]) continue;
            row_map[make_pair(i,item.first)] = true;
            col_map[make_pair(i, item.second)] = true;
            grid_map[make_pair(i, item.first/3*3 + item.second/3)] = true;
            board[item.first][item.second] = i+'0';
            isvalid = true;
            if(pq.size()  == 0) {
                has_find = 1; 
                //return ;
            }//没有这句也不行，因为没必要继续DFS了？
            DFS(board);
            if(has_find) return ;//肯定要有
             //board[item.first][item.second] = before;
            row_map[make_pair(i,item.first)] = false;
            col_map[make_pair(i, item.second)] = false;
            grid_map[make_pair(i, item.first/3*3 + item.second/3)] = false;
        }
        pq.push(item);

    }
    void solveSudoku(vector<vector<char>>& board) {
        has_find = false;
        row_cnt=vector<int>(9,0);
        col_cnt=vector<int>(9,0);
        grid_cnt=vector<int>(9,0);
        // for(auto &i:board)
        // {
        //     for(auto &j:i)
        pq = priority_queue< pair<int, int>, vector<pair<int, int>>, decltype(&compare)>(&compare);
         for(int i=1; i<=9; i++)
        {
            for(int j=0; j<9; j++){
                row_map[make_pair(i,j)] = false;
                col_map[make_pair(i,j)] = false;
                grid_map[make_pair(i,j)] = false;
            }
        }
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.'){
                    row_cnt[i]++;
                    col_cnt[j]++;
                    grid_cnt[i/3*3+j/3]++;

                    row_map[make_pair(board[i][j]-'0',i)] = true;
                    col_map[make_pair(board[i][j]-'0',j)] = true;
                    grid_map[make_pair(board[i][j]-'0',i/3*3+j/3)] = true;
                   
                }
                else{
                    holes.push_back(make_pair(i,j));
                }
            }

        }
        for(auto& i: holes)
            pq.push(i);
        DFS(board);
        return ;

    }
};


int main()
{
    Solution a;
    vector<vector<char>> board=vector<vector<char>>(9, vector<char>(9, '.'));
    vector<vector<char>> board2; //{{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."}};//,[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]};
    a.solveSudoku(board);
    a.solveSudoku(board2);
    return 0;
}