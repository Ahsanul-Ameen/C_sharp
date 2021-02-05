#!/bin/bash
NEWLINE=$'\n'

file=$1

exe_file="${file%.*}.exe";
text_file="${file%.*}.txt";

# command for .CS
mcs -out:$exe_file $file
mono $exe_file
monodis --output=decompiled-$text_file $exe_file
#

terminate=""
END=50
for i in $(seq 1 $END); do 
	terminate="${terminate}~"; 
done

echo "${NEWLINE}${terminate}"
echo "Completed running: $exe_file";
echo "Removing $exe_file and decompiled-$text_file...";
rm  "decompiled-$text_file" $exe_file;
echo "${terminate}"