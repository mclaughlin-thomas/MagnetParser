//  parser.c
//  
//  

#include "parser.h"


static bool GetInfoHash( Magnet* pMagnet, const char* pURI );
static bool GetDisplayName( Magnet* pMagnet, const char* pURI );
static bool GetTracker( Magnet* pMagnet, const char* pURI );


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
    
    const char* trackerString = strstr(pURI, "tr=");
    if (!trackerString){
        return false;
    }

    pMagnet->pTracker = CreateLinkedList();
    pMagnet->numTrackers = 0;

    while((trackerString = strstr(trackerString, "tr=")) != NULL){

        trackerString+=3;
        const char* cutoff = strstr(trackerString, "&tr");

        size_t length;
        if (cutoff) { //cutoff found
            length = (size_t)(cutoff - trackerString);
            // This computes how many characters there are between trackerString and cutoff.
        } else { //cutoff not found
            length = strlen(trackerString);
        }

        char* trackerRecord = malloc(length + 1);

        if (!trackerRecord){
            return false;
        }
        strncpy(trackerRecord, trackerString, length);
        trackerRecord[length] = '\0';

        ListNode* node = CreateNode(trackerRecord);
        InsertNodeToBack(pMagnet->pTracker, node);

        pMagnet->numTrackers ++;

        if (cutoff) {
            trackerString = cutoff;  // Move to the '&tr' delimiter
        } else {
            trackerString += length; // No '&tr' found, move to the end of the string
        }
    }
    return true;
}
