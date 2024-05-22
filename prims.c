#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int prim(int n,int cost[][n],int t[][2]){
	int mincost=INT_MAX;;
	int near[n],i,j,k,l,k1;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(cost[i][j]<mincost){
				k=i;
				l=j;
				mincost=cost[i][j];
			}
		}
	}
	mincost=cost[k][l];
	t[0][0]=k;
	t[0][1]=l;
	for(i=0;i<n;i++){
		if(cost[i][l]<cost[i][k]){
			near[i]=l;	
		}else{
			near[i]=k;
		}
	}
	near[k]=near[l]=-1;
	for(i=1;i<n-1;i++){
		int min=INT_MAX;
		int idx,j=0;
		for(idx=0;idx<n;idx++){
		
			if(near[idx]!=-1 && cost[idx][near[idx]]<min) {	
				min=cost[idx][near[idx]];
				j=idx;
			}
		}
		t[i][0]=j;
		t[i][1]=near[j];	
		mincost+=cost[j][near[j]];
		near[j]=-1;
		for(k1=0;k1<n;k1++){
			if(near[k1]!=-1 && cost[k1][near[k1]]>cost[k1][j]){
				near[k1]=j;
			}
		}
	}	
	return mincost;
}
int main(void){
   	FILE *file=fopen("adjacency.txt","r");  
	char ch;
	int rows=0,cols=0,i,j;
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
	int t[rows-1][2];
	int mincost=prim(rows,cost,t);
	printf("\n\nMinimum Cost of Spanning tree is :%d",mincost);
	printf("\nEdges of the Minimum Spanning Tree:\n");
	for(i=0;i<rows-1;i++){
		printf("%d,%d\n",t[i][0],t[i][1]);
	}
	fclose(file);
	return 0;
}
