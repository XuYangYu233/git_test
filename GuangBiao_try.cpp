#include<iostream>
#include<Windows.h>
using namespace std;
void gotoxy(int,int);
int main(){
    int i=0;
    for(i=0;i<15;i++){
        if(i==0||i==14){
            gotoxy(0,i);
            for(short j=0;j<=40;j++){
                cout << '-';
            }
        }
        else{
            gotoxy(0,i);
            cout << "|";
            
            gotoxy(15,i);
            printf("hello world!%d",i);
            gotoxy(40,i);
            cout << '|';
        }
    }
    system("PAUSE");
}

void gotoxy(int x,int y){
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
