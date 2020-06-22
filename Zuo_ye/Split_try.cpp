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
    strcpy(str,"MATLAB及其应用   1.0   余磊   副教授   电子信息学院   自然与工程类   2019   1   周一:1-10周,每1周11-12节,1区,3-303   无");
    temp = strtok(str,"   ");
    int i=0;
    while(temp!=NULL){
        strcpy(strarr[i],temp);
        cout << strarr[i] <<endl;
        i++;
        temp = strtok(NULL,"   ");
    }//记住strtok这个函数！！！下面这些就是不知道strtok的后果————搞了很多复杂的东西还是搞不出来
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