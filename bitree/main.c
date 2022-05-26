#include"stdio.h"
#include"include/bitree.h"

int main(){
    char list[]="AB#D##C##"; //Pre-Order

    BiTNode* root=NULL;
    PreOrderGenerateBiTree(&root,list);

    PreOrderTraverseBiTree(root);
    printf("\n");
    InOrderTraverseBiTree(root);
    printf("\n");
    PostOrderTraverseBiTree(root);
    
    return 0;
}