#include "stdio.h"    
#include "stdlib.h"   
#include"include/graph.h"

void InitMGraph(MGraph **graph,int numVertexes,int numEdges){
	(*graph)=(MGraph*)malloc(sizeof(MGraph));
	(*graph)->arc=(int**)malloc(sizeof(int*)*numVertexes);
	for(int i = 0; i < numVertexes; i++)
		(*graph)->arc[i] = (int * )malloc(numVertexes*sizeof(int));
	(*graph)->vexs=(int*)malloc(sizeof(int)*numVertexes);
	(*graph)->numEdges=numEdges;
	(*graph)->numVertexes=numVertexes;

	for (int i = 0; i < (*graph)->numVertexes; i++){
		(*graph)->vexs[i]=i;
	}

	for (int i = 0; i < (*graph)->numVertexes; i++){
		for (int j = 0; j < (*graph)->numVertexes; j++){
			if (i==j)
				(*graph)->arc[i][j]=0;
			else
				(*graph)->arc[i][j] = (*graph)->arc[j][i] = INFINITY;
		}
	}
}

void Floyd(MGraph* graph){    
	int** D=(int**)malloc(sizeof(int*)*graph->numVertexes);
	int** P=(int**)malloc(sizeof(int*)*graph->numVertexes);
	for(int i = 0; i < graph->numVertexes; i++){
		D[i] = (int * )malloc(graph->numVertexes*sizeof(int));
		P[i] = (int * )malloc(graph->numVertexes*sizeof(int));
	}

	for(int i=0;i<graph->numVertexes;i++){
		for(int j=0;j<graph->numVertexes;j++){
			D[i][j]=graph->arc[i][j];
			P[i][j]=j;
		}
	}

	for(int v=0; v<graph->numVertexes; v++){
		for(int i=0; i<graph->numVertexes; i++){        
			for(int j=0; j<graph->numVertexes; j++){
				if (D[i][j]>D[i][v]+D[v][j]){
					D[i][j]=D[i][v]+D[v][j];
					P[i][j]=P[i][v];
				}
			}
		}
	}

	for(int i=0;i<graph->numVertexes;i++){
		for(int j=0;j<graph->numVertexes;j++){
			printf("%d\t",D[i][j]);
		}
		printf("\n");
	}
		printf("\n");

	for(int i=0;i<graph->numVertexes;i++){
		for(int j=0;j<graph->numVertexes;j++){
			printf("%d\t",P[i][j]);
		}
		printf("\n");
	}
}
