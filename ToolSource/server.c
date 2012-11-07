#include "server.h"

int createServer( void )
{
    int s_server = socket( AF_INET , SOCK_STREAM , 0 );
    int s_client[MAX_CLIENTS];
    int nbClient = 0;
    int i;

    struct sockaddr_in serv_addr;

    //Max 3 clients so 3 differents threads
    pthread_t thread[MAX_THREAD];

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

    if( listen( s_server , MAX_CLIENTS ) < 0 )
    {
        printf("[-]Error to listen to 10 connection.\n");

        return PC_ERROR;
    }

    while( 1 )
    {

        if( nbClient == 0 )
        {
            s_client[0] = accept( s_server , NULL , NULL );
        }
        else
        {
            s_client[ nbClient ] = accept( s_server , NULL , NULL );
        }

        printf("[!]New client connected , id: %d.\n" , nbClient++ );

        pthread_create( &thread[ nbClient - 1 ] , NULL , receivingThread , &s_client[ nbClient - 1 ] );


    }


    return PC_SUCCESS;
}


int closeServer( void )
{

    return PC_SUCCESS;
}

void *receivingThread( void *socket )
{
    char buff[BUFF_SIZE];
    int ret;

    printf("[!]Receiving thread create with pid : %d !\n" , ( long int ) syscall( 224 ) );

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

        }

    }

    printf("[!]Quitting receiving thread with pid: %d !\n" , ( long int ) syscall( 224 ) );

    pthread_exit( NULL );
}

void setMediaPlayer( int mp )
{
    setKeys( mp );
}
