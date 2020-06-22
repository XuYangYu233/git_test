#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
    unsigned char *stra;
    stra = (unsigned char *)malloc(6);
    //printf("size of stra is %d\n",(int)sizeof(*stra));
    printf("input stra[0]:");
    scanf("%c",&(stra[0]));
    getchar();
    //getchar();
    printf("now stra[0] is %02X \ninput stra[1]:",stra[0]);
    stra = (unsigned char *)realloc(stra,2);
    scanf("%c",&(stra[1]));
    printf("now stra[0] is %02X, stra[1] is %02X \n",stra[0],stra[1]);

    return 0;
}