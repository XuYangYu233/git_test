#include<iostream>
using namespace std;
int main(){
    FILE *fi;
    unsigned char ch,ch2;
    short count=1;
    fi = fopen("D:\\Study\\Python_work\\midi_try\\miditry_001.mid","rb");
    //cout << count << '.';
    while(1){
        ch = fgetc(fi);
        printf("%02X ",ch);
        ch2 = fgetc(fi);
        if(feof(fi)){
            break;
        }
        else{
            fseek(fi,-1,SEEK_CUR);
        }
        /*if(ch<'!'&&ch!='\n'&&ch!='\0'&&ch!=' '){
            continue;
        }*/
        //cout << ch;
        
        /*if(ch=='\n'){
            count++;
            cout << count << '.';
        }*/
        
    }
    system("PAUSE");
    //cout << '\0' << endl;
}