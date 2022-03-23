#! /bin/bash

clear;
g++ cpp/main.cpp -o bin/built; 
if [[ $? -eq 0 ]]; then 
	while getopts "f" flag;
	do
		case "${flag}" in
			f) ./bin/built "-f"
				;;
		esac
	done
		if [[ $OPTIND == 1 ]]; then
			#echo "Here"
			./bin/built
		fi	
fi
