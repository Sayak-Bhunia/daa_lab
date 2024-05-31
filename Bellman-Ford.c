// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define inf 999

struct edge {
    int src, dest, wt;
};

struct graph {
    int v, e;
    struct edge *edge;
};

struct graph* createGraph(int v, int e) {
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    g->v = v;
    g->e = e;
    g->edge = (struct edge*)malloc((g->e)*sizeof(struct edge));
    return g;
}

void printDis(int dis[], int n) {
    printf("vertex    distnace from src");
    for(int i=0;i<n;i++) {
        printf("%d \t\t %d\n",i,dis[i]);
    }
}

void bellmanFord(struct graph* g, int src) {
    int v = g->v;
    int e = g->e;
    int dis[v];
    for(int i=0;i<v;i++) dis[i] = inf;
    dis[src] = 0;
    for(int i=1;i<=v-1;i++) {
        for(int j=0;j<e;j++) {
            int u = g->edge[j].src;
            int v = g->edge[j].dest;
            int wt = g->edge[j].wt;
            if(dis[u] != inf && dis[v]>dis[u]+wt) dis[v] = dis[u]+wt;
        }
    }
    for(int i=0;i<e;i++) {
            int u = g->edge[i].src;
            int v = g->edge[i].dest;
            int wt = g->edge[i].wt;
            if(dis[u] != inf && dis[v]>dis[u]+wt) printf("graph contains negative wt cycle\n");
    }
    printDis(dis, v);
}

int main() {
    int v, e;
    scanf("%d%d",&v,&e);
    struct graph* g = createGraph(v, e);
    for(int i=0;i<e;i++) {
        scanf("%d",&g->edge[i].src);
        scanf("%d",&g->edge[i].dest);
        scanf("%d",&g->edge[i].wt);
    }
    bellmanFord(g, 0);
}
