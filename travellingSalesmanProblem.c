#include <stdio.h>
int tsp_g[10][10] = {
   {12, 30, 33, 10, 45},
   {56, 22, 9, 15, 18},
   {29, 13, 8, 5, 12},
   {33, 28, 16, 10, 3},
   {1, 4, 30, 24, 20}
};
int vis[10], n, cost = 0;

/* creating a function to generate the shortest path */
void travellingsalesman(int c){
   int k, adjv = 999;
   int mn = 999;
   
   /* marking the vertices vis in an assigned array */
   vis[c] = 1;
   
   /* displaying the shortest path */
   printf("%d ", c + 1);
   
   /* checking the minimum cost edge in the graph */
   for(k = 0; k < n; k++) {
      if((tsp_g[c][k] != 0) && (vis[k] == 0)) {
         if(tsp_g[c][k]<mn) mn = tsp_g[c][k];
         adjv = k;
      }
   }
   if(mn != 999) cost += mn;
   if(adjv == 999) {
      adjv = 0;
      printf("%d", adjv + 1);
      cost += tsp_g[c][adjv];
      return;
   }
   travellingsalesman(adjv);
}

/* main function */
int main(){
   int i, j;
   n = 5;
   for(i = 0; i < n; i++) vis[i] = 0;
   printf("Shortest Path: ");
   travellingsalesman(0);
   printf("\nMinimum Cost: ");
   printf("%d\n", cost);
   return 0;
}


