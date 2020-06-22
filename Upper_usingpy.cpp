#include<iostream>
#include<cstring>
#define MAXLEN 100
using namespace std;
int main(){
    cout << "input string:";
    char stra[MAXLEN];
    cin >> stra;
    FILE *fi;
    FILE *fi_2;
    int ret;
    char temp[MAXLEN];
    char path[MAXLEN]=".\\upper.py ";
    strcat(path,stra);
    fi = _popen(path, "r");
    fi_2 = fopen("upperstr.dat", "w");
    while((ret=fread(stra, 1, MAXLEN, fi))>0) {
        cout << stra << "!?!" << endl;
        
        //fwrite(stra,1,ret,stdout);//fi_2);
    }
    fclose(fi_2);
    fi_2 = fopen("upperstr.dat", "r");
    while(!feof(fi_2)){
        char temp;
        temp = fgetc(fi_2);
        if(temp<'\n'){
            continue;
        }
        cout << temp;
    }
    fclose(fi_2);
    fclose(fi);
    system("Pause");
    return 0;
}