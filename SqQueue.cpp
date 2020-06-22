#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 128
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int front, rear;
}SqQueue;           //Ë³Ðò¶Ó

void InitQueue(SqQueue *&q){
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
}

void DestroyQueue(SqQueue *&q){
    free(q);
}

bool QueueEmpty(SqQueue *q){
    return (q->front==q->rear);
}

bool enQueue(SqQueue *&q, ElemType e){
    if(q->rear==MAXSIZE-1){
        return false;
    }
    q->rear++;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(SqQueue *&q, ElemType &e){
    if(q->front==q->rear){
        return false;
    }
    q->front++;
    e = q->data[q->front];
    return true;
}