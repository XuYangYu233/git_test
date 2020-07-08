#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int bo;
} Zhadan;

int n, m, x = 0;
Zhadan p[100];

void DFS(Zhadan boom, int k)
{
    for (int i = 0; i < x; i++) {
        if (i != k && p[i].bo == 1 && (boom.x == p[i].x || boom.y == p[i].y)) {
            p[i].bo = 0;
            DFS(p[i], i);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            scanf("%1d", &tmp);
            if (tmp) {
                p[x].x = i;
                p[x].y = j;
                p[x].bo = 1;
                x++;
            }
        }
    }
    for (int i = 0; i < x; i++) {
        if (p[i].bo) {
            num++;
            DFS(p[i], i);
        }
    }
    printf("%d", num);
    return 0;
}