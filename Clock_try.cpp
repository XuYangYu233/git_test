#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<Windows.h>

void delays(unsigned int t){
    unsigned int i,j;
    //for(i=0;i<t;i++){
        for(j=0;j<t;j++);
    //}
}



int main(){
    clock_t start, finish;
    double Text_time;
    start = clock();
    Sleep(1.5);
    //delays()
    //delays(1000*2000);
    finish = clock();
    Text_time = (double)(finish-start) / CLOCKS_PER_SEC * 1000;
    printf("%lf ms/n",Text_time);
    return 0;
}