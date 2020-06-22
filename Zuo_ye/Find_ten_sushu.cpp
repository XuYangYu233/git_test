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
    return count;
}

int erfen(int pri,int arr_ten[]){
    int len,sig,counter=1;
    len = 10;
    sig = len/2;//printf("%d\n",len);
    while(1){
        if(sig>=len){
            sig--;
            continue;
        } 
        if(pri>arr_ten[sig]) sig = sig - (len/pow(2,counter+1));
        else{
            if(pri<arr_ten[sig]) sig = sig + (len/pow(2,counter+1)) + 1;
            else break;
        }
        //printf("%d\n",sig);
        counter++;
        if(counter>=5){
            sig = -1;
            break;
        }
    }
    return sig;
}

int main(){
    int n,cou=0,sum=0,count,pri;
    int arr_ten[10];
    printf("Input n(n<=500):");
    scanf("%d",&n);
    int arr_a[n];
    count = shai_fa(arr_a,n);
    while(1){
        printf("%6d",arr_a[count-cou-1]);
        sum += arr_a[count-cou-1];
        arr_ten[cou] = arr_a[count-cou-1];
        cou++;
        if(cou==10) break;
    }
    printf("\nsum=%d\nInput a prime:",sum);
    scanf("%d",&pri);
    n = erfen(pri,arr_ten);
    printf("Location:%d\n",n);
    return 0;
}