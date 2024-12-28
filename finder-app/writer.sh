#!/bin/bash

if [ $# -ne 2 ]
then
    echo "Not Enough Parameters"
    exit 1
else
    writefile="$1"
    writestr="$2"
fi

mkdir -p "$(dirname "$writefile")"

echo  "$writestr" > "$writefile"
echo "Created"
exit 0
