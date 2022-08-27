#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 

typedef int Status; 

typedef int QElemType;   

typedef struct QNode	  
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct			  
{
   QueuePtr front,rear;   
}LinkQueue;

Status visit(QElemType c);

Status InitQueue(LinkQueue *Q);

  
Status DestroyQueue(LinkQueue *Q);

  
Status ClearQueue(LinkQueue *Q);

  
Status QueueEmpty(LinkQueue Q);

  
int QueueLength(LinkQueue Q);

  
Status GetHead(LinkQueue Q,QElemType *e);


  
Status EnQueue(LinkQueue *Q,QElemType e);

  
Status DeQueue(LinkQueue *Q,QElemType *e);

  
Status QueueTraverse(LinkQueue Q);
