#include <stdio.h>
#include "server.h"

int main(void)
{
    char choose;
    int media;

    printf("[?]Launch server on port 1337 ? (y/n) ");
    scanf("%c" , &choose );

    printf("[?]Media player to control:\n");
    printf("[1]VLCPLayer\n");
    printf("[2]OMXPlayer\n");
    printf("[!]Choice: ");
    scanf("%d", &media );

    //Set the Media Player to controll
    setMediaPlayer( media );

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

