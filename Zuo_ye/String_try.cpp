#include<iostream>
#include<string.h>
int main(){
    char str_a[]="Hel lo";
    char str_b[]="string";
    char str_c[12];
    int n;
    printf("str_a��С:%d\n",sizeof(str_a));//��С��6(���ֽ�)����Ϊ��β��һ��\0
    printf("str_a����:%d\n",strlen(str_a));//����Ϊ5��strlen�������������\0
    strcpy(str_c,str_a);//��str_a��ֵ���Ƹ�str_c
    n = strcmp(str_a,str_c);
    printf("1.n=%d\n",n);
    n = strcmp(str_b,str_a);
    printf("2.n=%d\n",n);//���s1��s2��ͬ,�򷵻�0;���s1<s2,�򷵻�С��0;���s1>s2,�򷵻ش���0
    strcat(str_a,str_b);//strcat�ɽ�str_bƴ�ӵ�str_aβ��
    printf("ƴ�ӽ��:%s\n\n",str_a);
    
    system("PAUSE");
    return 0;
}