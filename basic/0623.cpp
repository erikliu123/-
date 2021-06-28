#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
    int by_subtract[]={0x2103, 0x8B976};
    int decrease_num[]={0xFED, 0xCDEF};

    int by_subtract_8[]={03210, 07135, 021006};
    int decrease_num_8[]={02645, 04677, 07777};

    char buf[]="AUCKLAND";
    for(int i =0; i<sizeof(buf)-1; i++){
        buf[i] = (buf[i]-'A' + 5)%26 + 'A';
    }

    for(int i =0; i<sizeof(by_subtract)/sizeof(int); i++)
    {
        printf(" = %x \n", by_subtract[i] - decrease_num[i]);
    }
     printf(" %d \n", 14641%31);
    printf(" 0x%x \n", 67108864);
    printf("\n\n");
     for(int i =0; i<sizeof(by_subtract_8)/sizeof(int); i++)
    {
        printf(" = %o \n", by_subtract_8[i] - decrease_num_8[i]);
    }


    double d_array[] = {0.09375, 0.85, 0.53125, 0.275, 0.1025};
    for(int i =0; i<sizeof(d_array)/sizeof(double); i++)
    {
        printf(" double[%d] = %llx \n", i, *(uint64_t *)&d_array[i]);
    }
    return 0;
}