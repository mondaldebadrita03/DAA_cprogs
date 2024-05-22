#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
int V;
int *d;
void printSolution(int d[]){
	int i;
	printf("\n Vertex             Distance from Source\n");
	for(i=0;i<V;i++){
		printf("%d\t\t  %d\n",i,d[i]);
	}
}
void relax(int u,int v,int w){
	if(w!=0 && d[v]>d[u]+w){
		d[v]=d[u]+w;
	}
}
void initializeSingleSource(int G[][V],int s){
	int i;
	d=(int *)malloc(V*sizeof(int));	
	for(i=0;i<V;i++){
		d[i]=INT_MAX;
	}
	d[s]=0;
}
bool bellmanFord(int G[][V],int s){
	int i,u,v;
	initializeSingleSource(G,s);
	for(i=1;i<=V-1;i++){
		for(u=0;u<V;u++){
			for(v=0;v<V;v++){
				relax(u,v,G[u][v]);
			}
		}
	}
	for(u=0;u<V;u++){
			for(v=0;v<V;v++){
				if(G[u][v]!=0 && d[v]>d[u]+G[u][v]){
					return false;
				}
		}
	}
	printSolution(d);
	return true;
}
int main(void){
	FILE *file=fopen("matrix.txt","r");  
	int i,j,s;
	if(file==NULL){
		printf("Error in opening file !!!");
		exit(0);
	}
    fscanf(file, "%d", &V);
	int G[V][V];
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			if(fscanf(file,"%d",&G[i][j])!=1){
				return 1;
			}
		}
	}
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			printf("%d\t",G[i][j]);
		}
	printf("\n");
	}
	printf("Enter the source vertex:");
	scanf("%d",&s);
	bellmanFord(G,s);		
	return 0;
}
