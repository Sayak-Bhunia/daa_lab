// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct item {
    int val;
    int wt;
};

int helper(const void *a, const void *b) {
    double r1 = ((struct item *)a)->val/(double)((struct item *)a)->wt;
    double r2 = ((struct item *)b)->val/(double)((struct item *)b)->wt;
    if(r1>r2) return -1;
    else if(r1<r2) return 1;
    else return 0;
}

double fractionalKnapsack(struct item a[], int n, int w) {
    qsort(a, n, sizeof(a[0]), helper);
    int c = 0;
    double f = 0.0;
    for(int i=0;i<n;i++) {
        if(c + a[i].wt <= w) {
            c += a[i].wt;
            f += a[i].val;
        }
        else {
            int r = w - c;
            f += (a[i].val/(double)a[i].wt)*r;
            break;
        }
    }
    return f;
}

int main() {
    int n = 3, w = 50;
    struct item a[] = {{100, 20}, {60, 10}, {120, 30}};
    double res = fractionalKnapsack(a, n, w);
    printf("max val = %.2lf\n",res);
}
