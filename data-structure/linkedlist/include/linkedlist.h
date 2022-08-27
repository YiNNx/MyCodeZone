#pragma once

struct Node {
    int value;
    struct Node* next;
};

typedef struct Node* LinkedList;


void InitList(LinkedList *list);
void GenerateList(LinkedList list,int* numList,int len);
void ChearList(LinkedList list);
void PriorElem(LinkedList list,int cur_val);
void NextElem(LinkedList list,int cur_val);
void ListInsert(LinkedList list,int index,int val);
void ListDelete(LinkedList list,int index);
void ListTraverse(LinkedList list);


