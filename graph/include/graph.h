#pragma once

typedef char VertexType;

typedef struct EdgeNode{
    int adjVextexIndex;
    struct EdgeNode* next;
}EdgeNode;

typedef struct VertexNode {
    VertexType data;
    struct EdgeNode* firstedge;
}VertexNode;

typedef struct Graph{
    VertexNode *vertexNodeList;
    int numVertex;
    int numEdge;
}Graph;

typedef struct Vertex{
    int index;
    VertexType data;
}Vertex;

typedef struct Edge{
    int vertexA;
    int vertexB;
}Edge;

void CreateGraph(Graph** graph,Vertex* vertexList,Edge* edgeList,int lenVertexList, int lenEdgeList);

void DFSTraverse(Graph* graph);

void DFS(Graph* graph,int i);

void BFSTraverse(Graph* graph);
