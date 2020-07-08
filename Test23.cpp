#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 25000
typedef char ElemType[100];
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SqStack;

typedef struct{
    int a, b;
}ii;

void InitStack(SqStack **s){
    *s = (SqStack *)malloc(sizeof(SqStack));
    (*s)->top = -1;
}

void DestroyStack(SqStack *s){
    free(s);
}

bool StackEmpty(SqStack *s){
    return (s->top==-1);
}

bool Push(SqStack *s, ElemType e){
    if(s->top==MAXSIZE-1){
        return false;
    }
    s->top++;
    strcpy(s->data[s->top], e);
    //s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *s, ElemType e){
    if(s->top==-1){
        return false;
    }
    strcpy(e, s->data[s->top]);
    //*e = s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack *s, ElemType e){
    if(s->top==-1){
        return false;
    }
    strcpy(e, s->data[s->top]);
    //*e = s->data[s->top];
    return true;
}

int main()
{
    char stra[120], temp[120];
    int i, n, count = 0;
    SqStack *st, *bf;
    scanf("%d", &n);
    InitStack(&st);
    InitStack(&bf);
    for (i = 0; i < n; i++) {
        scanf("%s", stra);
        if (!strcmp(stra, "VISIT")) {
            scanf("%s", stra);
            Push(st, stra);
            printf("%s\n", stra);
            DestroyStack(bf);
            InitStack(&bf);
        } else if (!strcmp(stra, "BACK")) {
            if (StackEmpty(st)) {
                printf("Ignore\n");
            } else {
                Pop(st, temp);
                if (StackEmpty(st)) {
                    printf("Ignore\n");
                    Push(st, temp);
                } else {
                    Push(bf, temp);
                    GetTop(st, temp);
                    printf("%s\n", temp);
                }
            }
            //printf("%d %d\n", temp, i);
        } else if (!strcmp(stra, "FORWARD")) {
            if (StackEmpty(bf)) {
                printf("Ignore\n");
            } else {
                Pop(bf, temp);
                printf("%s\n", temp);
                Push(st, temp);
            }
        }
    }
    
    return 0;
}