#include <windows.h>
#include <iostream>
#include <mmsystem.h>
#include <cstring>

#pragma comment(lib, "winmm.lib")            //For MCI(Media Control Interface，媒体控制接口)-lunp libwinmm.a libcap.a
 

/*void PlayMp3()//cannot find -lunp
{
    char buf[128];
    char str[128] = {0 };
    int i = 0;
//use mciSendCommand
    MCI_OPEN_PARMS mciOpen;
    MCIERROR mciError;
//SetWindowText(NULL,"12345");
    mciOpen.lpstrDeviceType = "mpegvideo";
    mciOpen.lpstrElementName = "c:\\WELCOME.WAV";
    mciError = mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,(DWORD)&mciOpen);
    if(mciError)
    {
        mciGetErrorString(mciError,buf,128);
        printf("send MCI_OPEN command failed:%s\n",buf);
        return;
    }
    UINT DeviceID = mciOpen.wDeviceID ;
    MCI_PLAY_PARMS mciPlay;
    mciError = mciSendCommand(DeviceID,MCI_PLAY,0 ,(DWORD)&mciPlay);
    if(mciError)
    {
        printf("send MCI_PLAY command failed\n");
        return;
    }// -Wunknown-pragmas 
}*/

int main(int argc, char *argv[])
{
    //文件类型能够是:mp3、wav、avi等
    mciSendString(TEXT("open \"D:\\Study\\C++_work\\piano\\A1.mp3\" alias A1"),0,0,0);
    mciSendString(TEXT("play A1"),0,0,0);        //MCI命令字符串
                                        //存放反馈信息的缓冲区
                                            //缓冲区的长度
                                        //回调窗体的句柄，一般为NULL
    Sleep(50000);                            //等待声音播放
    mciSendString(TEXT("close A1"), 0, 0, 0);
    /*FILE *fi;
    int ret;
    char path[100]=".\\Music_play.py ";
    strcat(path,"A1");
    fi = popen(path,"r");*/
    
    return 0;
}
