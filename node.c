// node.c
// 
// 

#include "node.h"

void PrintNode( ListNode* pNode )  {
    printf( "Node's Data: %s\n" ,  pNode->pData );
}

ListNode* CreateNode(char* newPData){
    ListNode* pNewNode = (ListNode*) calloc( 1 , sizeof( ListNode) );
    if( NULL == pNewNode ){
        OutOfStorage();
    }
    pNewNode->pData = newPData;  
    return pNewNode;
}

void OutOfStorage( void )  {
    fprintf(stderr,"### PRETTY BAD RUNTIME ERROR ### No Memory Available :(" );
    exit( EXIT_FAILURE );
}
