#include <stdio.h>
struct Item{
	int profit;
	int weight;
};
void SortProfitperWeight(struct Item arr[],int N ){
    int i, j, key_profit, key_weight;
    double key;
    for (i = 1; i < N; i++) 
    {
        key = (arr[i].profit / arr[i].weight);
        key_profit = arr[i].profit;
        key_weight = arr[i].weight;
        j = i - 1;
        while (j >= 0 && (arr[j].profit / arr[j].weight) < key) 
        {
            arr[j + 1].profit = arr[j].profit;
            arr[j + 1].weight = arr[j].weight;
            j = j - 1;
        }
        arr[j + 1].profit = key_profit;
        arr[j + 1].weight = key_weight;
    }  
}
double fractionalKnapsack(int W, struct Item arr[], int N)
{
	SortProfitperWeight(arr,N);
	double finalvalue = 0.0;
	for (int i = 0; i < N; i++) {
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].profit;
		}
		else {
			finalvalue
				+= arr[i].profit
				* ((double)W / (double)arr[i].weight);
			break;
		}
	}
	return finalvalue;
}
int main()
{
	int W = 4;// WEIGHT OF MY SACK
	struct Item arr[] = { { 100, 2 }, { 10, 2} ,{ 120, 3 } };
	int N = sizeof(arr) / sizeof(arr[0]);
    printf("%f",fractionalKnapsack(W,arr,N)); 
	return 0;
}
