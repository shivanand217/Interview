#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high){
    /** taking the last element as pivot **/
    /** target :- we have to set all the elements which are smaller than pivot to its left and greater to right **/
    int pivot = arr[high];
    int i=low-1;
    int j=low;
    while(j < high){
        if(arr[j] < pivot) {
            i=i+1;
            swap(&arr[i],&arr[j]);
        }
        j=j+1;
    }
    swap(&arr[i+1],&arr[j]);
    return (i+1);
}
void quickSort(int arr[],int low,int high) {
    if(low < high) {
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}
int main() {
    int n,i;
    scanf("%d",&n);
    int *arr = (int *)malloc(sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);
    printf("Sorted elements: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    } putchar('\n');
    return 0;
}
