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
spinner="⠋⠙⠹⠼⠴⠦⠧⠏"
delay=0.1
iterations=30

echo "\033[94m╔════════════════════════════════════════════════════════════════════════╗\033[0m"
echo "\033[94m║\033[0m               \033[95mWelcome to \033[0m\033[32;4mpush_swap\033[0m \033[95mtester, by ilyanar!\033[0m  \033[94m	       	 ║\033[0m"
echo "\033[94m╚════════════════════════════════════════════════════════════════════════╝\033[0m\n"

sleep 0.2

printf "\033[3;1;95mDo you want random numbers?\033[0m \033[32m<y/n>\033[0m \033[95m: \033[0m"
read random
printf "\033[3;1;95mwhich checker do you want to use?\033[0m \033[32m<1=original/2=bonus>\033[0m \033[95;1m: \033[0m"
read check

#fonction to generate the numbers

generate_unique_random()
{
    local num
    while true; do
        num=$((1 + RANDOM % 1000000))
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
# printf "\r\033[96m${spinner:$i:1}\033[0m \033[33msorting numbers...\033[0m"

if [ "$random" == "n" ]
then
	echo "---------ARGUMENTS-------------"
	read -p "ARG = " numbers
	echo "-----------TIME-------------"
	LINE=$(time ./push_swap $numbers | wc -l)
elif [ "$random" == "y" ]
then
	printf "\033[3;1;95mHow many numbers you want : \033[0m"
	read count
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
	echo "Checker say : [\033[32mOK\033[0m], Good job ;)"
elif [ "$CHECK" == "KO" ]
then
	echo "Checker say : [\033[31mKO\033[0m], Retry it :("
elif [ "$CHECK" == "Error" ]
then
	echo "Checker say : \033[31;4mError\033[0m"
else
	echo "$CHECK bad format"
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
