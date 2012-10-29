#!bin/bash
key=$1
win=$( xdotool search --onlyvisible --class vlc | head -1 )
xdotool windowactivate $win
xdotool key --clearmodifiers --window $win $key
