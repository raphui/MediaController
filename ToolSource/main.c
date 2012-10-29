#include <stdio.h>
#include "server.h"

int main(void)
{
    char choose;

    printf("[?]Launch server on port 1337 ? (y/n) ");
    scanf("%c" , &choose );

    if( choose == 'y' )
    {
        printf("[+]Create server...\n");

        createServer();
    }
    else
    {
        return 0;
    }

    printf("\n");
    return 0;
}

