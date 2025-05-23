//  magnet.h
//  
//  

#ifndef _MAGNET_H_
#define _MAGNET_H_

#include "list.h"
#include <stdint.h>    // special int types


typedef struct  {
    char* pInfoHash;
    char* pDisplayName;
    LinkedList* pTracker;
    uint8_t numTrackers;
} Magnet;


void PrintMagnet( const Magnet* pMagnet );
void FreeMagnet(Magnet* pMagnet);  // release malloc'd mem

#endif
