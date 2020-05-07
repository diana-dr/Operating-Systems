#!/bin/bash
# Find recursively in a directory, all the files that have write permissions for everyone. Display their names, and then remove the write permission for everybody. You will need to use chmod's symbolic permissions mode, instead of the octal mode we have used in class. The the chmod manual for details.	

for x in `find type f $l -perm / 0=w`
do
	chmod a -w $x
done
