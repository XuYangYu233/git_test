#include<iostream>
#include<string.h>

using namespace std;

int char_shifting(char a){
    if(a>='0' && a<='9'){
        return a-'0';
    }
    else{
        return (10+a-'A');
    }
}

void str_shifting(char *stra,unsigned char *char_arr){
    int lena=0,temp=0;
    lena = strlen(stra);
    short ca_sig=0;
    for(short i=0;i<lena;i++){
        if(i%2 == 1){
            temp = char_shifting(stra[i-1]) * 16 + char_shifting(stra[i]);
            char_arr[ca_sig] = (unsigned char)temp;
            //cout << (int)char_arr[ca_sig] << " ";
            ca_sig++;
        }
    }
    return;
}

int main(){
    FILE *fi=NULL;
    unsigned char char_arr[5000000]={'\0'};
    char stra[]="";
    cout << stra << endl;
    fi = fopen("D:\\Study\\Python_work\\midi_try\\miditry_002.mid","a");
    str_shifting(stra,char_arr);
    //fprintf(fi,char_arr);
    int lenb=0;
    lenb = (strlen(stra)+1)/3;
    for(int i=0;i<lenb;i++){
        fputc(char_arr[i],fi);
    }

    fclose(fi);
    return 0;
}