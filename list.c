// list.c
// 
// 

#include "list.h"


LinkedList* CreateLinkedList(){
    // Here we use the calloc function to allocate memory for the LinkedList header and initialize
    // all the values in the structure to 0.
    // A pointer to that memory is returned unless calloc fails!
    LinkedList* pLL = (LinkedList*) calloc (1, sizeof(LinkedList));

    if(pLL == NULL){
        OutOfStorage();
    }

    return pLL;
}

int  Size( LinkedList* pList )  {
    return pList->nodeCount;
}

bool  IsEmpty( LinkedList* pList )  {
    return( 0 == pList->nodeCount );
}

void InsertNodeToBack( LinkedList* pList , ListNode* pNode )  {
    if( IsEmpty( pList ) )  {
        pList->pFirstNode = pNode;
    }
    else {
        pNode->pNext = NULL;  // Ensure it's the last node in the list after we insert...
        ListNode* pDummyIterator = pList->pFirstNode ;
        while( NULL != pDummyIterator->pNext )  {
            pDummyIterator = pDummyIterator->pNext;
        } // This yeilds last node, lost node points to NULL
        pDummyIterator->pNext  = pNode;
    }

    pList->nodeCount++;
}

void PrintList(LinkedList* pList) {
    ListNode* Dummy = pList->pFirstNode;
    while (Dummy){
        PrintNode(Dummy);
        Dummy= Dummy->pNext;
    }
}

void DeleteList(LinkedList* pList) {
    ListNode* current = pList->pFirstNode;
    ListNode* next = NULL;

    while (current != NULL) {
        next = current->pNext;
        free(current);
        current = next;
    }

    free(pList);
}