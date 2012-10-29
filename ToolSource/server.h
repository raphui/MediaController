#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>

#include "types.h"
#include "mediaPlayManager.h"

#define BUFF_SIZE   1024

int createServer( void );
int closeServer( void );
void receivingThread( void *socket );

#endif // SERVER_H
