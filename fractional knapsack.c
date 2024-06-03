#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

typedef struct item {
    int val;
    int wt;
}item;

int helper(const void *a, const void *b) {
    int r1 = ((item *)a)->val/(double)((item *)a)->wt;
    int r2 = ((item *)b)->val/(double)((item *)b)->wt;
    if(r1>r2) return -1;
    else if(r1<r2) return 1;
    else return 0;
}

double fractionalKnapsack(item a[], int n, int w) {
    qsort(a, n, sizeof(a[0]), helper);
    int c = 0;
    double f = 0.0;
    for(int i=0;i<n;i++) {
        if(c+a[i].wt<=w) {
            c += a[i].wt;
            f += a[i].val;
        }
        else {
            int r = w - c;
            f += ((a[i].val)/(double)(a[i].wt))*r;
            break;
        }
    }
    return f;
}

int main() {
    int n = 3, w = 50;
    item a[] = {{100, 20}, {60, 10}, {120, 30}};
    printf("%.2lf",fractionalKnapsack(a, n, w));
}
