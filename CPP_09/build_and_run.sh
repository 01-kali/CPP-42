#!/bin/bash

RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

STR="Select an exercise: "

while true; do
  EXERCISE_DIRS=($(find CPP_09 -name "ex*" | sort))
  OPTIONS=("${EXERCISE_DIRS[@]}" "Quit")
  for i in "${!OPTIONS[@]}"; do
    printf "%d) %s\n" $((i)) "${OPTIONS[$i]}"
  done
  read -p "$STR" choice
  clear

  if [[ "$choice" =~ ^[0-9]+$ ]]; then
    if [ "$choice" -ge "${#OPTIONS[@]}" ]; then
        echo -e "${RED}Invalid option index.${NC}"
        continue
    fi

    opt="${OPTIONS[$((choice))]}"
    
    if [[ "$opt" == "Quit" ]]; then
      exit 0
    elif [[ -d "$opt" ]]; then
      echo -e "${BLUE}Building $(basename "$opt")...${NC}"

      make re --no-print-directory -C "$opt"
      if [[ $? -ne 0 ]]; then
        continue
      fi

      exe=$(find "$opt" -maxdepth 1 -type f -executable ! -name "*.cpp" ! -name "*.hpp" ! -name "Makefile" ! -name "data.csv" ! -name "input.txt")
      if [[ -z "$exe" ]]; then
        echo -e "${RED}No executable found in $opt${NC}"
      else
        echo -e "Enter arguments for $(basename "$exe") (separated by space)."
        read -e -p "> " user_args
        echo -e "${BLUE}Running...${NC}"
        eval "$exe $user_args"
      fi
      sleep 1
      make fclean --no-print-directory -C "$opt"
    else
      echo -e "${RED}Invalid option.${NC}"
    fi
  else
     echo -e "${RED}Please enter a number.${NC}"
  fi
done
