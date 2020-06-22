#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void swap(int *a,int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main(){
    time_t seed;
    srand(time(&seed));
    int arra[100],arrb[100];
    //int a,b;
    for(int i=0;i<100;i++){
        arra[i] = rand()%1000;
        arrb[i] = rand()%1000;
    }
    for(int i=0;i<99;i++){
        for(int j=0;j<99;j++){
            if(arra[j]>arra[j+1]){
                swap(&(arra[j]),&(arra[j+1]));
            }
            if(arrb[j]>arrb[j+1]){
                swap(&(arrb[j]),&(arrb[j+1]));
            }
        }
    }

    FILE *fi1,*fi2;
    cout << "a:     b:" << endl;
    fi1 = fopen("data1.dat","w");
    fi2 = fopen("data2.dat","w");
    for(int i=0;i<100;i++){
        fprintf(fi1,"%d   \n",arra[i]);
        fprintf(fi2,"%d   \n",arrb[i]);
        printf("%-5d  %-5d\n",arra[i],arrb[i]);
    }
    fclose(fi1);
    fclose(fi2);
    //FILE *fi3;
    int arrc[200];
    for(int i=0;i<200;i++){
        if(i<100){
            arrc[i] = arra[i];
        }
        else{
            arrc[i] = arrb[i-100];
        }
    }
    
    for(int i=0;i<199;i++){
        for(int j=0;j<199;j++){
            if(arrc[j]>arrc[j+1]){
                swap(&arrc[j],&arrc[j+1]);
            }
        }
    }
    
    freopen("result.dat","w",stdout);
    for(int i=0;i<200;i++){
        cout << arrc[i] << endl;
    }

    return 0;
}