#include "mediaPlayManager.h"

char *getCommand( const char *func )
{
    int i;

    for( i = 0 ; i < NUM_COMMAND_AVAILABLE ; i++ )
    {
        if( strcmp( func , keysAvailable[i].function ) == 0 )
        {
            return keysAvailable[i].command;
        }
    }

    return NULL;
}

int sendCommand( const char *command )
{
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
    }

    return PC_SUCCESS;
}
