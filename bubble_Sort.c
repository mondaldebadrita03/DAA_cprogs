#include<stdio.h>
void bubble_Sort(int arr[],int n){
    for(int i=0;i<=n-1;i++) {
        int count=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                arr[j]=arr[j]^arr[j+1];
                arr[j+1]=arr[j]^arr[j+1];
                arr[j]=arr[j]^arr[j+1];
                count++;
            }
        }
        if(count==0)
            break;
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
    bubble_Sort(arr,n);
    printf("\nThe array after sorting: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
