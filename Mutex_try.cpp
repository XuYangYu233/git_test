#include <iostream>  
#include <thread>  
#include <Windows.h>  
#include <mutex>  
  
using namespace std;  
  
mutex mu;  //线程互斥对象  
  
int totalNum = 100;  
  
void thread01()  
{  
    while (totalNum > 0)  
    {  
        thread t_sleep(Sleep,1000);
         //同步数据锁  
        cout << "线程1：此时totalNum为" << totalNum << endl;
        totalNum--;  
        //mu.lock();
        //mu.unlock();
        t_sleep.join();
        //Sleep(1000);  //解除锁定  
    }  
}  
void thread02()  
{  
    while (totalNum > 0)  
    {  
        //thread t_sleep(Sleep,1000);
        if(totalNum%3==0){
            cout << "线程2：此时totalNum为" << totalNum << endl;
            totalNum--;
        }
        //totalNum--;  
        //mu.lock();
        //mu.unlock();
        
        //t_sleep.join();
        //Sleep(1000);   
    }  
}  

int main()  
{  
    thread task01(thread01);  
    //Sleep(500);
    thread task02(thread02);  
    //task01.detach();task02.detach();  

    task01.join();task02.join();
    
    system("pause");  
}  