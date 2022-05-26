#include"stdio.h"
#include"include/linkedlist.h"

int main(){
    int numList[]={1,2,3,4,5,6};

    LinkedList linkedList;
    InitList(&linkedList);
    GenerateList(linkedList,numList,sizeof(numList)/sizeof(numList[0]));
    ListTraverse(linkedList);

    PriorElem(linkedList,4);
    NextElem(linkedList,4);

    ListInsert(linkedList,3,99);
    ListTraverse(linkedList);

    ListDelete(linkedList,3);
    ListTraverse(linkedList);

    ChearList(linkedList);
    ListTraverse(linkedList);
    
    return 0;
}