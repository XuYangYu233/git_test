#include<iostream>
#include<cstdlib>
using namespace std;
int main(int argc,char *argv[]){
    FILE *in,*out;
    char ch;

    cout << endl << "�ļ����Ƴ���" << endl << endl;

    if(argc!=3){
        cout << "�����и�ʽ����" << endl;
        exit(1);
    }

    if((in=fopen(argv[1],"r"))==NULL){
        cout << "��Դ�ļ�����" << endl;
        exit(1);
    }
    
    if ((out=fopen(argv[2],"w"))==NULL){
        cout << "��Ŀ���ļ�����" << endl;
        exit(1);
    }
    
    cout << "�ļ�������. . .\n" << endl;
    while (!feof(in)){
        ch = fgetc(in);
        if(!feof(in)){
            fputc(ch,out);
        }
    }
    cout << "�ļ��������" << endl;

    fclose(in);
    fclose(out);

    return 0;   
}