// node.h
// 
// 

#ifndef _NODE_H_
#define _NODE_H_

#include <stdio.h>         // for printf() and fprintf()
#include <stdlib.h> 


typedef struct ListNode{
  struct ListNode*  pNext;
  char*  pData;
} ListNode;

void PrintNode( ListNode* pNode );

void OutOfStorage( void );

ListNode* CreateNode(char* newPData);

#endif