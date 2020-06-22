#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char s;
    char stra[100];
    int count=0;
    cout << "Input:";
    while(1){
        s=getchar();
        if(s<'!'){
            stra[count] = '\0';
            break; 
        }
        stra[count] = s;
        count++;
    }
    for(int i=count;i>0;i--){
        if(i==1){
            cout << "Output:" << 1 <<endl;
            cout << "Explanation: The answer is \"" << stra[0] << "\", with the length of 1." << endl;
            goto labelb;
        }
        char *strb;
        strb = (char *)malloc(i+1);
        //char strb[i+1];
        int token=0;
        while(token+i<=count){
            for(int j=0;j<i;j++){
                strb[j]=stra[token+j];
            }
            strb[i] = '\0';
            for(int a=0;a<i;a++){
                for(int b=a+1;b<i;b++){
                    if(strb[a]==strb[b]) goto labela;
                }
            }
            if(1){
                cout << "Output:" << sizeof(strb)-1 <<endl;
                cout << "Explanation: The answer is \"" << strb << "\", with the length of " << sizeof(strb)-1 << "." << endl;
                goto labelb;
            }
            else{
                labela:
                token++;
            }
        }
    }
    if(0){
        labelb:
        cout << "end" <<endl;
    }
}