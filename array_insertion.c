#include<stdio.h>
int main(void) {
    int n,arr[10],i,j,pos;
    printf("Enter the number of elements in an array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter an element to insert: ");
    scanf("%d",&j);
    printf("Enter the position to insert the element %d: ",j);
    scanf("%d",&pos);
    printf("The array before insertion: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("The array after insertion: ");
    for(i=n;i>=pos-1;i--){
        arr[i+1]=arr[i];
        arr[pos-1]=j;
    }
    ++n;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
