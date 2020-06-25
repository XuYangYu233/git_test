#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main(){
    float i,a,b;
    a = 10;
    b = 3;
    i = a/b;
    //printf("%f",i);
    //cout << 1 / 2;
    char *arr;
    arr = (char *)malloc(a*sizeof(char));
    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = '\0';
    printf("%s", arr);
    free(arr);

    return 0;
}