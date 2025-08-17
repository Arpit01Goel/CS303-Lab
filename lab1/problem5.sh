#! /bin/bash

# [ ] is test command
# -d checks if its directory and -f for file
# must use ; to seperate commands (syntax of bash language)

if [ -d "$1" ]; then 
    echo "directory"
elif [ -f "$1" ]; then 
    echo "file"
else 
    echo "something else"
fi