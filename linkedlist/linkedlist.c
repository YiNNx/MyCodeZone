#include"stdio.h"
#include"stdlib.h"
#include"include/linkedlist.h"

void InitList(LinkedList* list){
    struct Node* head=NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->value=0;
    head->next=NULL;
    *list=head;
}

void GenerateList(LinkedList list,int* numList,int len){
    struct Node* tail=list;

    for(int i=0;i<len;i++){
        tail->next=(struct Node*)malloc(sizeof(struct Node));
        tail->next->value=numList[i];
        printf("insert: %d\n",numList[i]);
        tail=tail->next;
    }
    tail=NULL;

    return;
}

void ListTraverse(LinkedList list){
    struct Node *pointer=list->next;
    if(pointer==NULL){
        printf("traverse: null\n");
    }
    while(pointer){
        printf("traverse: %d\n",pointer->value);
        pointer=pointer->next;
    }
}

void ChearList(LinkedList list){
    struct Node* node=list->next;
    while(node){
        struct Node* tmp=node;
        node=node->next;
        free(tmp);
    }
    list->next=NULL;
}

void PriorElem(LinkedList list,int cur_val){
    struct Node* cur_p=list->next,*pre_p=cur_p;
    if(cur_p->value==cur_val){
        printf("error: cur_val doesn't have pre_val\n");
        return;
    }
    cur_p=cur_p->next;

    while(cur_p){
        if(cur_p->value==cur_val){
            printf("pre_val: %d\n",pre_p->value);
        }
        pre_p=cur_p;
        cur_p=cur_p->next;
    }
}

void NextElem(LinkedList list,int cur_val){
    struct Node* cur_p=list->next;
    while(cur_p){
        if(cur_p->value==cur_val){
            if(cur_p->next){
                printf("next_val: %d\n",cur_p->next->value);
            }else{
                printf("error: cur_val doesn't have pre_val\n");
            }
        }
        cur_p=cur_p->next;
    }
}

void ListInsert(LinkedList list,int index,int val){
    struct Node* pre_p=list,*cur_p=list->next;
    for(int i=0;i<index;i++){
        pre_p=pre_p->next;
        cur_p=cur_p->next;
    }
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->value=val;
    pre_p->next=newNode;
    newNode->next=cur_p;
    return;
}

void ListDelete(LinkedList list,int index){
    struct Node* pre_p=list,*cur_p=list->next;
    for(int i=0;i<index;i++){
        pre_p=pre_p->next;
        cur_p=cur_p->next;
    }
    pre_p->next=cur_p->next;
    printf("delete: %d\n",cur_p->value);
    free(cur_p);
    return;
}

