//  main.c
//  
//  

#include "parser.h"
#include "config.h"

int main ( void )  {
    Magnet magnet = {0}; // initialize all to zero or NULL
    Magnet* pMagnet = &magnet;

    char* pMagnetURI = loadConfig();

    if ( ParseMagnet(pMagnet, pMagnetURI) == false ){
        return -1;
    }

    PrintMagnet( pMagnet );

    FreeMagnet( pMagnet );

    return 0;
}
