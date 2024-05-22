#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Job {
	int id; 
	int deadline; 
	int profit; 
} Job;
int max_deadline;
void SortProfitWise(Job arr[],int  N){ 
    int i, j, key_profit, key_weight,key_id,key_deadline;
    max_deadline = arr[0].deadline;
    double key;
    for (i = 1; i < N; i++) 
    {
        key_profit = arr[i].profit;
        key_id = arr[i].id;
        key_deadline = arr[i].deadline;
        if(max_deadline < (arr[i].deadline ))
            max_deadline = arr[i].deadline;
        j = i - 1;
        while (j >= 0 && (arr[j].profit) < key_profit) 
        {
            arr[j + 1].profit = arr[j].profit;
            arr[j + 1].id = arr[j].id;
            arr[j + 1].deadline = arr[j].deadline;
            j = j - 1;      
        }
        arr[j + 1].profit = key_profit;
        arr[j + 1].id = key_id;
        arr[j + 1].deadline = key_deadline;
    }
}
void printJobScheduling(Job arr[], int n)
{
    SortProfitWise(arr, n);
    int j,profit = 0;
    int *deadline;
    deadline = (int *) calloc((max_deadline+1),sizeof(int));
    int list_selected_items[n],k= 0;
    for(int i=0; i< n ; i++){
        if(deadline[arr[i].deadline] == 0){
            deadline[arr[i].deadline] = 1;
            printf("Selected Item number %d and corresponding profit %d\n",arr[i].id,arr[i].profit);
            profit+=arr[i].profit;
            list_selected_items[k++] =  arr[i].id;
        }
        else{
            j=arr[i].deadline;
            while(j>=1){
                if(deadline[j] == 0)
                {
                   deadline[j] = 1;
                   printf("Selected Item number %d and corresponding profit %d\n",arr[i].id,arr[i].profit);
                   profit+=arr[i].profit;
                   list_selected_items[k++] =  arr[i].id;    
                   break;
                }
                j--;
            }
        }
    }
    printf("\nTotal profit is = %d", profit);
}
int main()
{
	Job arr[] = { { 1, 2, 100 },
				{ 2, 1, 19 },
				{ 3, 2, 27 },
				{ 4, 1, 25 },
				{ 5, 3, 15 } };
	int n = sizeof(arr) / sizeof(arr[0]);
    printJobScheduling(arr, n);
	return 0;
}
