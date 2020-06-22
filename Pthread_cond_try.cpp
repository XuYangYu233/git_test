#include<pthread.h>
#include<semaphore.h>
#include<stdio.h> 
#include<Windows.h>
#pragma comment(lib, "pthreadVC2.lib")     //必须加上这句
pthread_t t1;           //pthread_t变量t1，用于获取线程1的ID
pthread_t t2;           //pthread_t变量t2，用于获取线程2的ID       
pthread_mutex_t mutex;
pthread_cond_t cond;
int i=0;                //共享资源
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
			printf("我是线程  1  打印的数都非5的倍数:  %d \n",i);
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
		pthread_cond_wait(&cond,&mutex);       //获得信号之前，会重新获得互斥锁
		printf("我是线程  2  打印5的倍数:  %d \n",i);
		pthread_mutex_unlock(&mutex);          //需要在此处释放互斥锁
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
