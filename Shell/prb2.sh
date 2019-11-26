#!/bin/bash

count=0
D=$1

for d in `find $D`; do 
	if [ -d $d ];then 
		continue
	fi
	c=$(wc -l $d)
	b=0
	for a in $c;do
		(( b=$a ))
		break
	done	
	if [ $b -gt 10 ];then
		(( count++ ))
	fi
	if [ $count -eq 10 ];then 
		break;
	fi 
done 	

echo $count
