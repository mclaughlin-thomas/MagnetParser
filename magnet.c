//  magnet.c
//  
//  

#include "magnet.h"


void PrintMagnet( const Magnet* pMagnet ){
    printf("InfoHash: %s\n", pMagnet->pInfoHash);
    printf("DisplayName: %s\n", pMagnet->pDisplayName);
    
    printf("Number of Trackers: %d\n", pMagnet->numTrackers);
    ListNode* current = pMagnet->pTracker->pFirstNode;
    while(current){
        printf("Tracker: %s\n", current->pData);
        current = current->pNext;
    }
}

void FreeMagnet(Magnet* pMagnet) {
    if ( !pMagnet ){
        return;
    }

    if ( pMagnet->pInfoHash ) {
        free( pMagnet->pInfoHash );
        pMagnet->pInfoHash = NULL;
    }

    if ( pMagnet->pDisplayName ) {
        free( pMagnet->pDisplayName );
        pMagnet->pDisplayName = NULL;
    }

    if ( pMagnet->pTracker ) {
        ListNode* current = pMagnet->pTracker->pFirstNode;

        while(current){
            free(current->pData);
            ListNode* next = current->pNext;
            free(current);
            current = next;
        }
        
        free(pMagnet->pTracker);
        pMagnet->pTracker = NULL;
    }
}
