#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

#include<iostream>
#include<time.h>
#include<chrono>

using namespace std::chrono;

# define TEST_TIMES 50
# define BUFFER_SIZE 128
int Interval_Microseconds=300;

void SleepSelectUS(SOCKET s, int64_t usec)
{
	struct timeval tv;
	fd_set dummy;
	FD_ZERO(&dummy);
	FD_SET(s, &dummy);
	tv.tv_sec = usec / 1000000L;
	tv.tv_usec = usec % 1000000L;
	select(0, 0, 0, &dummy, &tv);
	DWORD err = GetLastError();
	if (err != 0)
		printf("Error : %d", err);
}

void Precision_select()
{
	std::string buffer;
	buffer.assign(BUFFER_SIZE, 0);
	buffer.clear();
	int i = TEST_TIMES;
	uint64_t total_used = 0;
	WORD wVersionRequested = MAKEWORD(1, 0);
	WSADATA wsaData;
	WSAStartup(wVersionRequested, &wsaData);

	SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	while (i) {
		i--;
		steady_clock::time_point time_begin = steady_clock::now();
		SleepSelectUS(s, Interval_Microseconds);
		steady_clock::time_point time_end = steady_clock::now();
		char tmp[128] = {0};
		uint64_t used = duration_cast<microseconds>(time_end - time_begin).count();
		snprintf(tmp, 128, "%s Sleep %d us, time used : %lld us\n",__FUNCTION__, Interval_Microseconds, used);
		total_used += used;
		buffer += tmp;
	}
	closesocket(s);
	printf("%s", buffer.c_str());
	printf("%s Sleep %d us, avatar %lld us\n\n", __FUNCTION__, Interval_Microseconds, total_used / TEST_TIMES);

}

int main(){
    Precision_select();

    return 0;
}