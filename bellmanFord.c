#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define inf 999

typedef struct edge {
    int src;
    int dest;
    int wt;
}edge;

typedef struct graph {
    int v, e;
    edge* edge;
}graph;

graph* createGraph(int v, int e) {
    graph* g = (graph *)malloc(sizeof(graph));
    g->v = v;
    g->e = e;
    g->edge = (edge *)malloc((g->e)*sizeof(edge));
    return g;
}

void printDis(int dis[], int n) {
    printf("vertex    distnace from src");
    for(int i=0;i<n;i++) {
        printf("%d \t\t %d\n",i,dis[i]);
    }
}

void bellmanFord(graph* g, int src) {
    int v = g->v;
    int e = g->e;
    int dis[v];
    for(int i=0;i<v;i++) dis[i] = inf;
    dis[src] = 0;
    for(int i=1;i<=v-1;i++) {
        for(int j=0;j<e;j++) {
            int src = g->edge[j].src;
            int dest = g->edge[j].dest;
            int wt = g->edge[j].wt;
            if(dis[src] != inf && dis[dest]>dis[src]+wt) dis[dest] = dis[src]+wt;
        }
    }
    for(int i=0;i<e;i++) {
        int src = g->edge[i].src;
        int dest = g->edge[i].dest;
        int wt = g->edge[i].wt;
        if(dis[src] != inf && dis[dest]>dis[src]+wt) printf("graph contains negative wait cycle\n");
    }
    printDis(dis, v);
}

int main() {
    int v, e;
    scanf("%d%d",&v,&e);
    graph* g = createGraph(v, e);
    for(int i=0;i<e;i++) {
        scanf("%d",&g->edge[i].src);
        scanf("%d",&g->edge[i].dest);
        scanf("%d",&g->edge[i].wt);
    }
    bellmanFord(g, 0);
}
