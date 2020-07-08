#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// 部分代码来自课本
#define MAXSIZE 10000

typedef struct {
    int i, j, di;
} Box;
typedef Box ElemType;
typedef struct {
    Box data[MAXSIZE];
    int top;
} StType;
typedef StType SqStack;

void InitStack(SqStack** s)
{
    *s = (SqStack*)malloc(sizeof(SqStack));
    (*s)->top = -1;
}

void DestroyStack(SqStack* s)
{
    free(s);
}

bool StackEmpty(SqStack* s)
{
    return (s->top == -1);
}

bool Push(SqStack* s, ElemType e)
{
    if (s->top == MAXSIZE - 1) {
        return false;
    }
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack* s, ElemType* e)
{
    if (s->top <= -1) {
        return false;
    }
    *e = s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack* s, ElemType* e)
{
    if (s->top <= -1) {
        return false;
    }
    *e = s->data[s->top];
    return true;
}

int wayout = INT_MAX, count = 0;

void mgpath(int mg[20][20], int xi, int yi, int xe, int ye)
{
    Box path[MAXSIZE], e;
    int i, j, di, i1, j1, k;
    bool find;
    StType* st, *bf;
    InitStack(&st);
    InitStack(&bf);
    e.i = xi;
    e.j = yi;
    e.di = -1;
    Push(st, e);
    mg[xi][yi] = -1;
    while (!StackEmpty(st)) {
        GetTop(st, &e);
        i = e.i;
        j = e.j;
        di = e.di;
        if (i == xe && j == ye) {
            k = 0;
            while (!StackEmpty(st)) {
                Pop(st, &e);
                k++;
                Push(bf, e);
            }
            if (k < wayout) {
                wayout = k;
            }
            count++;
            if (count > 200000) {
                return;
            }
            while (!StackEmpty(bf)) {
                Pop(bf, &e);
                Push(st, e);
            }
            goto LABLE;
        }
        find = false;
        while (di < 3 && !find) {
            di++;
            switch (di) {
            case 0:
                i1 = i - 1;
                j1 = j;
                break;
            case 1:
                i1 = i;
                j1 = j + 1;
                break;
            case 2:
                i1 = i + 1;
                j1 = j;
                break;
            case 3:
                i1 = i;
                j1 = j - 1;
                break;
            }
            if (mg[i1][j1] == 0) {
                find = true;
            }
        }
        if (find) {
            st->data[st->top].di = di;
            e.i = i1;
            e.j = j1;
            e.di = -1;
            Push(st, e);
            mg[i1][j1] = -1;
        } else {
        LABLE:
            Pop(st, &e);
            mg[e.i][e.j] = 0;
        }
    }
    DestroyStack(st);
    return;
}

int main()
{
    int mg[20][20];
    int m, n, i, j, xb, yb, xe, ye, min;
    char temp;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            mg[i][j] = 1;
        }
    }
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        getchar();
        for (j = 1; j <= m; j++) {
            scanf("%c", &temp);
            if (temp == 'S') {
                xb = i;
                yb = j;
                mg[i][j] = 0;
            } else if (temp == 'T') {
                xe = i;
                ye = j;
                mg[i][j] = 0;
            } else if (temp == '.') {
                mg[i][j] = 0;
            }
        }
    }
    mgpath(mg, xb, yb, xe, ye);
    if (wayout == INT_MAX) {
        printf("-1");
    } else {
        printf("%d", wayout - 1);
    }

    return 0;
}