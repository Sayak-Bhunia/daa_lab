// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(int *a, int *b) {
    int z = *a;
    *a = *b;
    *b = z;
}

int partition(int a[], int l, int h) {
    int i = l-1;
    for(int j=l;j<h;j++) {
        if(a[j]<=a[h]) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[h]);
    return i+1;
}

void quickSort(int a[], int l, int h) {
    if(l<h) {
        int p = partition(a, l, h);
        quickSort(a, l, p-1);
        quickSort(a, p+1, h);
    }
}

int main() {
    int n;
    printf("enter the size of array = ");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements = ");
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("original array = ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    quickSort(a, 0, n-1);
    printf("sorted array = ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
} 
