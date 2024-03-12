#include<stdio.h>
#define INFINITY 9999
#define m 10

void dijkstra(int graph[m][m], int n, int start) {
    int cost[m][m], distance[m],pred[m];
    int visited[m],c,mndistance,nextnode,i,j;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(graph[i][j] == 0) cost[i][j] = INFINITY;
            else cost[i][j] = graph[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    distance[start]= 0;
    visited[start] = 1;
    c = 1;
    while(c<n-1) {
        mndistance = INFINITY;
        for(int i=0;i<n;i++) {
            if(distance[i]<mndistance && !visited[i]) mndistance = distance[i];
            nextnode = i;
        }
    }
    visited[nextnode] = 1;
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            if(mndistance + cost[nextnode][i]<distance[i]) {
                distance[i] = mndistance + cost[nextnode][i];
                pred[i] = nextnode;
            }
        }
        c++;
    }
    for(int i=0;i<n;i++) {
        if(i != start) printf("\nDistance from source to %d is %d",i,distance[i]);
    }
}

int main()
{
    int i,j,n = 6,u;
    int adjmatrix[6][6] = {{0,1,1,0,0,1},
                       {1,0,1,1,0,0},
                       {1,1,0,1,0,1},
                       {0,1,1,0,1,0},
                       {0,0,0,1,0,1},
                       {1,0,1,0,1,0}};
    int graph[m][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            graph[i][j] = adjmatrix[i][j];
        }
    }
    u = 0;
    dijkstra(graph, n, u);
}
