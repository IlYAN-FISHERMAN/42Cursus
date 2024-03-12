export PATH="/Users/ilkayyanar/Library/Python/3.9/bin:$PATH"

#----------------------------------------
alias ggfdf="ggc *.c libft/*.c minilibx_macos/libmlx.a -framework OpenGL -framework AppKit -o fdf"
alias ls="eza"
alias cow="cowsay -f ~/.cowsay.txt"
alias tree="eza --tree"
alias ll="eza -la"
alias cc="clear"
alias ggc="gcc -Wall -Werror -Wextra"
alias ggcf="gcc -Wall -Werror -Wextra -g3 -fsanitize=address"
alias cat="bat"
alias francinette=/Users/ilkayyanar/francinette/tester.sh
alias paco=/Users/ilkayyanar/francinette/tester.sh
alias push="ggc *.c libft/*.c -o push_swap"
alias pushf="ggcf *.c libft/*.c -o push_swap"
alias pushl="leaks --atExit -- ./push_swap"
alias macrui="ssh mac.ruinfo.ch -p 6969"
alias pipex="ggc *.c libft/*.c -o pipex"
alias ok_b="cliclick m:500,500 && cliclick c:921,443 && cliclick m:500,500"
alias dodo="sudo shutdown -h now"
alias dodo1h="sudo  shutdown -h +60 \"i'm gonna sleep\""
alias cdd="cd ~/travail/repo_github/42Cursus/"
alias make="make -j$(sysctl -n hw.ncpu)"
#----------------------------------------

eval "$(starship init zsh)"
export MANPAGER="sh -c 'col -bx | bat -l man -p'"
export LIBRARY_PATH=/opt/homebrew/lib
fastfetch

#---------------fonctions-------------------------

function vplay
{
	local display="$1"
	if [ "$display" = "1" ]
	then
		cliclick c:500,500 && sleep 0.3 && cliclick c:500,500
	elif [ "$display" = "2" ]
	then
		cliclick m:500,500 && cliclick c:-1850,650 && sleep 0.3 && cliclick c:-1850,650 && cliclick m:500,500
	else
		printf "\033[95mError\033[0m"
	fi
}

function vol+
{
	local vole="$1"
	osascript -e "set volume output volume (output volume of (get volume settings) + \"$vole\")"
}

function vol-
{
	local vole="$1"
	osascript -e "set volume output volume (output volume of (get volume settings) - \"$vole\")"
}

function vnext
{
	local next="$1"
	if [ "$next" = "1" ]
	then
		cliclick c:500,500 && sleep 0.3 && cliclick c:1315,1054
	elif [ "$next" = "2" ]
	then
		cliclick m:500,500 && cliclick c:-1850,650 && sleep 0.3 cliclick c:-900,1341 && cliclick m:500,500
	else
		printf "\033[95mError\033[0m"
	fi
}

function close
{
	local name="$1"
	osascript -e "tell application \"$name\" to quit"
}

COWPATH="$COWPATH:$HOME/.cowsay/cowfiles/"

# Cow-spoken fortunes every time you open a terminal
function cowsayfortune
{
    NUMOFCOWS=`cowsay -l | tail -n +2 | wc -w`
    WHICHCOW=$((RANDOM%$NUMOFCOWS+1))
    THISCOW=`cowsay -l | tail -n +2 | sed -e 's/\ /\'$'\n/g' | sed $WHICHCOW'q;d'`

    #echo "Selected cow: ${THISCOW}, from ${WHICHCOW}"
    fortune | cowsay -f $THISCOW -W 100
}

cowsayfortune
