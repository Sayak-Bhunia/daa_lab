#include <stdio.h>
#include <stdlib.h>

struct item {
    int val;
    int wt;
};

int helper(const void *a, const void *b) {
    double r1 = (double)((struct item *)a)->val/(double)((struct item *)a)->wt;
    double r2 = (double)((struct item *)b)->val/(double)((struct item *)b)->wt;
    if(r1 > r2) return -1;
    else if(r1 < r2) return 1; 
    else return 0;
}

double fractionalKnapsack(int w, struct item a[], int n) {
    qsort(a, n, sizeof(a[0]), helper); 
    int curr = 0;
    double final = 0.0;
    for(int i=0;i<n;i++) {
        if(curr + a[i].wt <= w) {
            curr += a[i].wt;
            final += a[i].val;
        } 
        else {
            int rem = w - curr;
            final += ((double)a[i].val/(double)a[i].wt)*(double)rem;
            break;
        }
    }
    return final;
}

int main() {
    int n = 3, w = 50;
    struct item a[] = {{100, 20}, {60, 10}, {120, 30}};
    double res = fractionalKnapsack(w, a, n);
    printf("The maximum value is %.2lf\n", res);
}
