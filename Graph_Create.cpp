#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAXV 128
#define INF INT_MAX
typedef int InfoType;
typedef struct ANode{
    int adjvex;
    struct ANode *nextarc;
    int weight;
}ArcNode;
typedef struct Vnode{
    InfoType info;
    ArcNode *firstarc;
}VNode;
typedef struct{
    VNode adjlist[MAXV];
    int n, e;
}AdjGraph;

void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e){
    int i,j;
    ArcNode *p;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for(i=0;i<n;i++){
        G->adjlist[i].firstarc = NULL;
    }
    for(i=0;i<n;i++){
        for(j=n-1;j>=0;j--){
            if(A[i][j]!=0 && A[i][j]!=INF){
                p = (ArcNode *)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}

void DispAdj(AdjGraph *G){
    int i;
    ArcNode *p;
    for(i=0;i<G->n;i++){
        p = G->adjlist[i].firstarc;
        printf("%3d", i);
        while(p!=NULL){
            printf("%3d[%d]->",p->adjvex,p->weight);
            p = p->nextarc;
        }
        printf("NULL\n");
    }
}

void DestroyAdj(AdjGraph *&G){
    int i;
    ArcNode *pre, *p;
    for(i=0;i<G->n;i++){
        pre = G->adjlist[i].firstarc;
        if(pre!=NULL){
            p = pre->nextarc;
            while(p!=NULL){
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);
}

typedef struct{
    int no;
    InfoType info;
}VertexType;
typedef struct{
    int edges[MAXV][MAXV];
    int n, e;
    VertexType vexs[MAXV];
}MatGraph;

void Create_MatGraph(MatGraph *g){
    int i,j;
    freopen("MatGraph_try_info.txt", "r", stdin);
    scanf_s("%d %d", &(g->n), &(g->e));
    for(i=0;i<g->n;i++){
        getchar();
        scanf("%d", &g->vexs[i].no);
    }
    for(i=0;i<g->n;i++){
        for(j=0;j<g->n;j++){
            scanf("%d", &g->edges[i][j]);
            if(i==j){
                g->edges[i][j] = 0;
            }
            else if(g->edges[i][j]==0){
                g->edges[i][j] = INF;
            }
        }
    }
    freopen("CON", "r", stdin);
}

/*int main(){
    MatGraph g;
    AdjGraph *G=NULL;
    Create_MatGraph(&g);
    CreateAdj(G, g.edges, g.n, g.e);
    DispAdj(G);
    DestroyAdj(G);

    return 0;
}*/