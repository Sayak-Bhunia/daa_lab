#include <stdio.h>
#define nV 4
#define inf 999

void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == inf)
        printf("%4s", "inf");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

void floydWarshall(int g[][nV]) {
  int matrix[nV][nV], i, j, k;

  // Initialize the matrix with the graph
  for (i = 0; i < nV; i++) {
    for (j = 0; j < nV; j++) {
      matrix[i][j] = g[i][j];
    }
  }

  // Floyd-Warshall algorithm
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

int main() {
  int g[nV][nV] = {{0, 3, inf, 5},
                   {2, 0, inf, 4},
                   {inf, 1, 0, inf},
                   {inf, inf, 2, 0}};
  floydWarshall(g);
  return 0;
}
