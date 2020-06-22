#include<iostream>
#include<math.h>

int shai_fa(int arr_a[],int n){
    int i,j,count=0;
    for(i=3;i<=n;i+=2){
        for(j=3;j<=i-1;j++){
            int k;
            k = i % j;
            if(k==0) goto label;
        }
        arr_a[count] = i;
        count++;
        label:
        continue;
    }
    arr_a[count] = -1;
    return 0;
}

int main(){
    int n,cou=0;
    printf("input n:");
    scanf("%d",&n);
    int arr_a[n];
    shai_fa(arr_a,n);
    printf("the answer is: 2,");
    while(1){
        printf("%2d",arr_a[cou]);
        cou++;
        if(arr_a[cou]==-1) break;
        if((cou+1)%5==0) printf("\n              ");
        else printf(",");
    }
    //system("PAUSE");
    return 0;
}