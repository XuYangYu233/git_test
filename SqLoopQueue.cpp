#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 5 //环形队列的长度
typedef int ElemType;
typedef struct{
    ElemType data[MAXLEN];
    int front, rear;
}SqQueue;           //环形队

void InitQueue(SqQueue *&q){
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

void DestroyQueue(SqQueue *&q){
    free(q);
}

bool QueueEmpty(SqQueue *q){
    return (q->front==q->rear);
}

bool enQueue(SqQueue *&q, ElemType e){
    if((q->rear+1)%MAXLEN==q->front){
        return false;
    }
    q->rear = (q->rear+1) % MAXLEN;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(SqQueue *&q, ElemType &e){
    if(q->front==q->rear){
        return false;
    }
    q->front = (q->front+1) % MAXLEN;
    e = q->data[q->front];
    return true;
}