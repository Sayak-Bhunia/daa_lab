#include<stdio.h>
#define n 4
#define inf 999

void printMatrix(int a[][n]) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(a[i][j] == inf) printf("0");
            else printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int a[][n]) {
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(a[i][k] + a[k][j]<a[i][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    printMatrix(a);
}

int main()
{
    int a[n][n] = {{0, 3, inf, 5},
                   {2, 0, inf, 4},
                   {inf, 1, 0, inf},
                   {inf, inf, 2, 0}};
    floydWarshall(a);
}
