#include<stdio.h>
#include<windows.h>
int main(){
    const int one = 600;//一拍
    const int half = 300;//半拍
    const int four_one = 150;//1/4拍
    const int onedot = 450;//附点音符
    //note 定义音符
    const int mnote1 = 440;//do
    const int mnote2 = 495;//re
    const int mnote3 = 550;//mi
    const int mnote4 = 587;//fa
    const int mnote5 = 660;//so
    const int mnote6 = 733;//la
    const int mnote7 = 825;//si
    const int lnote5 = 325;
    //music 两只老虎
    Beep(mnote1, one);
    Beep(mnote2, one);
    Beep(mnote3, one);
    Beep(mnote1, one);
    Beep(mnote1, one);
    Beep(mnote2, one);
    Beep(mnote3, one);
    Beep(mnote1, one);
    Beep(mnote3, one);
    Beep(mnote4, one);
    Beep(mnote5, one);
    Sleep(one);
    Beep(mnote3, one);
    Beep(mnote4, one);
    Beep(mnote5, one);
    Sleep(one);
    Beep(mnote5, onedot);
    Beep(mnote6, four_one);
    Beep(mnote5, onedot);
    Beep(mnote4, four_one);
    Beep(mnote3, one);
    Beep(mnote1, one);
    Beep(mnote5, onedot);
    Beep(mnote6, four_one);
    Beep(mnote5, onedot);
    Beep(mnote4, four_one);
    Beep(mnote3, one);
    Beep(mnote1, one);
    Beep(mnote3, one);
    Beep(lnote5, one);
    Beep(mnote1, one);
    Sleep(one);
    Beep(mnote3, one);
    Beep(lnote5, one);
    Beep(mnote1, one);
    system("pause");
}