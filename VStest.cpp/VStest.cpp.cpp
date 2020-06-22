// VStest.cpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <cstring>

#pragma comment(lib, "winmm.lib")

int main()
{
    std::cout << "Hello World!\n";
	mciSendString(TEXT("open \"D:\\Study\\C++_work\\piano\\A1.mp3\" alias A1"), 0, 0, 0);
	mciSendString(TEXT("play A1"), 0, 0, 0);        //MCI命令字符串
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
