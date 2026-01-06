#!/bin/bash

RED='\033[0;31m'
NC='\033[0m'

STR="Select a folder: "

while true; do
  CPP_DIRS=($(find -name "CPP_*" | sed 's|^\./||' | sort))
  OPTIONS=("${CPP_DIRS[@]}" "Quit")
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
      $opt/build_and_run.sh
    else
      echo -e "${RED}Invalid option.${NC}"
    fi
  fi
done
