#include<iostream>
int main(){
    int square[5][5];
    int sum_h[5]={0},sum_l[5]={0},sum_d[2]={0};
    printf("Input your square:\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&square[i][j]);
        }
    }
    {
    for(int n=0;n<5;n++){
        sum_d[0] += square[n][n];
        sum_d[1] += square[4-n][n];
    }
    if(sum_d[0]!=sum_d[1]) goto label;
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            sum_h[i] += square[i][j];
            sum_l[i] += square[j][i];
        }
        if(sum_h[i]!=sum_l[i]) goto label;
        if(i>=1){
            if(sum_h[i]!=sum_h[i-1]||sum_l[i]!=sum_l[i-1]) goto label;
        }
    }
    if(1) printf("It is a magic square!");
    else{
        label:
        printf("It is not a magic square!");
    }
    return 0;
}