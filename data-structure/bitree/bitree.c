#include"stdio.h"
#include"stdlib.h"
#include"include/bitree.h"

int i=0;

void PreOrderGenerateBiTree(BiTNode** root,char* list){
    if(list[i]=='#'){
        i++;
        return;
    }

    (*root)=(BiTNode*)malloc(sizeof(BiTNode));
    (*root)->lChild=(*root)->rChild=NULL;

    (*root)->data=list[i++];
    PreOrderGenerateBiTree(&((*root)->lChild),list);
    PreOrderGenerateBiTree(&((*root)->rChild),list);

    return;
}

void PreOrderTraverseBiTree(BiTNode* root){
    if(root==NULL){
        return;
    }

    printf("pre order traverse:%c\n",root->data);
    PreOrderTraverseBiTree(root->lChild);
    PreOrderTraverseBiTree(root->rChild);

    return;
}


void InOrderTraverseBiTree(BiTNode* root){
    if(root==NULL){
        return;
    }

    InOrderTraverseBiTree(root->lChild);
    printf("in order traverse:%c\n",root->data);
    InOrderTraverseBiTree(root->rChild);

    return;
}


void PostOrderTraverseBiTree(BiTNode* root){
    if(root==NULL){
        return;
    }

    PostOrderTraverseBiTree(root->lChild);
    PostOrderTraverseBiTree(root->rChild);
    printf("post order traverse:%c\n",root->data);
    
    return;
}
