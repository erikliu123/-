#include <stdio.h>
//(void *)(&(((type*)NULL)->member) - ((type*)NULL)); //ptr->member - ptr;
#define container_of(ptr, type, member)    \
    (type*)((char *)ptr - (char *)&(((type*)0)->member))

struct bar {
    int a;
};

struct foo {
    short b;
    struct bar bar;
    char c;
};

void test(struct bar *b)
{
    struct foo *f;
    f = container_of(b, struct foo, bar);
}

int main(){
    //int a;
    //scanf("%d", &a);
    //printf("%d\n", a);
    int a;
    int b;
   //(void *)&a - (void *)&b; //NOTICE: 错误的减法
    printf("%s\n","Hello World! ");
}