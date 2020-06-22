#include<iostream>
#include<string.h>
#include<stdlib.h>
#define MINGWENPAN "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define MIWENPAN "DEFGHIJKLMNOPQRSTUVWXYZABCdefghijklmnopqrstuvwxyzabc"
using namespace std;

void change(char *pa){
    char ming[]=MINGWENPAN;
    char mi[]=MIWENPAN;
    for(int a=0;a<52;a++){
        if(*pa==ming[a]){
            *pa=mi[a];
            break;
        }
    }

}
int main(){
    char *str_a;
    int len;
    str_a = (char*)calloc(100,sizeof(char));
    cout << "Input Mingwen:";
    gets(str_a);
    len = strlen(str_a);
    for(int i=0;i<len;i++){
        change(&*(str_a+i));
    }
    cout << "Output Miwen:";
    for(int i=0;i<len;i++){
        cout << *(str_a+i) << "";
    }
    free(str_a);
    return 0;
}