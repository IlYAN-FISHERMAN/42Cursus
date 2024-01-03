#!/bin/bash

numbers=""

read -p "Do you want random numbers? <y/n> : " random
read -p "which checker do you want to use? < 1 = original, 2 = bonus > : " check

generate_unique_random()
{
    local num
    while true; do
        num=$((1 + RANDOM % 1000))
		if [[ ! " ${numbers[*]} " =~ " $num " ]]; then
            numbers+="$num "
            break
        fi
    done
}

generate()
{
	for ((i=0; i<count; i++)); do
    	generate_unique_random
	done
}

if [ "$random" == "n" ]
then
	read -p "ARG = " numbers
	LINE=$(./push_swap $numbers | wc -l)
elif [ "$random" == "y" ]
then
	read -p "How many numbers you want : " count
	generate
	LINE=$(./push_swap $numbers | wc -l)
else
	echo "Error bad format."
	exit
fi

if [ "$check" == "1" ]
then
	CHECK=$(./push_swap $numbers | ./other/checker_Mac $numbers)
elif [ "$check" == "2" ]
then
	CHECK=$(./push_swap $numbers | ./bonus/checker $numbers)
fi

echo "\nNumber of line : "$LINE

if [ "$CHECK" == "OK" ]
then
	echo "\nChecker say : $CHECK, Good job ;)"
elif [ "$CHECK" == "KO" ]
then
	echo "\nChecker say : $CHECK, Retry it :("
else
	echo "$CHECK bad format, Retry it :("
fi
echo "\n"

read -p "Do you want print the stack A and B ? <y/n> : " prints

if [ "$prints" == "y" ]
then
	./push_swap $numbers | ./other/print_stack $numbers
fi

echo "\nEND"
exit
