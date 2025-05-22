//  parser.c
//  
//  

#include "parser.h"


bool ParseMagnet( Magnet* pMagnet, const char* pURI){
    
    if(GetInfoHash( pMagnet, pURI )==false){
        return -1;
    }
    if(GetDisplayName( pMagnet, pURI )==false){
        return -1;
    }
    if(GetTracker( pMagnet, pURI )==false){
        return -1;
    }

    return true;
}

static bool GetInfoHash( Magnet* pMagnet, const char* pURI ){

    const char* start = strstr(pURI, "xt=");
    if (!start){
        return false;
    }
    start += 3;

    const char* end = strstr(start, "&dn");
    if (!end){
        return false;
    }
    size_t length = end - start;

    pMagnet->pInfoHash = malloc(length + 1);
    if(!pMagnet->pInfoHash){
        return false;
    }
    strncpy(pMagnet->pInfoHash, start, length);
    pMagnet->pInfoHash[length] = '\0';

    return true;
}

static bool GetDisplayName( Magnet* pMagnet, const char* pURI ){
    const char* start = strstr(pURI, "dn=");
    if (!start){
        return false;
    }
    start += 3;

    const char* end = strstr(start, "&tr");
    if (!end){
        return false;
    }
    size_t length = end - start;

    pMagnet->pDisplayName = malloc(length + 1);
    if(!pMagnet->pDisplayName){
        return false;
    }
    strncpy(pMagnet->pDisplayName, start, length);
    pMagnet->pDisplayName[length] = '\0';

    return true;
}
static bool GetTracker( Magnet* pMagnet, const char* pURI ){
    
    const char* start = strstr(pURI, "tr=");
    if (!start){
        return false;
    }
    start += 3;

   size_t length = strlen(start);  // from first tracker to end

    pMagnet->pTracker = malloc(length + 1);
    if(!pMagnet->pTracker){
        return false;
    }
    strncpy(pMagnet->pTracker, start, length);
    pMagnet->pTracker[length] = '\0';

    return true;
}
