#! /bin/bash

sed -n "1,1p" 's/^\([^ ]*\) \([^ ]*\) \([^ ]*\)/\3 \1 \2/' problem3.txt