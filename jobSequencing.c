#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct job {
    char id;
    int profit;
    int deadline;
} job;

int cmp(const void *a, const void *b) {
    return ((job *)b)->profit - ((job *)a)->profit;
}

int min(int a, int b) {
    return a<b?a:b;
}

void jobSequencing(job a[], int n) {
    qsort(a, n, sizeof(job), cmp);
    int res[n];
    bool slot[n];
    for (int i=0;i<n;i++) slot[i] = false;
    for(int i=0;i<n;i++) {
        for(int j=min(n, a[i].deadline)-1;j>=0;j--) {
            if (slot[j] == false) {
                res[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(slot[i]) printf("%c ", a[res[i]].id);
    }
}

int main() {
    int n = 5;
    job a[] = {{'a', 100, 2},
               {'b', 19, 1},
               {'c', 27, 2},
               {'d', 25, 1},
               {'e', 15, 3}};
    printf("max profit sequence ->\n");
    jobSequencing(a, n);
}
