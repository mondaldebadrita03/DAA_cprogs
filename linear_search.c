#include <stdio.h>
int main(void)
{
    int n,arr[100],i,x,pos=0,flag=0;
    printf("Enter the number of elements in an array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Elements of the array:");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter an element to search: ");
    scanf("%d",&x);
    for(i=0;i<n;i++){
        ++pos;
        if(arr[i]==x){
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("Element %d has been found in the position %d",x,pos);
    else
        printf("Element %d was not found",x);
    return 0;
}
