// list.h
// 
// 

#ifndef _LIST_H_
#define _LIST_H_


#include "node.h"
#include <stdbool.h>   // for Boolean


typedef struct {
  ListNode*  pFirstNode;
  int        nodeCount;
} LinkedList;

LinkedList* CreateLinkedList( void );

int  Size( LinkedList* pList );

bool  IsEmpty( LinkedList* pList );

void InsertNodeToBack( LinkedList* pList , ListNode* pNode );

void PrintList(LinkedList* pList);

void DeleteList(LinkedList* pList);

#endif
