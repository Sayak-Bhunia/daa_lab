#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct edge {
    int src, dest, wt;
};

struct graph {
    int v, e;
    struct edge *edge;
};

struct graph* createGraph(int v, int e) {
    struct graph* g = (struct graph*) malloc(sizeof(struct graph));
    g->v = v;
    g->e = e;
    g->edge = (struct edge*) malloc(g->e * sizeof(struct edge));
    return g;
}

void printArr(int dis[], int n) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dis[i]);
}

void BellmanFord(struct graph* g, int src) {
    int v = g->v;
    int e = g->e;
    int dist[v];

    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= v - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = g->edge[j].src;
            int v = g->edge[j].dest;
            int wt = g->edge[j].wt;
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    for (int i = 0; i < e; i++) {
        int u = g->edge[i].src;
        int v = g->edge[i].dest;
        int wt = g->edge[i].wt;
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            printf("Graph contains negative weight cycle\n");
    }

    printArr(dist, v);
}

int main() {
    int v, e;
    scanf("%d", &v);
    scanf("%d", &e);
    struct graph* g = createGraph(v, e);

    for (int i = 0; i < e; i++) {
        scanf("%d", &g->edge[i].src);
        scanf("%d", &g->edge[i].dest);
        scanf("%d", &g->edge[i].wt);
    }

    BellmanFord(g, 0);

    free(g->edge);
    free(g);

    return 0;
}
