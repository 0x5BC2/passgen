# passgen

A password generator made in C with clipboard integration with intended use with Linux keyboard shortcuts

## Features

- Cryptographically secure
- Automatically copies to clipboard
- Intended use with keybindings
- Customizable length
- Includes lowercase, uppercase, numbers and special characters

## Requirements

- `copyq` (can be any other clipboard manager as far you edit the commands in the source)
- GCC (or any C compiler)

## Tested on

- Linux Mint 22.3 (Cinnamon) (x86_64) | Linux Kernel 6.17.0 | copyq 13.0.0 | libnotify 0.8.3

## Installation

### From source

```bash
# Clone the repository
git clone https://github.com/0x5BC2/passgen.git
cd passgen

# Compile
gcc -o passgen passgen.c
# Or with warnings, optimized to level 2 and stripped
gcc -Wall -Wextra -O2 -s -o passgen passgen.c

```

### From releases

```bash
# Download the latest release
wget https://github.com/0x5BC2/passgen/releases/latest/download/passgen

# Make it executable
chmod +x passgen
```

## Post Installation

```bash
# Run directly
./passgen -l <length>

# Install system-wide
sudo cp passgen /usr/local/bin/
```

## Should you use it?

Probably not, but it's out there if you want to
