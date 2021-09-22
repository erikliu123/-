
/*
给定两个有序非空整数数组A和B，A按照升序排列，且不存在重复元素，B按照降序排列，且不存在重复元素。
设计算法，将B合并到A中，并输出合并后的元素的个数。要求合并结果仍然按照升序排列，且不存在重复元素。
可以假定A存在足够的空间。
*/
#include<iostream>
#include<vector>

using namespace std;

int mergeArray(vector<int> &A, int alen, vector<int> &B)
{
    //把B归并到A中
    int len = alen;
    for(int i=B.size()-1; i>=0; i--)
    {
        //找到在A中合适的位置进行插入
        bool inserted = false, same = false;
        for(int j = alen-1; j>=0; j--)
        {
            if(A[j] == B[i]){
                same = true;
                break;
            }
            if(A[j] < B[i])
            {
                inserted = true;
                //A[j+1]...A[len]的元素往后移动
                for(int k = alen; k>j; k--)
                {
                    A[k] = A[k-1];
                }
                A[j+1] = B[i];
                alen++;
            }
        }
        if(!same && !inserted)
        {
            for(int k = alen; k>0; k--)
            {
                A[k] = A[k-1];
            }
            A[0] = B[i];
            alen++;
        }

    }
    return alen;
}
int main()
{
    vector<int> A{1,2,3,4,0,0,0}, B{4,0};
    int len = mergeArray(A, 4, B);
    for(int i=0; i<len; i++)
    {
        cout<<A[i]<<"\t";
    }
    return 0;
}