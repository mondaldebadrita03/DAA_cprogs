#include <stdio.h>
int binary_Search(int arr[],int n,int x){
    int a1=0,a2=n-1;
    while(a2>a1){
        int mid=a1+(a2-a1)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]>x){
            a2=mid-1;
        }
        else{
            a1=mid+1;
        }
    }
    return -1;
}
int main(void){
    int arr[10],n,i,x,y;
    printf("Enter the number of elements in an array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The elements of the array: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter an element to search: ");
    scanf("%d",&x);
    y=binary_Search(arr,n,x);
    if(y==-1)
        printf("Element %d not found",x);
    else
        printf("Element %d has been found in the position %d",x,y+1);
    return 0;
}
