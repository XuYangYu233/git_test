#include<math.h>
#include<iostream>
double fun(int n){
    double result;
    double sum=0.0;
    int i;
    for(i=1;(i*21)<n;i++){
        sum += i*21;
    }
    result = sqrt(sum);
    return result;
}
int main(){
    printf("calculate complex calculating!\ninput 88 to exit\n");
    while(1){
        char boo;
        int n;
        double res;
        printf("input n:");
        scanf("%d",&n);
        if(n==88) break;
        res = fun(n);
        printf("answer is %f\n",res);
    }
    printf("exit");
    return 0;
}