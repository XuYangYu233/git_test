#include<iostream>
#include<cstdlib>
using namespace std;
int main(int argc,char *argv[]){
    FILE *in,*out;
    char ch;

    cout << endl << "文件复制程序" << endl << endl;

    if(argc!=3){
        cout << "命令行格式错误" << endl;
        exit(1);
    }

    if((in=fopen(argv[1],"r"))==NULL){
        cout << "打开源文件错误" << endl;
        exit(1);
    }
    
    if ((out=fopen(argv[2],"w"))==NULL){
        cout << "打开目标文件错误" << endl;
        exit(1);
    }
    
    cout << "文件复制中. . .\n" << endl;
    while (!feof(in)){
        ch = fgetc(in);
        if(!feof(in)){
            fputc(ch,out);
        }
    }
    cout << "文件复制完成" << endl;

    fclose(in);
    fclose(out);

    return 0;   
}