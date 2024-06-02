// Online C compiler to run C program online
#include<stdio.h>
#define inf 999
#define m 10

int tsp(int n, int a[m][m], int vis[], int c, int cost) {
    int adjv = inf;
    int mn = inf;
    vis[c] = 1;
    printf("%d ",c+1);
    for(int i=0;i<n;i++) {
        if(a[c][i] != inf && vis[i] == 0) {
            if(a[c][i]<mn) mn = a[c][i];
            adjv = i;
        }
    }
    if(mn != inf) cost += mn;
    if(adjv == inf) {
        adjv = 0;
        printf("%d ",adjv+1);
        cost += a[c][adjv];
        return cost;
    }
    return tsp(n, a, vis, adjv, cost);
}

int main() {
    int n = 5;
    int a[m][m] = {
       {12, 30, 33, 10, 45},
       {56, 22, 9, 15, 18},
       {29, 13, 8, 5, 12},
       {33, 28, 16, 10, 3},
       {1, 4, 30, 24, 20}
    };
    int vis[m] = {0};
    int cost = 0;
    printf("\n%d",tsp(n, a, vis, 0, cost));
}
