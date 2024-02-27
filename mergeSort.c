#include<stdio.h>

void merge(int a[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int l[n1], m[n2];
    for(int i=0;i<n1;i++) l[i] = a[p+i];
    for(int i=0;i<n2;i++) m[i] = a[q+1+i];
    int i = 0, j = 0, k = p;
    while(i<n1 && j<n2) {
        if(l[i] <= m[j]) {
            a[k] = l[i];
            i++;
        }
        else {
            a[k] = m[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        a[k] = l[i];
        i++;
        k++;
    }
    while(j<n2) {
        a[k] = m[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r) {
    if(l<r) {
        int mid = (l+r)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}

int main()
{
    int a[8];
    printf("enter elements: ");
    for(int i=0;i<8;i++) {
        scanf("%d",&a[i]);
    }
    mergeSort(a, 0, 7);
    printf("\nSorted Array:\n");
    for(int i=0;i<8;i++) {
        printf("%d ",a[i]);
    }
}

// 7 19 32 16 5 13 67 90
