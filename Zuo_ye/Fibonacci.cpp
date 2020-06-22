#include<iostream>

int fab_diedai(int n){
    int a=1,b=1,c;
    if(n<=2) return 1;
    while(n>2){
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}

int fab_digui(int n){
    if(n==1||n==2) return 1;
    else{
        return fab_digui(n-1)+fab_digui(n-2);
    }
}

int main(){
    int boo;
    printf("Calculate Fibonaccis!\nInput a fushu or 0 to exit\n");
    printf("Which kind of function to use?[digui(0)/diedai(1)]");
    scanf("%d",&boo);
    while(1){
        int n,ans;
        printf("Input n:");
        scanf("%d",&n);
        if(n<=0) break;
        if(boo==0) ans = fab_digui(n);
        else ans = fab_diedai(n);
        if(ans<=0){
            printf("That n is too big!\nTry again!");
            continue;
        } 
        printf("The answer is %d\n",ans);
    }
    printf("Exit!");
    return 0;
}