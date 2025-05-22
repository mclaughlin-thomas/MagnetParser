//  magnet.c
//  
//  

#include "magnet.h"


// bool InitializeMagnet( Magnet* pMagnet, char* pNewInfoHash, char* pNewDisplayName, char* pNewTracker){
//   pMagnet->pInfoHash = pNewInfoHash;
//   pMagnet->pDisplayName = pNewDisplayName;
//   pMagnet->pTracker = pNewTracker;
// }

void PrintMagnet( const Magnet* pMagnet ){
    printf("InfoHash: %s\n", pMagnet->pInfoHash);
    printf("DisplayName: %s\n", pMagnet->pDisplayName);
    printf("Tracker: %s\n", pMagnet->pTracker);
}

void FreeMagnet(Magnet* pMagnet) {
    if (!pMagnet){
        return;
    }

    if (pMagnet->pInfoHash) {
        free(pMagnet->pInfoHash);
        pMagnet->pInfoHash = NULL;
    }

    if (pMagnet->pDisplayName) {
        free(pMagnet->pDisplayName);
        pMagnet->pDisplayName = NULL;
    }

    if (pMagnet->pTracker) {
        free(pMagnet->pTracker);
        pMagnet->pTracker = NULL;
    }
}
