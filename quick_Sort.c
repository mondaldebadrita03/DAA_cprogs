#include <stdio.h>
int partition(int arr[],int lb,int ub){
    int pivot=arr[lb];
    int st,end=lb;
    for(st=lb+1;st<=ub;st++){
        if(arr[st]<pivot){
            end++;
            int temp=arr[st];
            arr[st]=arr[end];
            arr[end]=temp;
        }
    }
    int temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;
    return end;
}
void quick_Sort(int arr[],int lb,int ub){
   if(ub>lb){
       int loc=partition(arr,lb,ub);
       quick_Sort(arr,lb,loc-1);
       quick_Sort(arr,loc+1,ub);
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
    quick_Sort(arr,0,n-1);
    printf("\nThe array after sorting: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
