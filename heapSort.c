#include<stdio.h>

void swap(int *a, int *b) {
    int z = *a;
    *a = *b;
    *b = z;
}

int heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && a[l]>a[largest]) largest = l;
    if(r<n && a[r]>a[largest]) largest = r;
    if(largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for(int i=n/2-1;i>=0;i--) {
        heapify(a, n, i);
    }
    for(int i=n-1;i>=0;i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    int a[8];
    printf("enter elements: ");
    for(int i=0;i<8;i++) {
        scanf("%d",&a[i]);
    }
    heapSort(a,8);
    printf("\nSorted Array:\n");
    for(int i=0;i<8;i++) {
        printf("%d ",a[i]);
    }
}

// 7 19 32 16 5 13 67 90
