#include<stdio.h>
#include<stdlib.h>

#include"BinTree.cpp"

void PreOrder(BTNode *b){
    if(b!=NULL){
        printf("%c", b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

void InOrder(BTNode *b){
    if(b!=NULL){
        InOrder(b->lchild);
        printf("%c", b->data);
        InOrder(b->rchild);
    }
}

void PostOrder(BTNode *b){
    if(b!=NULL){
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c", b->data);
    }
}

#define MAXSIZE 128
//typedef BTNode* ElemType;
#define ElemType BTNode*
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SqStack;

static void InitStack(SqStack *&s){
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

static void DestroyStack(SqStack *&s){
    free(s);
}

static bool StackEmpty(SqStack *s){
    return (s->top==-1);
}

static bool Push(SqStack *&s, ElemType e){
    if(s->top==MAXSIZE-1){
        return false;
    }
    s->top++;
    s->data[s->top] = e;
    return true;
}

static bool Pop(SqStack *&s, ElemType &e){
    if(s->top==-1){
        return false;
    }
    e = s->data[s->top];
    s->top--;
    return true;
}

static bool GetTop(SqStack *s, ElemType &e){
    if(s->top==-1){
        return false;
    }
    e = s->data[s->top];
    return true;
}

void PreOrder1(BTNode *b){
    BTNode *p;
    SqStack *st;
    InitStack(st);
    if(b!=NULL){
        Push(st, b);
        while(!StackEmpty(st)){
            Pop(st, p);
            printf("%c", p->data);
            if(p->rchild!=NULL){
                Push(st, p->rchild);
            }
            if(p->lchild!=NULL){
                Push(st, p->lchild);
            }
        }
        printf("\n");
    }
    DestroyStack(st);
}

void PreOrder2(BTNode *b){
    BTNode *p;
    SqStack *st;
    InitStack(st);
    p = b;
    while(!StackEmpty(st) || p!=NULL){
        while(p!=NULL){
            printf("%c", p->data);
            Push(st, p);
            p = p->lchild;
        }
        if(!StackEmpty(st)){
            Pop(st, p);
            p = p->rchild;
        }
    }
    printf("\n");
    DestroyStack(st);
}

void InOrder1(BTNode *b){
    BTNode *p;
    SqStack *st;
    InitStack(st);
    p = b;
    while(!StackEmpty(st) || p!=NULL){
        while(p!=NULL){
            Push(st, p);
            p = p->lchild;
        }
        if(!StackEmpty(st)){
            Pop(st, p);
            printf("%c", p->data);
            p = p->rchild;
        }
    }
    printf("\n");
    DestroyStack(st);
}

void PostOrder1(BTNode *b){
    BTNode *p, *r;
    bool flag;
    SqStack *st;
    InitStack(st);
    p = b;
    do{
        while(p!=NULL){
            Push(st, p);
            p = p->lchild;
        }
        r = NULL;
        flag = true;
        while(!StackEmpty(st) && flag){
            GetTop(st, p);
            if(p->rchild==r){
                printf("%c", p->data);
                Pop(st, p);
                r = p;
            }
            else{
                p = p->rchild;
                flag = false;
            }
        }
    }while(!StackEmpty(st));
    printf("\n");
    DestroyStack(st);
}

#define MAXLEN 5 //环形队列的长度
typedef struct{
    ElemType data[MAXLEN];
    int front, rear;
}SqQueue;           //环形队

static void InitQueue(SqQueue *&q){
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

static void DestroyQueue(SqQueue *&q){
    free(q);
}

static bool QueueEmpty(SqQueue *q){
    return (q->front==q->rear);
}

static bool enQueue(SqQueue *&q, ElemType e){
    if((q->rear+1)%MAXLEN==q->front){
        return false;
    }
    q->rear = (q->rear+1) % MAXLEN;
    q->data[q->rear] = e;
    return true;
}

static bool deQueue(SqQueue *&q, ElemType &e){
    if(q->front==q->rear){
        return false;
    }
    q->front = (q->front+1) % MAXLEN;
    e = q->data[q->front];
    return true;
}

void LevelOrder(BTNode *b){
    BTNode *p;
    SqQueue *qu;
    InitQueue(qu);
    enQueue(qu, b);
    while(!QueueEmpty(qu)){
        deQueue(qu, p);
        printf("%c", p->data);
        if(p->lchild!=NULL){
            enQueue(qu, p->lchild);
        }
        if(p->rchild!=NULL){
            enQueue(qu, p->rchild);
        }
    }
}