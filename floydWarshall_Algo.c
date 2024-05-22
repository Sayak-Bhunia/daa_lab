#include<stdio.h>
#define n 4
#define inf 999

void printMatrix(int m[][n]) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(m[i][j] == inf) printf("%4s",inf);
            else printf("%4d",m[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int a[][n]) {
    int m[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) m[i][j] = a[i][j];
    }
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(m[i][k]+m[k][j]<m[i][j]) {
                    m[i][j] = m[i][k] + m[k][j];
                }
            }
        }
    }
    printMatrix(m);
}

int main()
{
    int g[n][n] = {{0, 3, inf, 5},
                   {2, 0, inf, 4},
                   {inf, 1, 0, inf},
                   {inf, inf, 2, 0}};
    floydWarshall(g);
}
