//  main.c
//  
//  

#include "parser.h"


int main ( void )  {
    Magnet magnet = {0}; // initialize all to zero or NULL
    Magnet* pMagnet = &magnet;

    char* pMagnetURI = "magnet:?xt=urn:btih:FDA8F581B7A3F77F7045EFA5AB581B5BACBF387E&dn=Andor%20S02E08%201080p%20WEB%20H264-SuccessfulCrab&tr=udp%3A%2F%2Ftracker.opentrackr.org%3A1337";

    if ( ParseMagnet(pMagnet, pMagnetURI) == false ){
        return -1;
    }

    PrintMagnet( pMagnet );

    FreeMagnet(pMagnet);

    return 0;
}
