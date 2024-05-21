#include <stdio.h>
void insertion_Sort(int arr[],int n){
    for(int i=1; i<n; i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int main(void) {
    int n,i;
    printf("Enter the number of elements in an array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nThe array before sorting: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    insertion_Sort(arr,n);
    printf("\nThe array after sorting: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
