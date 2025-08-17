#! /bin/bash

echo "With quotes:"
echo "arg1: [$1]"
echo "arg1 with quotes: [$1]"
echo "arg1 without quotes: [$1]"

echo
echo "Without quotes:"
echo arg1: [$1]
echo arg1 with quotes: [$1]
echo arg1 without quotes: [$1]

echo
echo "Looping over arguments with and without quotes:"
echo "With quotes:"
for arg in "$1"; do
    echo "[$arg]"
done

echo "Without quotes:"
for arg in $1; do
    echo "[$arg]"
done