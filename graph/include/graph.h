#pragma once

typedef char VertexType;

typedef struct EdgeNode{
    int adjVextexIndex;
    int weight;
    struct EdgeNode* next;
}EdgeNode;

typedef struct VertexNode {
    VertexType data;
    struct EdgeNode* firstedge;
}VertexNode;

typedef struct LGraph{
    VertexNode *vertexNodeList;
    int numVertex;
    int numEdge;
}LGraph;

typedef struct Vertex{
    int index;
    VertexType data;
}Vertex;

typedef struct Edge{
    int vertexA;
    int vertexB;
}Edge;

void CreateGraph(LGraph** graph,Vertex* vertexList,Edge* edgeList,int lenVertexList, int lenEdgeList);

void DFSTraverse(LGraph* graph);

void DFS(LGraph* graph,int i,int* visited);

void BFSTraverse(LGraph* graph);

// -------------------------

#define INFINITY 65535

typedef struct
{
	int* vexs;
	int** arc;
	int numVertexes, numEdges;
}MGraph;

void InitMGraph(MGraph **graph,int numEdges,int numVertexes);

void Floyd(MGraph* graph);

void Dijkstra(MGraph* graph,int v0);