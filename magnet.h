//  magnet.h
//  
//  

#ifndef _MAGNET_H_
#define _MAGNET_H_


#include <stdio.h>
#include <stdbool.h>   // for Boolean
#include <stdio.h>     // for printf()
#include <stdlib.h>


typedef struct  {
    char* pInfoHash;
    char* pDisplayName;
    char* pTracker;
    short int numTrackers;
} Magnet;


void PrintMagnet( const Magnet* pMagnet );
void FreeMagnet(Magnet* pMagnet);  // release malloc'd mem

#endif
