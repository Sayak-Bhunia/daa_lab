// Online C compiler to run C program online
#include <stdio.h>
#define inf 9999
#define m 10

void dijkstra(int a[m][m], int n, int st) {
    int cost[m][m], dis[m], pred[m];
    int vis[m], mndis, c, next;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(a[i][j] == 0) cost[i][j] = inf;
            else cost[i][j] = a[i][j];
        }
    }
    
    for(int i=0;i<n;i++) {
        dis[i] = cost[st][i];
        pred[i] = st;
        vis[i] = 0;
    }
    
    dis[st] = 0;
    vis[st] = 1;
    c = 1;
    
    while(c<n-1) {
        mndis = inf;
        for(int i=0;i<n;i++) {
            if(dis[i]<mndis && !vis[i]) {
                mndis = dis[i];
                next = i;
            }
        }
        vis[next] = 1;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                if(mndis+cost[next][i]<dis[i]) {
                    dis[i] = mndis+cost[next][i];
                    pred[i] = next;
                }
            }
        }
        c++;
    }
    for(int i=0;i<n;i++) {
        if(i != st) printf("\n dis from source to %d = %d", i, dis[i]);
    }
}

int main() {
    int a[m][m];
    int n,u;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    }
    scanf("%d",&u);
    dijkstra(a, n, u);
}
