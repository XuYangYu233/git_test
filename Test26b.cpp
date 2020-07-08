#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// 部分代码来自课本
#define MAXSIZE 10000

typedef struct {
    int i, j;
    int pre;
} Box;
typedef Box ElemType;
typedef struct {
    Box data[MAXSIZE];
    int front, rear;
} QuType;
typedef QuType SqQueue;

void InitQueue(SqQueue **q){
    *q = (SqQueue *)malloc(sizeof(SqQueue));
    (*q)->front = (*q)->rear = -1;
}

void DestroyQueue(SqQueue *q){
    free(q);
}

bool QueueEmpty(SqQueue *q){
    return (q->front==q->rear);
}

bool enQueue(SqQueue *q, ElemType e){
    if(q->rear==MAXSIZE-1){
        return false;
    }
    q->rear++;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(SqQueue *q, ElemType *e){
    if(q->front==q->rear){
        return false;
    }
    q->front++;
    *e = q->data[q->front];
    return true;
}

int wayout = 0;

bool mgpath(int mg[20][20], int xi, int yi, int xe, int ye)
{
    Box e;
    int i, j, di, i1, j1;
    QuType *qu;
    InitQueue(&qu);
    e.i = xi;
    e.j = yi;
    e.pre = -1;
    enQueue(qu, e);
    mg[xi][yi] = -1;
    while (!QueueEmpty(qu)) {
        deQueue(qu, &e);
        i = e.i;
        j = e.j;
        if (i == xe && j == ye) {
            while (e.pre != -1) {
                e = qu->data[e.pre];
                wayout++;
            }
            DestroyQueue(qu);
            return true;
        }
        for (di = 0; di < 4; di++) {
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
                e.i = i1;
                e.j = j1;
                e.pre = qu->front;
                enQueue(qu, e);
                mg[i1][j1] = -1;
            }
        }
    }
    DestroyQueue(qu);
    return false;
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
    
    if (!mgpath(mg, xb, yb, xe, ye)) {
        printf("-1");
    } else {
        printf("%d", wayout);
    }

    return 0;
}