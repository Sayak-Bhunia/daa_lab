#include <stdio.h>
#define inf 9999 //INFINITY
#define mx 10

void Dijkstra(int Graph[mx][mx], int n, int start) {
  int cost[mx][mx], dis[mx], pred[mx];
  int visited[mx], c, mndis, next, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = inf;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    dis[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  dis[start] = 0;
  visited[start] = 1;
  c = 1;

  while (c < n - 1) {
    mndis = inf;

    for (i = 0; i < n; i++)
      if (dis[i] < mndis && !visited[i]) {
        mndis = dis[i];
        next = i;
      }

    visited[next] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mndis + cost[next][i] < dis[i]) {
          dis[i] = mndis + cost[next][i];
          pred[i] = next;
        }
    c++;
  }

  // Printing the dis
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\ndis from source to %d: %d", i, dis[i]);
    }
}

int main() {
  int Graph[mx][mx], i, j, n, u;
  
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter the adjacency matrix for the graph:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &Graph[i][j]);
    }
  }

  printf("Enter the starting node: ");
  scanf("%d", &u);

  Dijkstra(Graph, n, u);

  return 0;
}
