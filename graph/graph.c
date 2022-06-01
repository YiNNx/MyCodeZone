#include"stdio.h"
#include"stdlib.h"
#include"include/graph.h"
#include"../queue/queue.h"

void CreateGraph(Graph** graph,Vertex* vertexList,Edge* edgeList,int lenVertexList, int lenEdgeList){
    VertexNode *vertexNodeList=(VertexNode *)malloc(lenVertexList*sizeof(VertexNode));

    for(int i=0;i<lenVertexList;i++){
       vertexNodeList[i].firstedge=NULL;
       vertexNodeList[i].data=vertexList[i].data;
       printf("insert vertex node: %c\n",vertexNodeList[i].data);
    }

     for(int i=0;i<lenEdgeList;i++){
       int vertexA=edgeList[i].vertexA,vertexB=edgeList[i].vertexB;

        EdgeNode* newNode=(EdgeNode *)malloc(sizeof(EdgeNode));
        newNode->adjVextexIndex=vertexB;
        printf("insert edge node: %d\n",newNode->adjVextexIndex);
        newNode->next=vertexNodeList[i].firstedge;
        vertexNodeList[i].firstedge=newNode;

        EdgeNode* newNode2=(EdgeNode *)malloc(sizeof(EdgeNode));
        newNode2->adjVextexIndex=vertexA;
        printf("insert edge node: %d\n",newNode2->adjVextexIndex);
        newNode2->next=vertexNodeList[i].firstedge;
        vertexNodeList[i].firstedge=newNode2;
    }

    (*graph)=(Graph*)malloc(sizeof(Graph));
    (*graph)->numVertex=lenVertexList;
    (*graph)->numEdge=lenEdgeList;
    (*graph)->vertexNodeList=vertexNodeList;
    return;
}



 int* initVisited(int len){
    int* visited;
    visited=(int*)malloc(len*sizeof(int));
    for(int i=0;i<len;i++){
        visited[i]=0;
    }
    return visited;
}

void DFSTraverse(Graph* graph){
    int* visited=initVisited(graph->numVertex);
    for(int i=0;i<graph->numVertex;i++){
        if(visited[i]==0){
            DFS(graph,i,visited);
        }
    }
}

void DFS(Graph* graph,int i,int* visited){
    visited[i]=1;
    printf("DFS Traverse: %c\n",(graph->vertexNodeList)[i].data);

    EdgeNode* edgeNode=(graph->vertexNodeList)[i].firstedge;
    while(edgeNode){
        if(visited[edgeNode->adjVextexIndex]==0){
            DFS(graph,edgeNode->adjVextexIndex,visited);
        }
        edgeNode=edgeNode->next;
    }
}

void BFSTraverse(Graph* graph){
    int* visited=initVisited(graph->numVertex);
    for(int i=0;i<graph->numVertex;i++){
        VertexNode vertexNode=graph->vertexNodeList[i]
        
    }
}