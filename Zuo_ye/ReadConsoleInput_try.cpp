#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;
int main(){
    HANDLE hand_in=GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD keyrec;
    DWORD nomeaning;
    short flag=1;
    while(1){
        ReadConsoleInput(hand_in,&keyrec,3,&nomeaning);
        char c;
        c = _getch();
        if(keyrec.EventType==KEY_EVENT){
            if(keyrec.Event.KeyEvent.bKeyDown==0){
                flag = 1;
            }
            if(keyrec.Event.KeyEvent.bKeyDown==1){
                flag = 0;
            }
        }
        if(flag==1){
            cout << " !!!    " << c;
        }
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    }
}