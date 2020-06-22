#include <iostream>
#include <thread>
#include <Windows.h>
#include <conio.h>

#pragma comment(lib, "winmm.lib")

void plays(char mingwen){
    if (mingwen == 'a')
    {
        printf("sss!!!\n");
        //char oppath[100]="open \"D:\\Study\\C++_work\\piano\\%s.mp3\" alias %s";
        char oppath[100] = "open piano\\%s.mp3 alias %s";
        char temp[100];
        sprintf(temp, oppath, "A1", "A1");
        mciSendStringA(temp, 0, 0, 0);
        sprintf(temp, "play %s", "A1");
        mciSendStringA(temp, 0, 0, 0);
        Sleep(5000);
        sprintf(temp, "close %s", "A1");
        mciSendStringA(temp, 0, 0, 0);
    }
    if (mingwen != 'a')
    {
        std::this_thread::yield();
    }
    printf("end111\n");
}

int main(){
    char key = '0';
    while (key != '8'){
        key = getch();
        if (key == '8'){
            break;
        }
        if (key == 'a'){
            std::thread t(plays, 'a');
            t.join();
            //t.detach();
        }
        if (key == 's'){
            std::thread t(plays, 'b');
            t.detach();
        }
    }
    char c;
    c = _getch();
    std::cout << c + 1 << std::endl;
    system("PAUSE");
    return 0;
}