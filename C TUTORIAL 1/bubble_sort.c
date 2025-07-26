#include<stdio.h>
#include<stdlib.h>
void bubble_sort(int arr[], int n) {
    int i, j;
    int swapped;
    for (i = 0; i < n; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
     if (!swapped) {
            break;
        }
    }
}
int main(){
    int b,i,n;
    int a[50];
    printf("enter n :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubble_sort(a,n);
    for(i=0;i<n;i++){
        printf("%d   ",a[i]);
    }
    return 0;
}
