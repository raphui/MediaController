#include "server.h"

int createServer( void )
{
    int s_server = socket( AF_INET , SOCK_STREAM , 0 );
    int s_client;

    struct sockaddr_in serv_addr;

    pthread_t thread;

    if( s_server < 0 )
    {
        printf("[-]Error to create socket.\n");

        return PC_ERROR;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl( INADDR_ANY );
    serv_addr.sin_port = htons( 1337 );

    if( bind( s_server , ( struct sockaddr* )&serv_addr, sizeof( serv_addr ) ) < 0 )
    {
        printf("[-]Error to bind on port: 1337.\n");

        return PC_ERROR;
    }

    if( listen( s_server , 10 ) < 0 )
    {
        printf("[-]Error to listen to 10 connection.\n");

        return PC_ERROR;
    }

    while( 1 )
    {

        s_client = accept( s_server , NULL , NULL );

        printf("[!]New client connected.\n");
        pthread_create( &thread , NULL , receivingThread , &s_client );

    }


    return PC_SUCCESS;
}


int closeServer( void )
{

    return PC_SUCCESS;
}

void receivingThread( void *socket )
{
    char buff[BUFF_SIZE];
    int ret;

    printf("[!]Receiving thread create !\n");

    while( 1 )
    {
        memset( buff , 0 , BUFF_SIZE );

        ret = recv( *( int *)socket , buff , BUFF_SIZE , 0 );

        if( ret > 0 )
        {
            printf("[+]Data: %s\n" , buff );

            if( strcmp( buff , "Disconnect" ) == 0 )
            {
                close( *( int *)socket );

                printf("[-]Client disconnect.\n");

                break;
            }
            else
            {

                sendCommand( buff );
            }

//            if( strcmp( buff , "Play" ) == 0 )
//            {
//                printf("[+]Play request.\n");

//                sendCommand(SCRIPT_COMMAND "space");
//            }
//            else if( strcmp( buff , "Disconnect" ) == 0 )
//            {
//                close( *( int *)socket );

//                printf("[-]Client disconnect.\n");

//                break;
//            }
//            else if( strcmp( buff , "Forward" ) == 0 )
//            {
//                sendCommand(SCRIPT_COMMAND "Shift+Right");
//            }
//            else if( strcmp( buff , "Rewind" ) == 0 )
//            {
//                sendCommand(SCRIPT_COMMAND "Shift+Left");
//            }
//            else if( strcmp( buff , "VolumeUp" ) == 0 )
//            {
//                sendCommand(SCRIPT_COMMAND "Ctrl+Up");
//            }
//            else if( strcmp( buff , "VolumeDown" ) == 0 )
//            {
//                sendCommand(SCRIPT_COMMAND "Ctrl+Down");
//            }
//            else if( strcmp( buff , "Time" ) == 0 )
//            {
//                sendCommand(SCRIPT_COMMAND "t");
//            }

            //memset( buff , 0 , BUFF_SIZE );
        }

    }

    printf("[!]Quitting receiving thread !\n");

    pthread_exit( NULL );
}
