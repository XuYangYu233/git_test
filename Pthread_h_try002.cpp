// pthread_test.cpp: �������̨Ӧ�ó������ڵ㡣
//
//#include"stdafx.h"
#include<pthread.h>
#include<stdio.h>
#include<Windows.h>
#pragma comment(lib, "pthreadVC2.lib")

//total ticket
int total_ticket = 100;

pthread_mutex_t m_tMutex = PTHREAD_MUTEX_INITIALIZER;
//�Դ�����
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
            //�����printf�ϳ�һ�仰�����һֱ������Ʊ�������
            //����ʱ��ð��������ķ�Χ������С
            pthread_mutex_lock(&m_tMutex);
            printf("%u�������˵�", pthread_self());
            printf("%d��Ʊ\n", total_ticket);
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
//���¹������ƣ�ʵ�ַ�����ͬ��
//    pthread_join(tid1, NULL);
//    pthread_join(tid2, NULL);
//    pthread_join(tid3, NULL);
//    pthread_join(tid4, NULL);
    pthread_join(pthread_self(), NULL);
    getchar();
    return 0;
}