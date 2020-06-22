#include<iostream>
using namespace std;

typedef int InfoType;

#define MAXV 128
#define INF 32767
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
    cout << "输入顶点和边数:" << endl;
    scanf("%d %d", &g->n, &g->e);

    cout << "输入顶点信息:" << endl;
    for(i=0;i<g->n;i++){
        getchar();
        scanf("%d", &g->vexs[i].no);
    }

    cout << "输入邻接矩阵:" << endl;
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
}

//Prim算法
void Prim(MatGraph g, int v){
    int lowcost[MAXV];
    int MIN;
    int closest[MAXV], i, j, k;
    for(i=0;i<g.n;i++){
        lowcost[i] = g.edges[v][i];
        closest[i] = v;
    }
    for(i=1;i<g.n;i++){
        MIN = INF;
        for(j=0;j<g.n;j++){
            if(lowcost[j]!=0 && lowcost[j]<MIN){
                MIN = lowcost[j];
                k = j;
            }
        }
        printf("边(%d,%d)权为:%d\n",closest[k],k,MIN);
        lowcost[k] = 0;
        for(j=0;j<g.n;j++){
            if(lowcost[j]!=0 && g.edges[k][j]<lowcost[j]){
                lowcost[j] = g.edges[k][j];
                closest[j] = k;
            }
        }
    }
}

//Kruskal算法
typedef struct{
    int u;
    int v;
    int w;
}Edge;

void InsertSort(Edge E[], int numof_e){         //此处应为插入排序
    for(int i=0;i<numof_e-1;i++){
        for(int j=0;j<numof_e-1;j++){
            if(E[j].w>E[j+1].w){
                Edge temp;
                temp = E[j];
                E[j] = E[j+1];
                E[j+1] = temp;
            }
        }
    }
}

void Kruskal(MatGraph g){
    int i, j, u1, v1, sn1, sn2, k;
    int vset[MAXV];
    Edge E[MAXV];
    k = 0;
    for(i=0;i<g.n;i++){
        for(j=0;j<g.n;j++){
            if(g.edges[i][j]!=0 && g.edges[i][j]!=INF){
                E[k].u = i;
                E[k].v = j;
                E[k].w = g.edges[i][j];
                k++;
            }
        }
    }
    InsertSort(E,g.e);
    for(i=0;i<g.n;i++){
        vset[i] = i;
    }
    k = 1;
    j = 0;
    while(k<g.n){
        u1 = E[j].u;
        v1 = E[j].v;
        sn1 = vset[u1];
        sn2 = vset[v1];
        if(sn1!=sn2){
            printf("边(%d,%d)权为:%d\n", u1, v1, E[j].w);
            k++;
            for(i=0;i<g.n;i++){
                if(vset[i]==sn2){
                    vset[i] = sn1;
                }
            }
        }
        j++;
    }
}

//Dijkstra算法
void Dispath(MatGraph g, int dist[], int path[], int S[], int v){
    int i, j, k;
    int apath[MAXV], d;
    for(i=0;i<g.n;i++){
        if(S[i]==1 && i!=v){
            printf("从顶点%d到顶点%d的路径长度为:%d\t路径为:", v, i, dist[i]);
            d = 0;
            apath[d] = i;
            k = path[i];
            if(k==-1){
                printf("无路径\n");
            }
            else{
                while(k!=v){
                    d++;
                    apath[d] = k;
                    k = path[k];
                }
                d++;
                apath[d] = v;
                printf("%d", apath[d]);
                for(j=d-1;j>=0;j--){
                    printf(",%d", apath[j]);
                }
                printf("\n");
            }
        }
    }
}

void Dijkstra(MatGraph g, int v){
    int dist[MAXV], path[MAXV];
    int S[MAXV];
    int MINdis, i, j, u;
    for(i=0;i<g.n;i++){
        dist[i] = g.edges[v][i];
        S[i] = 0;
        if(g.edges[v][i] < INF){
            path[i] = v;
        }
        else{
            path[i] = -1;
        }
    }
    S[v] = 1;
    path[v] = 0;
    for(i=0;i<g.n-1;i++){
        MINdis = INF;
        for(j=0;j<g.n;j++){
            if(S[j]==0 && dist[j]<MINdis){
                u = j;
                MINdis = dist[j];
            }
        }
        S[u] = 1;
        for(j=0;j<g.n;j++){
            if(S[j]==0){
                if(g.edges[u][j]<INF && dist[u]+g.edges[u][j]<dist[j]){
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
            }
        }
    }
    Dispath(g, dist, path, S, v);
}

//Floyd算法
void Dispath(MatGraph g, int A[][MAXV], int path[][MAXV]){
    int i, j, k, s;
    int apath[MAXV], d;
    for(i=0;i<g.n;i++){
        for(j=0;j<g.n;j++){
            if(A[i][j]!=INF && i!=j){
                printf("从%d到%d的路径为:", i, j);
                k = path[i][j];
                d = 0;
                apath[d] = j;
                while(k!=-1 && k!=i){
                    d++;
                    apath[d] = k;
                    k = path[i][k];
                }
                d++;
                apath[d] = i;
                printf("%d", apath[d]);
                for(s=d-1;s>=0;s--){
                    printf(",%d",apath[s]);
                }
                printf("\t路径长度为:%d\n", A[i][j]);
            }
        }
    }
}

void Floyd(MatGraph g){
    int A[MAXV][MAXV], path[MAXV][MAXV];
    int i, j, k;
    for(i=0;i<g.n;i++){
        for(j=0;j<g.n;j++){
            A[i][j] = g.edges[i][j];
            if(i!=j && g.edges[i][j]<INF){
                path[i][j] = i;
            }
            else{
                path[i][j] = -1;
            }
        }
    }
    for(k=0;k<g.n;k++){
        for(i=0;i<g.n;i++){
            for(j=0;j<g.n;j++){
                if(A[i][j]>A[i][k]+A[k][j]){
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    Dispath(g,A,path);
}

int main(){
    MatGraph g;
    freopen("MatGraph_try_info4.txt", "r", stdin);
    Create_MatGraph(&g);
    cout << "==========Prim==========" << endl;
    Prim(g, 0);
    cout << "==========Kruskal==========" << endl;
    Kruskal(g);
    cout << "==========Dijkstra==========" << endl;
    Dijkstra(g, 0);
    cout << "==========Floyd==========" << endl;
    Floyd(g);

    return 0;
}