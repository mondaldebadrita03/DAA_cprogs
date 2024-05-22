#include<stdio.h>
#include<stdlib.h>
int V;
void printSolution(int D[][V],int P[][V]){
	int i,j;
	printf("Shortest distance between all pair of nodes :\n");
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			printf("%d\t",D[i][j]);
		}
		printf("\n");
	}
	printf("Predecessor Matrix for shortest path:\n");
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			printf("%d\t",P[i][j]);
		}
		printf("\n");
	}
}
void floyedWarshall(int W[][V]){
	int i,j,k;
	int D[V][V],P[V][V];
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			D[i][j]=W[i][j];
			P[i][j]=0;
		}
	}
	
	for(k=0;k<V;k++){           // k=1
		for(i=0;i<V;i++){       // i=2
			for(j=0;j<V;j++){   // j=1 
				
				if(D[i][k]!=INT_MAX  && D[k][j] !=INT_MAX && D[i][j]>D[i][k]+D[k][j]){
					D[i][j]=D[i][k]+D[k][j];
					P[i][j]=k+1;
				}			
			}
		}
	}
	printSolution(D,P);
}		
int main(void){
	FILE *file=fopen("adjacency1.txt","r");  
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
	floyedWarshall(G);		
	return 0;
}
