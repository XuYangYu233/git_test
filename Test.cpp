#include<iostream>
#include<cstring>
#include<cmath>
#include<windows.h>
#include<conio.h>
#include<process.h>
using namespace std;
void readf(FILE *fi){
    
    for(int i=0;i<20;i++){
        char p=fgetc(fi);
        cout << p;
        //char s[20];
        //fscanf(fi,"%s",s);
        //cout << s << "  ";
    }
    
}

void get_filename(char *path, char *name)
{
    int i,j = 0;
    for(i = 0; path[i]; i ++)
        if(path[i] == '\\') j = i;
    strcpy(name, &path[j]);
    cout << name << endl;
} //meaningless!!

int main(){
    char stra[]="%";
    char strb[]="d";
    char strc[]="10";
    char strd[20]="111";
    char stre[100];
    int arra[5]={1,3,5,6,2};
    int arrb[5];
    strcat(strc,strb);
    strcat(stra,strc);
    int a;
    FILE *fi;fi = fopen("result.dat","r");
    readf(fi);
    short token=0;
    while(token++<20){
        char ttt=fgetc(fi);
        cout << ttt;
    }
    a = sqrt(2000);
    cout << stra << "  !!!  " << a << "  !!!!  " << strlen(strd) << endl;
    printf(stra,123);
    putchar('\n');
    FILE *fi2;
    fi2 = _popen("dir .\\piano","r");
    while(!feof(fi2)){
        fscanf(fi2,"%s",stre);
        if(strstr(stre,".dat")!=NULL){
            cout << stre << "?!!!!" << endl;
        }
    }
    //
    char dir[5][30];
    //fread(stre,1,10000,fi2);
    //cout << stre << endl;
    //readf(fi);
    cout << sizeof(dir) << endl;
    char sss='a',ssb='b';
    cout << "Input:";
    //sss=_getch();
    //ssb=_getch();
    cout << (int)sss << (int)ssb << endl;
    bool x=1,y=1;
    cout << "boll:" << x+y*6 <<endl;
    system("pause");
    //Beep(500,400);
    cout << "end???" << endl;
    
    return 0;
}