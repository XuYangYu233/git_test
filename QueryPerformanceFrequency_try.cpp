#include<iostream>
#include<Windows.h>
using namespace std;

void sleep_us(float t){
    LARGE_INTEGER t1,t2,tc;
    double time=0;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    while(1){
        QueryPerformanceCounter(&t2);
        time = (double)(t2.QuadPart - t1.QuadPart)*1000*1000/(double)tc.QuadPart;
        if(time >= t){
            break;
        }
    }
}

int main(){
    LARGE_INTEGER t1,t2,tc;
    double time;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);

    sleep_us(735.295837);

    QueryPerformanceCounter(&t2);
    time = (double)(t2.QuadPart - t1.QuadPart)*1000*1000/(double)tc.QuadPart;
    cout << "time=" << time << endl;

    return 0;
}