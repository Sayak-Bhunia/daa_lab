// Online C compiler to run C program online
#include <stdio.h>
#define inf 9999
#define m 10
int a[m][m] = {
   {12, 30, 33, 10, 45},
   {56, 22, 9, 15, 18},
   {29, 13, 8, 5, 12},
   {33, 28, 16, 10, 3},
   {1, 4, 30, 24, 20}
};
int vis[m], n, cost = 0;

void tsp(int c) {
   int adjv = 999;
   int mn = 999;
   vis[c] = 1;
   printf("%d ", c+1);
   for(int i=0;i<n;i++) {
      if(a[c][i] != 0 && vis[i] == 0) {
         if(a[c][i]<mn) mn = a[c][i];
         adjv = i;
      }
   }
   if(mn != 999) cost += mn;
   if(adjv == 999) {
      adjv = 0;
      printf("%d", adjv+1);
      cost += a[c][adjv];
      return;
   }
   tsp(adjv);
}

int main() {
    int i,j;
    n = 5;
    for(i=0;i<n;i++) vis[i] = 0;
    printf("shortest path = ");
    tsp(0);
    printf("\nmin cost = ");
    printf("%d\n",cost);
    
    
}
