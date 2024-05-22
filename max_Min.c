#include<stdio.h>
void max_Min(int arr[],int s,int e,int *max,int *min){
    if(s==e){
        *max=arr[s];
        *min=arr[s];
    }else if(s==e-1){
        if(arr[s]>arr[e]){
            *max=arr[s];
            *min=arr[e];
        }else{
            *max=arr[e];
            *min=arr[s];
        }
    }else{
        int mid=(s+e)/2;
        max_Min(arr,s,mid,max,min);
        int max1,min1;
        max_Min(arr,mid+1,e,&max1,&min1);
        if(*max<max1){
            *max=max1;
        }if(*min>min1){
            *min=min1;
        }
    }
}
int main(void) {
    int n,i,max,min;
    printf("Enter the number of elements in an array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nThe array: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    max_Min(arr,0,n-1,&max,&min);
    printf("\nMax:%d ,Min:%d",max,min);
    return 0;
}
