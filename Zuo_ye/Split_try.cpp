#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main(){
    char strarr[10][50];
    memset(strarr,'\0',500);
    char *str,*temp;
    str = (char *)calloc(200,sizeof(char));
    temp = (char *)calloc(50,sizeof(char));
    strcpy(str,"MATLAB����Ӧ��   1.0   ����   ������   ������ϢѧԺ   ��Ȼ�빤����   2019   1   ��һ:1-10��,ÿ1��11-12��,1��,3-303   ��");
    temp = strtok(str,"   ");
    int i=0;
    while(temp!=NULL){
        strcpy(strarr[i],temp);
        cout << strarr[i] <<endl;
        i++;
        temp = strtok(NULL,"   ");
    }//��סstrtok�������������������Щ���ǲ�֪��strtok�ĺ�������������˺ܶิ�ӵĶ������Ǹ㲻����
    /*int mk1=0,mk2=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<=strlen(str);j++){
            if(*(str+j)==' '){
                mk1 = j;
                if(*(str+j-1)==' '){
                    continue;
                }
                else break;
            }
            if(*(str+j)=='\0'){
                mk2=1;
                break;
            }
            strarr[i][j-mk1] = *(str+j); 
        }
        if(mk2==1) break;
    }
    cout << "name:" << strarr[0] << endl \
    << strarr[1] << endl << strarr[2] << endl \
    << strarr[3] << endl << strarr[4] << endl \
    << strarr[5] << endl << strarr[6] << endl \
    << strarr[7] << endl << strarr[8] << endl \
    << strarr[9] << endl;*/


}