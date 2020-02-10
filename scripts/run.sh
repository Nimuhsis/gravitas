#!/bin/bash

DIR=$1
EXE=$2

BLUE="\033[0;34m"
RESET="\033[0m"

if [ -d "./bin/$DIR" ] && [ -f "./bin/$DIR/$EXE" ]; then
	./bin/"$DIR"/"$EXE"
else
	echo "Either ${BLUE}${DIR}${RESET} is not a directory or ${BLUE}${EXE}${RESET} is not an executable\n" 
fi


#fl=$1
#fl2=$2
#fl_name="${fl%%.*}" 
#gcc $@ -o $fl_name -lSDL2 && ./$fl_name
