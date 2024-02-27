#include<stdio.h>

void swap(int *a, int *b) {
    int z = *a;
    *a = *b;
    *b = z;
}

int partition(int a[], int l, int h) {
    int pivot = a[h];
    int i = l-1;
    for(int j=l;j<h;j++) {
        if(a[j]<=pivot) {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[h]);
    return (i+1);
}

void quickSort(int a[], int l, int h) {
    if(l<h) {
        int p = partition(a, l, h);
        quickSort(a, l, p-1);
        quickSort(a, p+1, h);
    }
}

int main()
{
    int a[8];
    printf("enter elements: ");
    for(int i=0;i<8;i++) {
        scanf("%d",&a[i]);
    }
    quickSort(a, 0, 7);
    printf("\nSorted Array:\n");
    for(int i=0;i<8;i++) {
        printf("%d ",a[i]);
    }
}

// 7 19 32 16 5 13 67 90
