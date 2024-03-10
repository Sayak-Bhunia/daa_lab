#include<stdio.h>

int max(int a, int b) {
    return (a>b)?a:b;
}

int min(int a, int b) {
    return (a<b)?a:b;
}

int findMax(int a[], int n) {
    if(n == 1) return a[0];
    else return max(a[n-1], findMax(a, n-1));
}

int findMin(int a[], int n) {
    if(n == 1) return a[0];
    else return min(a[n-1], findMin(a, n-1));
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
    printf("Maximum element = %d\n",findMax(a, n));
    printf("Minimum element = %d",findMin(a, n));
}
