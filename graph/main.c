#include"stdio.h"
#include"include/graph.h"

int main(){
    Vertex vertexList[]={{0,'A'},{1,'B'},{2,'C'},{3,'D'},{4,'E'},{5,'F'},{6,'G'},{7,'H'},{8,'I'}};
    Edge edgeList[]={{0,5,11},{0,1,10},{1,8,12},{1,6,16},{1,2,18},{2,8,8},{2,3,22},{6,3,24},{7,3,16},{4,3,20},{8,3,21},{4,7,7},{4,5,26},{5,6,17},{6,7,19}};
    LGraph* lgraph=NULL;
    CreateGraph(&lgraph,vertexList,edgeList,9,15);
    DFSTraverse(lgraph);
    BFSTraverse(lgraph);

    MGraph* mgraph=NULL;
    InitMGraph(mgraph,16,9);

	mgraph->arc[0][1]=1;
	mgraph->arc[0][2]=5; 
	mgraph->arc[1][2]=3; 
	mgraph->arc[1][3]=7; 
	mgraph->arc[1][4]=5; 

	mgraph->arc[2][4]=1; 
	mgraph->arc[2][5]=7; 
	mgraph->arc[3][4]=2; 
	mgraph->arc[3][6]=3; 
	mgraph->arc[4][5]=3;

	mgraph->arc[4][6]=6;
	mgraph->arc[4][7]=9; 
	mgraph->arc[5][7]=5; 
	mgraph->arc[6][7]=2; 
	mgraph->arc[6][8]=7;

	mgraph->arc[7][8]=4;

	for(int i = 0; i < mgraph->numVertexes; i++)
	{
		for(int j = i; j < mgraph->numVertexes; j++)
		{
			mgraph->arc[j][i] =mgraph->arc[i][j];
		}
	}

    return 0;
}