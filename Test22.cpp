#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 128000
typedef int ElemType;
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
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *s, ElemType *e){
    if(s->top==-1){
        return false;
    }
    *e = s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack *s, ElemType *e){
    if(s->top==-1){
        return false;
    }
    *e = s->data[s->top];
    return true;
}

void ShellSort(ii R[], int n){
    int i,j,d;
    ii tmp;
    d = n / 2;
    while(d > 0){
        for(i=d;i<n;i++){
            tmp = R[i];
            j = i - d;
            while(j>=0 && tmp.a<R[j].a){
                R[j+d] = R[j];
                j = j - d;
            }
            R[j+d] = tmp;
        }
        d = d / 2;
    }
}

int main()
{
    char stra[50005];
    int i = 1, len, temp, count = 0;
    ii restore[25005];
    SqStack *st;
    scanf("%s", stra);
    InitStack(&st);
    len = strlen(stra);
    while (i < len+1) {
        if (stra[i - 1] == '(') {
            Push(st, i);
        } else if (stra[i - 1] == ')') {
            if (StackEmpty(st)) {
                printf("No???%d", i);
                return 0;
            }
            Pop(st, &temp);
            restore[count].a = temp;
            restore[count].b = i;
            count++;
            //printf("%d %d\n", temp, i);
        }
        i++;
    }
    if (StackEmpty(st)) {
        printf("Yes\n");
    } else {
        printf("No!!!");
        return 0;
    }
    ShellSort(restore, count);
    for (i = 0; i < count; i++) {
        printf("%d %d\n", restore[i].a, restore[i].b);
    }
    
    return 0;
}