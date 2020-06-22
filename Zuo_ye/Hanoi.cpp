#include<iostream>
void hanoi(int n,char a,char b,char c){
    if(n==1) printf("%c --> %c\n",a,c);
    else{
        hanoi(n-1,a,c,b);
        printf("%c --> %c\n",a,c);
        hanoi(n-1,b,a,c);
    }
}
int main(){
    int n;
    char a='A',b='B',c='C';
    printf("input the number of hanoi:");
    scanf("%d",&n);
    hanoi(n,a,b,c);
    system("PAUSE");
    return 0;
}