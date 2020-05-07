#!/bin/bash
# Find recursively in a directory all ".c" files having more than 500 lines. Stop after finding 10 such files.	


find -name '*.c' | while read dir
do
	a = `wc $dir`
	if [ $a[0] >= 500 ]
	then
		echo $dir is a file that has more than 500 lines;
	fi
done
