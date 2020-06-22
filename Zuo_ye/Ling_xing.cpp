#include<iostream>
int main(){
    int a,b;
    for(a=1;a<=7;a++){
        for(b=1;b<=7;b++){
            if(a+b>=5&&a+b<=11&&b-a<=3&&a-b<=3) printf("*");
            else printf(" ");
        }
    printf("\n");
    }
    system("PAUSE");
    return 0;
}