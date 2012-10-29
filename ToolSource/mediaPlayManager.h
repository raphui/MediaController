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


//Only available in this file
static s_commandAvailable keysAvailable[] =
{
    "Play"          ,   "space",
    "Pause"         ,   "space",
    "Forward"       ,   "Shift+Right",
    "Rewind"        ,   "Shift+Left",
    "VolumeUp"      ,   "Ctrl+Up",
    "VolumeDown"    ,   "Ctrl+Down",
    "Time"          ,   "t"
};


char *getCommand( const char *func );
int sendCommand( const char *command );

#endif // MEDIAPLAYERMANAGER_H
