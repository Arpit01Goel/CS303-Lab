#! /bin/bash

echo "Enter string, starting index, length (one in each line):"
read str
read st
read len


substring=${str:$st:$len}
echo "$substring"
