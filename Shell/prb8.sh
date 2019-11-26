#!/bin/bash


systems=`df | awk 'NR>1{print $1,$2,$5}' | sed /"9.%"/d | sed /"\<[0-9][0-9][0-9][0-9][0-9][0-9]\>"/d`

string=""
c=0
for s in $systems;do
	string+=$s
	string+=" "
	((c++))
	if (( $c % 3 ==0 )); then 
		string+="\n"
	fi 	
done

echo -e $string
