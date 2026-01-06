#!/bin/bash

RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

STR="Select an exercise: "

while true; do
  EXERCISE_DIRS=($(find CPP_02 -name "ex*" | sort))
  OPTIONS=("${EXERCISE_DIRS[@]}" "Quit")
  for i in "${!OPTIONS[@]}"; do
    printf "%d) %s\n" $((i)) "${OPTIONS[$i]}"
  done
  read -p "$STR" choice
  clear

  if [[ "$choice" =~ ^[0-9]+$ ]]; then
    opt="${OPTIONS[$((choice))]}"
    if [[ "$opt" == "Quit" ]]; then
      exit 0
    elif [[ -d "$opt" ]]; then
      echo -e "${BLUE}Building $(basename "$opt")...${NC}"

      make re --no-print-directory -C "$opt"
      if [[ $? -ne 0 ]]; then
        break
      fi

      exe=$(find "$opt" -maxdepth 1 -type f -executable ! -name "*.cpp" ! -name "*.hpp" ! -name "Makefile")
      if [[ -z "$exe" ]]; then
        echo -e "${RED}No executable found in $opt${NC}"
      else
        echo -e "${BLUE}Running $(basename "$exe")...${NC}"

        sleep 1
        "$exe"
      fi
      sleep 1
      make fclean --no-print-directory -C "$opt"
    else
      echo -e "${RED}Invalid option.${NC}"
    fi
  fi
done
