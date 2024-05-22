#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
int V;
void printSolution(int d[]){
	int i=0;
	printf("\nVertex Distance from Source\n");
	for(i=0;i<V;i++){
		printf("%d\t\t %d\n",i,d[i]);
	}	
}
int extractMin(int dist[],bool spt[]){
	int min=INT_MAX,minIndex;
	int v;
	for(v=0;v<V;v++){
		if(spt[v]==false && dist[v]<=min){
			min=dist[v];
			minIndex=v;
		}
	}
	return minIndex;
}
void dijkastra(int g[][V]){	
	int d[V],i,s,count,u,v;
	bool spt[V];
	for(i=0;i<V;i++){
		d[i]=INT_MAX;			
		spt[i]=false;	
	}
	printf("Enter the source Vertex:");
	scanf("%d",&s);
	d[s]=0;
	count=0;
	while(count<V-1){
		u=extractMin(d,spt);	
		spt[u]=true;
		for(v=0;v<V;v++){
			if(!spt[v] && g[u][v] && d[v]>d[u]+g[u][v]){	
				d[v]=d[u]+g[u][v];
			}	
		}
		count++;	
	}
	printSolution(d);
}
int main(void){
	FILE *file=fopen("matrix.txt","r");  
	int i,j;
	if(file==NULL){
		printf("Error in opening file !!!");
		exit(0);
	}
    fscanf(file, "%d", &V);  
	int cost[V][V];
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			if(fscanf(file,"%d",&cost[i][j])!=1){
				return 1;
			}
		}
	}
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			printf("%d\t",cost[i][j]);
		}
	printf("\n");
	}		
	dijkastra(cost);
}
