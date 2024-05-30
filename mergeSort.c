// Online C compiler to run C program online
#include <stdio.h>

void merge(int a[], int p, int q, int r) {
    int n1 = q-p+1;
    int n2 = r-q;
    int l[n1], m[n2];
    for(int i=0;i<n1;i++) l[i] = a[p+i];
    for(int i=0;i<n2;i++) m[i] = a[q+i+1];
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

void mergeSort(int a[], int l, int h) {
    if(l<h) {
        int p = (l+h)/2;
        mergeSort(a, l, p);
        mergeSort(a, p+1, h);
        merge(a, l, p, h);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    mergeSort(a, 0, n-1);
    for(int i=0;i<n;i++) printf("%d",a[i]);
}
