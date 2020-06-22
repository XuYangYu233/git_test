#include<iostream>

#include"Graph_Create.cpp"
#include"SqLoopQueue.cpp"

int visited[MAXV]={0};
//vÎªÆðµã
void DFS(AdjGraph *G, int v){
    ArcNode *p;
    visited[v] = 1;
    printf("%2d", v);
    p = G->adjlist[v].firstarc;
    while(p!=NULL){
        if(visited[p->adjvex]==0){
            DFS(G, p->adjvex);
        }
        p = p->nextarc;
    }
}

void BFS(AdjGraph *G, int v){
    int w, i;
    ArcNode *p;
    SqQueue *qu;
    InitQueue(qu);
    /*int visited[MAXV];
    for(i=0;i<G->n;i++){
        visited[i] = 0;
    }*/
    printf("%2d", v);
    visited[v] = 1;
    enQueue(qu, v);
    while(!QueueEmpty(qu)){
        deQueue(qu, w);
        p = G->adjlist[w].firstarc;
        while(p!=NULL){
            if(visited[p->adjvex]==0){
                printf("%2d",p->adjvex);
                visited[p->adjvex] = 1;
                enQueue(qu, p->adjvex);
            }
            p = p->nextarc;
        }
    }
    printf("\n");
}

int main(){
    MatGraph g;
    AdjGraph *G=NULL;
    Create_MatGraph(&g);
    CreateAdj(G, g.edges, g.n, g.e);
    DispAdj(G);
    //DFS(G, 0);
    BFS(G, 0);

    return 0;
}