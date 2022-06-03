#include"stdio.h"
#include"stdlib.h"
#include"include/graph.h"
#include"../queue/queue.h"

void CreateGraph(LGraph** graph,Vertex* vertexList,Edge* edgeList,int lenVertexList, int lenEdgeList){
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
        newNode->next=vertexNodeList[vertexA].firstedge;
        vertexNodeList[vertexA].firstedge=newNode;

        EdgeNode* newNode2=(EdgeNode *)malloc(sizeof(EdgeNode));
        newNode2->adjVextexIndex=vertexA;
        printf("insert edge node: %d\n",newNode2->adjVextexIndex);
        newNode2->next=vertexNodeList[vertexB].firstedge;
        vertexNodeList[vertexB].firstedge=newNode2;
    }

    (*graph)=(LGraph*)malloc(sizeof(LGraph));
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

void DFSTraverse(LGraph* graph){
    int* visited=initVisited(graph->numVertex);
    for(int i=0;i<graph->numVertex;i++){
        if(visited[i]==0){
            DFS(graph,i,visited);
        }
    }
    printf("\n");
}

void DFS(LGraph* graph,int i,int* visited){
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

void BFSTraverse(LGraph* graph){
    int* visited=initVisited(graph->numVertex);
    LinkQueue queue;
    InitQueue(&queue);
    for(int i=0;i<graph->numVertex;i++){
        if(visited[i]!=1){
            EnQueue(&queue,i);
            visited[i]=1;
            printf("BFS Traverse: %c\n",graph->vertexNodeList[i].data); 
        }
        while(!QueueEmpty(queue)){
            int vextexIndex;
            DeQueue(&queue,&vextexIndex); 
            struct EdgeNode* node= graph->vertexNodeList[vextexIndex].firstedge;
            while(node!=NULL){
                if(!visited[node->adjVextexIndex]){
                    EnQueue(&queue,node->adjVextexIndex);
                    printf("BFS Traverse: %c\n",graph->vertexNodeList[node->adjVextexIndex].data); 
                    visited[node->adjVextexIndex]=1;
                }
                node=node->next;
            }  
        }
    }
    printf("\n");
}