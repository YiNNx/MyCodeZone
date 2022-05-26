#include"stdio.h"
#include"stdlib.h"
#include"include/graph.h"

void CreateGraph(Graph** graph,Vertex* vertexList,Edge* edgeList){
    int lenVertexList=sizeof(vertexList)/sizeof(vertexList[0]);
    int lenEdgeList=sizeof(edgeList)/sizeof(edgeList[0]);

    (*graph)=(Graph*)malloc(sizeof(Graph));
    (*graph)->numVertex=lenVertexList;
    (*graph)->numEdge=lenEdgeList;

    VertexNode *vertexNodeList=(VertexNode *)malloc(lenVertexList*sizeof(VertexNode));

    for(int i=0;i<lenVertexList;i++){
       vertexNodeList[i].firstedge=NULL;
       vertexNodeList[i].data=vertexList[i].data;
    }

    for(int i=0;i<lenEdgeList;i++){
       int vertexA=edgeList[i].vertexA,vertexB=edgeList[i].vertexB;

       if (vertexNodeList[vertexA].firstedge==NULL){
           EdgeNode* edgeNode=(EdgeNode *)malloc(sizeof(EdgeNode));
           edgeNode->adjVextexIndex=vertexB;
           edgeNode->next=NULL;

           vertexNodeList[vertexA].firstedge=edgeNode;
       }else{
            EdgeNode* edgeNode=vertexNodeList[vertexA].firstedge;
            while(edgeNode){
               edgeNode=edgeNode->next;
            }

            EdgeNode* newNode=(EdgeNode *)malloc(sizeof(EdgeNode));
            newNode->adjVextexIndex=vertexB;
            newNode->next=NULL;

            edgeNode->next=newNode;
       }


       if (vertexNodeList[vertexB].firstedge==NULL){
           EdgeNode* edgeNode=(EdgeNode *)malloc(sizeof(EdgeNode));
           edgeNode->adjVextexIndex=vertexA;
           edgeNode->next=NULL;

           vertexNodeList[vertexB].firstedge=edgeNode;
       }else{
            EdgeNode* edgeNode=vertexNodeList[vertexB].firstedge;
            while(edgeNode){
               edgeNode=edgeNode->next;
            }

            EdgeNode* newNode=(EdgeNode *)malloc(sizeof(EdgeNode));
            newNode->adjVextexIndex=vertexA;
            newNode->next=NULL;

            edgeNode->next=newNode;
       }
    }

    (*graph)->vertexNodeList=vertexNodeList;
    return;
}

int* visited;

void initVisited(int len){
    visited=(int*)malloc(len*sizeof(int));
    for(int i=0;i<len;i++){
        visited[i]=0;
    }
    return;
}

void DFSTraverse(Graph* graph){
    initVisited(graph->numVertex);
    for(int i=0;i<graph->numVertex;i++){
        if(visited[i]==0){
            DFS(graph,i);
        }
    }
}

void DFS(Graph* graph,int i){
    visited[i]=1;
    printf("DFS Traverse: %c\n",(graph->vertexNodeList)[i].data);

    EdgeNode* edgeNode=(graph->vertexNodeList)[i].firstedge;
    while(edgeNode){
        if(visited[edgeNode->adjVextexIndex]==0){
            DFS(graph,edgeNode->adjVextexIndex);
        }
        edgeNode=edgeNode->next;
    }
}

void BFSTraverse(Graph* graph){

}