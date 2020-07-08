#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char qipan[50];
    int n;
    int mid;
}Tiaoqi;

typedef struct {
    Tiaoqi data;
    int pre;
}Node;

void exchange(Tiaoqi *temp, int a, int b)
{
    char ch;
    ch = temp->qipan[a];
    temp->qipan[a] = temp->qipan[b];
    temp->qipan[b] = ch;
}

void bfs(Tiaoqi *tq, int *arr, int *len)
{
    Tiaoqi temp;
    Node trans, next;
    Node queue[10000];
    int front = -1, rear = -1;
    int i, j, out_flag;
    rear++;
    trans.data = *tq;
    trans.pre = -1;
    queue[rear] = trans;
    
    while (front != rear) {
        front++;
        trans = queue[front];
        
        out_flag = 1;
        for (i = 0; i < trans.data.n; i++) {
            if (trans.data.qipan[i] == 'W') {
                out_flag = 0;
            }
        }
        if (trans.data.qipan[trans.data.n] != ' ') {
            out_flag = 0;
        }
        for (i = trans.data.n + 1; i < trans.data.n * 2 + 1; i++) {
            if (trans.data.qipan[i] == 'B') {
                out_flag = 0;
            }
        }
        
        if (out_flag == 1) {
            j = 0;
            while (trans.pre != -1) {
                arr[j++] = trans.data.mid;
                
                trans = queue[trans.pre];
            }
            *len = j;
            return;
        }
        
        if (trans.data.mid > 0 && trans.data.qipan[trans.data.mid - 1] != 'B') {
            temp = trans.data;
            exchange(&temp, temp.mid, temp.mid - 1);
            temp.mid--;
            rear++;
            next.data = temp;
            next.pre = front;
            queue[rear] = next;
        }
        if (trans.data.mid < 2 * trans.data.n && trans.data.qipan[trans.data.mid + 1] != 'W') {
            temp = trans.data;
            exchange(&temp, temp.mid, temp.mid + 1);
            temp.mid++;
            rear++;
            next.data = temp;
            next.pre = front;
            queue[rear] = next;
        }
        if (trans.data.mid > 1 && trans.data.qipan[trans.data.mid - 1] != trans.data.qipan[trans.data.mid - 2] && trans.data.qipan[trans.data.mid - 2] != 'B') {
            temp = trans.data;
            exchange(&temp, temp.mid, temp.mid - 2);
            temp.mid -= 2;
            rear++;
            next.data = temp;
            next.pre = front;
            queue[rear] = next;
        }
        if (trans.data.mid < 2 * trans.data.n - 1 && trans.data.qipan[trans.data.mid + 1] != trans.data.qipan[trans.data.mid + 2] && trans.data.qipan[trans.data.mid + 2] != 'W') {
            temp = trans.data;
            exchange(&temp, temp.mid, temp.mid + 2);
            temp.mid += 2;
            rear++;
            next.data = temp;
            next.pre = front;
            queue[rear] = next;
        }
    }
}

int main()
{
    int i, len, cnt;
    int arr[1000];
    Tiaoqi *tq;
    tq = (Tiaoqi *)calloc(1, sizeof(Tiaoqi));
    scanf("%d", &(tq->n));
    tq->mid = tq->n;
    for (i = 0 ; i < 2 * tq->n + 1; i++) {
        if (i < tq->n) {
            tq->qipan[i] = 'W';
        } else if (i > tq->n) {
            tq->qipan[i] = 'B';
        } else {
            tq->qipan[i] = ' ';
        }
    }
    bfs(tq, arr, &len);
    cnt = 0;
    for (i = len - 1; i >= 0; i--) {
        printf("%d",arr[i] + 1);
        cnt++;
        if (cnt % 5 == 0) {
            printf("\n");
            cnt = 0;
        } else {
            printf(" ");
        }
    }
    
    return 0;
}