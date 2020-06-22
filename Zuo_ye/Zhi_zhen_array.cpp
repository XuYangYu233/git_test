#include<iostream>
#define WEEK {"Monday","Tuseday","Wensday","Thursday","Friday","Saturday","Sunday"}
using namespace std;
int main(){
    char week[7][20]=WEEK;
    char *ptr[7];
    int n=0;
    for(int i=0;i<7;i++){
        ptr[i] = week[i];
    }
    cout << "Input n:";
    while(1){
        scanf("%d",&n);
        if(n>=1&&n<=7) break;
        else cout << "Input error!" << endl << "Please input again:";
    }
    cout << "Output weekday:" << ptr[n-1] << endl;
    return 0;
    /*
    char *week[7]=WEEK;
    int n=0;
    cout << "Input n:";
    while(1){
        scanf("%d",&n);
        if(n>=1&&n<=7) break;
        else cout << "Input error!" << endl << "Please input again:";
    }
    cout << "Output weekday:" << week[n-1] << endl;
    return 0;
    */
}