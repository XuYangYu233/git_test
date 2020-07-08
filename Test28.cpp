#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 505
#define INF INT_MAX
typedef int InfoType;
typedef struct ANode {
    int adjvex;
    struct ANode* nextarc;
    int weight;
} ArcNode;
typedef struct Vnode {
    InfoType info;
    ArcNode* firstarc;
} VNode;
typedef struct {
    VNode adjlist[MAXV];
    int n, e;
} AdjGraph;

void CreateAdj(AdjGraph** G, int A[MAXV][MAXV], int n, int e)
{
    int i, j;
    ArcNode* p;
    *G = (AdjGraph*)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++) {
        (*G)->adjlist[i].firstarc = NULL;
    }
    for (i = 0; i < n; i++) {
        for (j = n - 1; j >= 0; j--) {
            if (A[i][j] != 0 && A[i][j] != INF) {
                p = (ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = (*G)->adjlist[i].firstarc;
                (*G)->adjlist[i].firstarc = p;
            }
        }
    }
    (*G)->n = n;
    (*G)->e = e;
}

void DispAdj(AdjGraph* G)
{
    int i;
    ArcNode* p;
    for (i = 0; i < G->n; i++) {
        p = G->adjlist[i].firstarc;
        printf("%3d:", i);
        while (p != NULL) {
            printf("%3d[%d]->", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("NULL\n");
    }
}

void DestroyAdj(AdjGraph* G)
{
    int i;
    ArcNode *pre, *p;
    for (i = 0; i < G->n; i++) {
        pre = G->adjlist[i].firstarc;
        if (pre != NULL) {
            p = pre->nextarc;
            while (p != NULL) {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);
}

int visited[MAXV] = { 0 };
//vÎªÆðµã
void DFS(AdjGraph* G, int v)
{
    ArcNode* p;
    visited[v] = 1;
    p = G->adjlist[v].firstarc;
    while (p != NULL) {
        if (visited[p->adjvex] == 0) {
            DFS(G, p->adjvex);
        }
        p = p->nextarc;
    }
}

int main()
{
    int n, m, i, j, k, gn, ge = 0, count;
    int mat[MAXV][MAXV];
    char zhadan[505][505];
    AdjGraph* G;
    scanf("%d %d", &n, &m);
    gn = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%c", &zhadan[i][j]);
            if (zhadan[i][j] == '\n') {
                j--;
            } else if (zhadan[i][j] == '1') {
                zhadan[i][j] = gn + 1;
                gn++;
            } else {
                zhadan[i][j] = 0;
            }
        }
    }
    for (i = 0; i < gn; i++) {
        for (j = 0; j < gn; j++) {
            mat[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (zhadan[i][j] != 0) {
                for (k = 0; k < n; k++) {
                    if (zhadan[i][k] != 0 && k != j) {
                        mat[zhadan[i][j] - 1][zhadan[i][k] - 1] = 1;
                        mat[zhadan[i][k] - 1][zhadan[i][j] - 1] = 1;
                    }
                }
                for (k = 0; k < m; k++) {
                    if (zhadan[k][j] != 0 && k != i) {
                        mat[zhadan[k][j] - 1][zhadan[i][j] - 1] = 1;
                        mat[zhadan[i][j] - 1][zhadan[k][j] - 1] = 1;
                    }
                }
            }
        }
    }

    CreateAdj(&G, mat, gn, ge);
    DispAdj(G);
    count = 0;
    for (i = 0; i < gn; i++) {
        if (visited[i] == 0) {
            DFS(G, i);
            count++;
        }
    }
    printf("%d", count);

    return 0;
}