#!/bin/bash

if [ $# -ne 2 ]
then
    echo "Parameters not specified"
    exit 1
else
    filesdir="$1"
    searchstr="$2"
fi

if [ ! -d "$filesdir" ]
then
    echo "Path given is not a directory"
    exit 1
fi


num_files=$(find "$filesdir" -type f | wc -l)
num_lines=$(grep -r "$searchstr" "$filesdir" | wc -l) 

echo "The number of files are $num_files  and the number of matching lines are $num_lines"

exit 0
