// pthread_test.cpp: 定义控制台应用程序的入口点。
//
//#include"stdafx.h"
#include<pthread.h>
#include<stdio.h>
#include<Windows.h>
#pragma comment(lib, "pthreadVC2.lib")

//total ticket
int total_ticket = 100;

pthread_mutex_t m_tMutex = PTHREAD_MUTEX_INITIALIZER;
//自带函数
//int pthread_create(pthread_t *pThread, const pthread_attr_t *pAttr, void *(*start_routine)(void*), void *arg);
//int pthread_join(pthread_t tid, void **value_ptr);
//void pthread_exit(void *value_ptr);

void function() {
    printf("this is a thread\n");
}

void* thread_start(void* pram) {
    while (true) {
        
        if (total_ticket > 0) {        
        //    for(; total_ticket > 0;){
        //    Sleep(100);
            //如果把printf合成一句话会出现一直卖零张票的情况。
            //加锁时最好把锁起来的范围缩到最小
            pthread_mutex_lock(&m_tMutex);
            printf("%u窗口卖了第", pthread_self());
            printf("%d张票\n", total_ticket);
        //    pthread_mutex_lock(&m_tMutex);
        //    printf("%d\n", total_ticket);
            total_ticket--;
            Sleep(1000);
            pthread_mutex_unlock(&m_tMutex);
            Sleep(100);
        } else {
            pthread_mutex_unlock(&m_tMutex);
            break;
        }
    }
    return NULL;
}

int main()
{
    function();
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    pthread_t tid4;
    pthread_create(&tid1, NULL, thread_start, NULL);
    pthread_create(&tid2, NULL, thread_start, NULL);
    pthread_create(&tid3, NULL, thread_start, NULL);
    pthread_create(&tid4, NULL, thread_start, NULL);
//以下功能类似，实现方法不同。
//    pthread_join(tid1, NULL);
//    pthread_join(tid2, NULL);
//    pthread_join(tid3, NULL);
//    pthread_join(tid4, NULL);
    pthread_join(pthread_self(), NULL);
    getchar();
    return 0;
}