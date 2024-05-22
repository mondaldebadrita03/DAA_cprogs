#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct {
    int u, v;
    int cost;
} Edge;
void heapify(Edge *ptr, int i, int n){
	int lchildIndex=2*i; 
	int rchildIndex=2*i+1;
	Edge temp;
	int smallestIndex=i; 
	if(lchildIndex<n && ptr[lchildIndex].cost  <    ptr[i].cost)
		smallestIndex=lchildIndex;
	if(rchildIndex<n && ptr[rchildIndex].cost<ptr[smallestIndex].cost) 
		smallestIndex=rchildIndex;
	if(smallestIndex!=i){
		temp=*(ptr+smallestIndex);
		*(ptr+smallestIndex)=*(ptr+i);
		*(ptr+i)=temp;
		heapify(ptr,smallestIndex,n); 	
	}
}
void buildMinHeap(Edge *ptr, int n){
	int i;
	for(i=n/2-1;i>=0;i--){
		heapify(ptr,i,n); 		
	}
}
Edge extractMin(Edge *ptr,int n){
	Edge x;
	int i;
	if(n==0){
		printf("Empty heap!!!");
		return ;
	}
	x=ptr[0];
	ptr[0]=ptr[n-1];   
	heapify(ptr,0,n-1);	
	return x;
}
int find(int i,int *parent) {
    while(*(parent+i)>=0)
       i=*(parent+i);
    return i;
}
void unionSets(int i,int j,int *parent){
	parent[i]=j;
}
int kruskal(int edgeCount,int n,int cost[][n],int t[][2]) {   /* Construct a heap out of edge cost using heapify*/
   	int *parent,i,j,k=0,uset,vset;
	Edge *graph,temp;
	int  minCost;
    graph=(Edge *)malloc(edgeCount*sizeof(Edge));
    parent=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			if(cost[i][j]!=INT_MAX){
				graph[k].u=i;
				graph[k].v=j;
				graph[k].cost=cost[i][j];
				k++;
			}
		}
	}
	buildMinHeap(graph,edgeCount);
	for(i=0;i<n;i++)
		parent[i]=-1;
	  i = 0;minCost=0;
    while (i < n - 1 && edgeCount> 0) {
 		temp=extractMin(graph,edgeCount);
 		uset=find(temp.u,parent);vset=find(temp.v,parent);
 		if (uset != vset) {
 			t[i][0]=temp.u;
			t[i][1]=temp.v;
            minCost += temp.cost;
            unionSets(uset,vset,parent);
            i=i+1;
        }
        edgeCount--;
    }
    if(i!=n-1){
    	printf("No Spanning Tree !!1");
    	return;
	}
    return minCost;
}	
int main(void){
   	FILE *file=fopen("adjacency.txt","r");  
	char ch;
	int rows=0,cols=0,i,j,k=0;
	int edgeCount=0;
	Edge *graph;
	if(file==NULL){
		printf("Error in opening file !!!");
		exit(0);
	}
	fscanf(file, "%d %d", &rows, &cols);
	int cost[rows][cols];
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(fscanf(file,"%d",&cost[i][j])!=1){
				return 1;
			}
		}
	}
	printf("\nMatrix read from file :\n");
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			 printf("%d ",cost[i][j]);
		}
		printf("\n");
	}
	int t[rows-1][2];
	for(i=0;i<rows;i++){
		for(j=0;j<=i;j++){
			if(cost[i][j]!=INT_MAX){
				edgeCount++;
			}
		}
	}
	int minCost = kruskal(edgeCount,rows,cost,t);
    printf("Minimum cost of spanning tree: %d\n", minCost);
    printf("Edges in the minimum-cost spanning tree:\n");
    for(i=0;i<rows-1;i++){
		printf("%d,%d\n",t[i][0],t[i][1]);
	}
	fclose(file);
	return 0;
}
