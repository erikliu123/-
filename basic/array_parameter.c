#include <stdio.h>

void fun(int array[2])//只会传入array的地址进来，而不是拷贝array[0],array[1]
{
    array[0] = 100;
    array[1] = 101;

}

int main()
{
    int array[2];
    fun(array);
    return 0;
}