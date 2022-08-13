#!/bin/sh
# Script for Assignment 1
# Author: Kishore Ellanti

set -e
set -u

#echo "arguments received are $1 and $2"
if [ $# -lt 2 ]
then
	echo "return with error, Expecting two command line arguments"
	return 1
fi

if [ ! -d $1 ]
then
	echo "given path invalid"
	return 1
fi

NUMFILES=`grep -rl $2 $1 | wc -l`
MATCHING_LINES=`grep -r $2 $1 | wc -l`

#echo ${NUMFILES}
#echo ${MATCHING_LINES}
MATCHSTR="The number of files are ${NUMFILES} and the number of matching lines are ${MATCHING_LINES}"

echo ${MATCHSTR}
