#!/bin/sh
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    scypt.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 01:04:16 by ilyanar           #+#    #+#              #
#    Updated: 2001/04/07 01:04:16 by ilyanar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

numbers=""

# beggening

read -p "Do you want random numbers? <y/n> : " random
echo "------------------------"
read -p "which checker do you want to use? < 1 = original, 2 = bonus > : " check
echo "------------------------"

#fonction to generate the numbers

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

# grep the random numbers

if [ "$random" == "n" ]
then
	read -p "ARG = " numbers
	LINE=$(time ./push_swap $numbers | wc -l)
elif [ "$random" == "y" ]
then
	read -p "How many numbers you want : " count
	echo "\n-----------TIME-------------"
	generate
	LINE=$(time ./push_swap $numbers | wc -l)
else
	echo "Error bad format."
	exit
fi
# the checker

if [ "$check" == "2" ]
then
	CHECK=$(./push_swap $numbers | ./checker $numbers)
else
	CHECK=$(./push_swap $numbers | ./other/checker_Mac $numbers)
fi
# grep the time
echo "\n----------OPERATIONS--------------"
echo ""$LINE" instructions"
echo "------------------------\n"

# check for checker

if [ "$CHECK" == "OK" ]
then
	echo "Checker say : $CHECK, Good job ;)"
elif [ "$CHECK" == "KO" ]
then
	echo "Checker say : $CHECK, Retry it :("
else
	echo "$CHECK bad format, Retry it :("
fi

echo ""

# print the stacks
echo "------------------------"
read -p "Do you want print the stack A and B ? <y/n> : " prints
ARCH=$(sysctl -a | grep Intel)
if [ "$prints" == "y" ]
then
	if [ ! "$ARCH" ]
	then
		./push_swap $numbers | ./other/print_stack $numbers
	else
		./push_swap $numbers | ./other/print_mac_intel $numbers
	fi
fi

# print the instructions

echo "------------------------"
read -p "Want to see the instruction ? <y/n> : " intr

if [ "$intr" == "y" ]
then
	./push_swap $numbers
fi

#end
#
echo "------------------------"
echo "\nEND"
exit
