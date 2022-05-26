#pragma once

struct BiTNode
{
    char data;
    struct BiTNode *lChild,*rChild;
};


typedef struct BiTNode BiTNode;

typedef struct BiTNode* BiTree;


void PreOrderGenerateBiTree(BiTNode** root,char* list);

void PreOrderTraverseBiTree(BiTNode* root);
void InOrderTraverseBiTree(BiTNode* root);
void PostOrderTraverseBiTree(BiTNode* root);
