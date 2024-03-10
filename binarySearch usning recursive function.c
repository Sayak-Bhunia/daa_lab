#include<stdio.h>

int binarySearch(int a[], int l, int h, int t) {
    if(l<=h) {
        int mid = (l+h)/2;
        if(a[mid] == t) return mid;
        else if(a[mid]<t) return binarySearch(a, mid+1, h, t);
        else return binarySearch(a, l, mid, t);
    }
    return -1;
}

int main()
{
    int n;
    printf("enter size = ");
    scanf("%d",&n);;
    int a[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int target;
    printf("enter element to find = ");
    scanf("%d",&target);
    int idx = binarySearch(a, 0, n-1, target);
    if(idx != -1) printf("%d found at index %d",target,idx);
    else printf("%d not found in the array",target);
}
