#!/bin/bash

user=$1

now=$(date +%s)

login_time=$(who -u | awk -v user="$user" '$1 == user { print $3, $4 }')


start_time=$(date -d "$login_time" +%s)

difference=$(( now - start_time ))

hours=$(( difference / 3600 ))
minutes=$(( (difference % 3600) / 60 ))

echo "$hours hours $minutes minutes."