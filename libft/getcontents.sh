#!/bin/sh

# $# == ARGC
LIBARY=$1

if [ $# == 0 ]; then
	echo "please enter a name"
	exit 1
fi

PREFIX=./
if [ $(echo $LIBARY | grep -e "/" | wc -c) != 0 ]; then
	if [ $(echo $LIBARY | cut -c 1-2) == "./" ]; then
		PREFIX=""
	fi
	PREFIX+=$(echo $LIBARY | rev | cut -d / -f2- | rev)/
fi
PREFIX=$(echo $PREFIX | sed 's/\//\\\//g')
TEMP=$(nm -AUjg $LIBARY | cut -d: -f2)
TEMP=$(echo $TEMP | sed 's/ /\
/g' | sed "s/^/$PREFIX/g")
echo $TEMP