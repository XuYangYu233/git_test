#include<pthread.h>
#include<semaphore.h>
#include<stdio.h> 
#include<Windows.h>
#pragma comment(lib, "pthreadVC2.lib")     //����������
pthread_t t1;           //pthread_t����t1�����ڻ�ȡ�߳�1��ID
pthread_t t2;           //pthread_t����t2�����ڻ�ȡ�߳�2��ID       
pthread_mutex_t mutex;
pthread_cond_t cond;
int i=0;                //������Դ
void * child1(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		i++;
		if(i%5==0)
		{
			pthread_cond_broadcast(&cond);
		}
		else
		{
			printf("�����߳�  1  ��ӡ��������5�ı���:  %d \n",i);
		}
		pthread_mutex_unlock(&mutex);
		Sleep(1000);
	}
}      
void *child2(void *arg)
{
    while(1)
	{
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond,&mutex);       //����ź�֮ǰ�������»�û�����
		printf("�����߳�  2  ��ӡ5�ı���:  %d \n",i);
		pthread_mutex_unlock(&mutex);          //��Ҫ�ڴ˴��ͷŻ�����
		Sleep(0);
	}
}
int main(void)
{

    pthread_cond_init(&cond,NULL);
	pthread_mutex_init(&mutex,NULL); 
    pthread_create(&t1,NULL,child1,NULL);
    pthread_create(&t2,NULL,child2,NULL);
    Sleep(100000000);

}
