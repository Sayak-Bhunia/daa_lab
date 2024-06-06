#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define inf 999
#define m 4

int matrixChainOrder(int a[], int n) {
    int dp[n][n];
    for(int i=1;i<n;i++) dp[i][i] = 0;
    for(int l=2;l<n;l++) {
        for(int i=1;i<n-l+1;i++) {
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            for(int k=i;k<=j-1;k++) {
                int q = dp[i][k] + dp[k+1][j] + a[i-1]*a[k]*a[j];
                if(q<dp[i][j]) dp[i][j] = q;
            }
        }
    }
    return dp[1][n-1];
}

int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("min no. of multiplications needed = %d",matrixChainOrder(a, n));
}
