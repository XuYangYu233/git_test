#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int a,b,c,d,e,f,g;
    char stra[100],strb[100]="No";
    scanf("%s", stra);
    if (!strcmp(stra, "VISIT")) {
        scanf("%s", strb);
    }
    printf("%s!!!%s", stra, strb);
    /*if(a>b){
        e = b;
    }
    else{
        e = a;
    }
    if(c>d){
        f = c;
    }
    else{
        f = d;
    }
    g = f + e;*/
    //printf("%d",g);
    return 0;
}