#!/bin/sh
#script for assignment 1
#Author: Kishore Ellanti

if [ $# -lt 2 ]
then
	echo "required atleast two command line arguments"
	return 1
fi

echo "given path is $1"
touch $1

if [ $? -ne 0 ]
then
	echo "error in creating a file at the specified path"
	return 1
fi

echo $2 > $1
