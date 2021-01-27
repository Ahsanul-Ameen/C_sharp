#!/bin/bash
NEWLINE=$'\n'

file=$1

exe_file="${file%.*}.exe";
text_file="${file%.*}.txt";

mcs -out:$exe_file $file
mono $exe_file
monodis --output=decompiled-$text_file $exe_file

echo "${NEWLINE}-------------------------------------------------";
echo "Completed running: $exe_file";
echo "Removing $exe_file and decompiled-$text_file...";
rm  "decompiled-$text_file" $exe_file;