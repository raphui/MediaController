#ifndef MEDIAPLAYERMANAGER_H
#define MEDIAPLAYERMANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

#define SCRIPT_COMMAND          "sh /home/raphio/vlcController.sh "
#define NUM_COMMAND_AVAILABLE   7

typedef struct commandAvailable
{
    const char *function;
    char *command;

}s_commandAvailable;

static s_commandAvailable *keys;


//Only available in this file
static s_commandAvailable keysAvailableVLC[] =
{
    {   "Play"          ,   "space"         },
    {   "Pause"         ,   "space"         },
    {   "Forward"       ,   "Ctrl+Right"    },
    {   "Rewind"        ,   "Ctrl+Left"     },
    {   "VolumeUp"      ,   "Ctrl+Up"       },
    {   "VolumeDown"    ,   "Ctrl+Down"     },
    {   "Time"          ,   "t"             }
};

static s_commandAvailable keysAvailableOMX[] =
{

    {   "Play"          ,   "p"             },
    {   "Pause"         ,   "p"             },
    {   "Forward"       ,   "Right"         },
    {   "Rewind"        ,   "Left"          },
    {   "VolumeUp"      ,   "+"             },
    {   "VolumeDown"    ,   "-"             },
    {   "Time"          ,   "z"             }
};


char *getCommand( const char *func );
int sendCommand( const char *command );
void setKeys( int mp );

#endif // MEDIAPLAYERMANAGER_H
