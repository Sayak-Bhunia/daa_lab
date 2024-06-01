// Online C compiler to run C program online
#include<stdio.h>
#include<stdbool.h>

bool isCompatible(int n, int m, int p, int q) {
    return m == p;
}

void mul(int n, int m, int p, int q, int a[n][m], int b[p][q], int res[n][q]) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<q;j++) {
            res[i][j] = 0;
            for(int k=0;k<m;k++) res[i][j] += a[i][k]*b[k][j];
        }
    }
}

void printMatrix(int n, int q, int res[n][q]) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<q;j++) printf("%d ",res[i][j]);
        printf("\n");
    }
}

int main() {
    int n,m,p,q;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&p,&q);
    int a[n][m];
    int b[p][q];
    if(!isCompatible(n, m, p, q)) {
        printf("matrices are not compatible for multiplication!\n");
        return 1;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    }
    for(int i=0;i<p;i++) {
        for(int j=0;j<q;j++) scanf("%d",&b[i][j]);
    }
    int res[n][q];
    mul(n, m, p, q, a, b, res);
    printMatrix(n, q, res);
}
