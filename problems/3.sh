#!/bin/bash
# Find recursively in a directory, all the files with the extension ".log" and sort their lines (replace the original file with the sorted content).	

find . -name "*.log" type f | while read file
do
	sort $file -o $file
done 
