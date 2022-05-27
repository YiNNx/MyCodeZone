#include"stdio.h"
#include"include/graph.h"

int main(){
    Vertex vertexList[]={{0,'A'},{1,'B'},{2,'C'},{3,'D'},{4,'E'}};
    Edge edgeList[]={{0,1},{0,2},{0,3},{1,2},{2,3}};
    Graph* graph=NULL;
    CreateGraph(&graph,vertexList,edgeList,5,5);
    DFSTraverse(graph);
    //BFSTraverse(graph);
    return 0;
}