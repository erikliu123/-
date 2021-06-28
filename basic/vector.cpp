#include <iostream>
#include <array>
#include <vector>
#include <cstring>

using namespace std;

void Print(vector<vector<int>> a)
{
    vector<vector<int> >::iterator p1;
    vector<int>::iterator p2;
    for (p1 = a.begin(); p1 != a.end(); p1++)
    {
        for (p2 = p1->begin(); p2 != p1->end(); p2++)
        {
            cout << "[" << *p2 << "]";
        }
        cout <<endl;
    }
    cout <<endl;
}

int main()
{
    int i = 0;
    vector <int> asd(4,2); //将含有4个数据的一维动态数组初始为2
    vector<std::vector<int> > asd1(4,vector<int>(4,0)); //初始化row*column二维动态数组，初始化值为0

    vector<std::vector<int> >::iterator p1;
    vector <int>::iterator p2;


    //简单初始化
    for (p1 = asd1.begin(); p1 != asd1.end(); p1++)
    {
        for (p2 = p1->begin(); p2 != p1->end(); p2++)
        {
            *p2 = i++;
        }
    }

    cout << "Init:" <<endl;
    Print(asd1);

    //插入列元素用push_back
    asd1[1].push_back(23);
    asd1.push_back(asd);
   
    
    //设置行列数
    int size_row = asd1.size();             //获取行数
    cout << "size_row:" << size_row <<endl;
    asd1.resize(10);                        //设置行数
    size_row = asd1.size();                 //获取行数
    cout << "size_row:" << size_row <<endl;

    int size_col = asd1[0].size();
    cout << "size_col:" << size_col <<endl;
    asd1[1].resize(10);                     //设置列数
    size_col = asd1[1].size();
    cout << "size_col:" << size_col <<endl;
    
   
    cout << "Push_back:" <<endl;
    Print(asd1);

    cout << "Erase:" <<endl;
    auto test1 = asd1.begin();
    test1 = test1 + 3;
    asd1.erase(test1);
    Print(asd1);

    return 0;
}