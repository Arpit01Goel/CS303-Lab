#!/bin/bash

for file in "$@"
do
  if [ -f "$file" ]; then
    tr 'a-z' 'A-Z' < "$file" > "${file}.tmp"
    mv "${file}.tmp" "$file"
  else
    echo "$file does not exist"
  fi
done