#include <stdio.h>
void selection_Sort(int arr[],int n){
    for(int i=0; i<n-1; i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
                min=j;
        }
        if(min!=i){
            arr[i]=arr[i]^arr[min];
            arr[min]=arr[i]^arr[min];
            arr[i]=arr[i]^arr[min];
        }
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
    selection_Sort(arr,n);
    printf("\nThe array after sorting: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
