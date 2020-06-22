#include<iostream>
#include<string.h>
int main(){
    char str_a[]="Hel lo";
    char str_b[]="string";
    char str_c[12];
    int n;
    printf("str_a大小:%d\n",sizeof(str_a));//大小是6(个字节)，因为结尾有一个\0
    printf("str_a长度:%d\n",strlen(str_a));//长度为5，strlen这个函数不计算\0
    strcpy(str_c,str_a);//将str_a的值复制给str_c
    n = strcmp(str_a,str_c);
    printf("1.n=%d\n",n);
    n = strcmp(str_b,str_a);
    printf("2.n=%d\n",n);//如果s1和s2相同,则返回0;如果s1<s2,则返回小于0;如果s1>s2,则返回大于0
    strcat(str_a,str_b);//strcat可将str_b拼接到str_a尾部
    printf("拼接结果:%s\n\n",str_a);
    
    system("PAUSE");
    return 0;
}