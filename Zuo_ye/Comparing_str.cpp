#include<iostream>
#include<stdlib.h>
#include<string.h>
#define LEN 100
using namespace std;
void swap(char *a,char *b){
        char s[LEN];
        strcpy(s,a);
        strcpy(a,b);
        strcpy(b,s);
}
int main(){
    char *str[5];
    cout << "Input five str:";
    for(int i=0;i<5;i++){
        *(str+i) = (char *)malloc(LEN);
        //cout << sizeof(*(str+i));
        //memset(str+i,'\0',sizeof(str+i));
        scanf("%s",*(str+i)); 
    }
    cout << "\nAfter sorted:";
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            if(strlen(*(str+j))>=strlen(*(str+j+1))){
                swap(*(str+j),*(str+j+1));
            }
        }
    }
    char temp[5];
    for(int i=0;i<5;i++){
        char s;
        cout << "  " << str[i];
        s = *(str[i]+2);
        if(strlen(str[i])<3){
            s = ' ';
        }
        temp[i] = s;
    }
    cout << '\n' << temp;
}