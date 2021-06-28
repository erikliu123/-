#include <stdio.h>
#include <string.h>
/*
问：fun的作用是不是返回字符串ps的长度？
答案： 不是
*/
int Fun(char *ps){
    char *p;
    p=ps;
    while(*p++);return (p-ps);
}
    
int main(){
    char*s ;int 
    a1,a2;
    s = "hello";
    a1=Fun(s);
    a2=strlen(s);
    printf("%d , %d n" , a1,a2);
    return 0;
}
