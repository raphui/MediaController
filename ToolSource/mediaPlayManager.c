#include "mediaPlayManager.h"

void setKeys( int mp )
{
    if( mp == 1 )
    {
        keys = &keysAvailableVLC;
    }
    else if( mp == 2 )
    {
        keys = &keysAvailableOMX;
    }
}

char *getCommand( const char *func )
{
    int i;

    for( i = 0 ; i < NUM_COMMAND_AVAILABLE ; i++ )
    {
        if( strcmp( func , keys[i].function ) == 0 )
        {
            return keys[i].command;
        }
    }

    return NULL;
}

int sendCommand( const char *command )
{
    int status = PC_SUCCESS;

    char *key = getCommand( command );

    if( key != NULL )
    {
        char *systemString = ( char * ) malloc( 255 * sizeof( char ) );

        strcpy( systemString , SCRIPT_COMMAND );
        strcat( systemString , key );

        system( systemString );

        printf("[+]Command: %s sended.\n" , systemString );

        free( systemString );
    }
    else
    {
        printf("[-]Command not valid: %s\n" , command );

        status = PC_ERROR;

    }

    return status;
}
