#include<stdio.h>
void merge(int arr[],int lb,int mid, int ub){
    int mer[ub-lb+1];
    int i=lb,j=mid+1,k=0;
    while(i<=mid && j<=ub){
        if(arr[i]>arr[j]){
            mer[k]=arr[j];
            k++;
            j++;
        }else{
            mer[k]=arr[i];
            k++;
            i++;
        }
    }
    while(i<=mid){
        mer[k++]=arr[i++];
    }
    while(j<=ub){
        mer[k++]=arr[j++];
    }
    for(int x=0; x<ub-lb+1; x++){
        arr[lb+x]=mer[x];
    }
}
void merge_Sort(int arr[],int lb,int ub){
    if(ub>lb){
        int mid=lb+(ub-lb)/2;
        merge_Sort(arr,lb,mid);
        merge_Sort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
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
    merge_Sort(arr,0,n-1);
    printf("\nThe array after sorting: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
