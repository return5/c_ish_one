#!/bin/bash
#compile script for c-is one
#compiles game and creates executable names 'cish_one'

# src_files are all the .c files to include
# -I tells gcc to look in headers folder for headers
# -lncurses is for ncurses
gcc @src_files -Iheaders -ocish_one -lncurses -Wall -Wextra