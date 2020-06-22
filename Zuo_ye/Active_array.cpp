#include<iostream>
#include<stdlib.h>
using namespace std;

void swap(int *pa,int *pb){
    *pa = *pa + *pb;
    *pb = *pa - *pb;
    *pa = *pa - *pb;
}
int main(){
    int *arr_a,n;
    cout << "Input n:";
    scanf("%d",&n);
    arr_a = (int*)calloc(n,sizeof(int));
    cout << "The array:";
    for(int i=0;i<n;i++){
        *(arr_a+i) = rand()%100;
        cout << *(arr_a+i) << "   ";
    }
    cout << "\nAfter paixu:";
    for(int j=0;j<n;j++){
        for(int k=0;k<n-1;k++){
            if(*(arr_a+k)>*(arr_a+k+1)) swap(*(arr_a+k),*(arr_a+k+1));
        }
    }
    for(int i=0;i<n;i++){
        cout << *(arr_a+i) << "   ";
    }
    return 0;
}