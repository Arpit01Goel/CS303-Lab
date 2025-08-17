#! /bin/bash

word="$1"
shift  # remove first element

for file in "$@"; do
    sed -i "/$word/d" "$file"
done
