// Online C compiler to run C program online
#include <stdio.h>

void swap(int *a, int *b) {
    int z = *a;
    *a = *b;
    *b = z;
}

void heapify(int a[], int n, int i) {
    int mx = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && a[l]>a[mx]) mx = l;
    if(r<n && a[r]>a[mx]) mx = r;
    if(mx != i) {
        swap(&a[i], &a[mx]);
        heapify(a, n, mx);
    }
}

void heapSort(int a[], int n) {
    for(int i=n/2-1;i>=0;i--) heapify(a, n, i);
    for(int i=n-1;i>=0;i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    heapSort(a, n);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}
