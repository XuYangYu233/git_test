#include<iostream>
int main(){
    int a,*p;
    scanf("%d",&a);
    p = &a;
    printf("%d",*p);
    return 0;
}