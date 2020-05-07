#!/bin/bash
# Display a report showing the full name of all the users currently connected, and the number of processes belonging to each of them.	

for j in `cat who.fake | awk -F: '{print $1}'`
do
	count=0
	for i in `cat ps.fake | awk -F: '{print $1}'`
	do
		if [ $i = $j ]
		then
			count=`expr 1 + $count`
		fi
	done
	echo $j $count
done		
