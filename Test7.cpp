#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a>b){
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
    g = f + e;
    printf("%d",g);
    return 0;
}