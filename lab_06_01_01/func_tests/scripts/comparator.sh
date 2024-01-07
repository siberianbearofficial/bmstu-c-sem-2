#!/bin/bash

if [[ $# -eq 3 ]]; then
  if [[ $3 != "-v" ]]; then
    echo "Usage: $0 file1 file2 [-v]" >&2a
    exit 1
  fi
  verbose=1
elif [[ $# -eq 2 ]]; then
  verbose=0
else
  echo "Usage: $0 file1 file2 [-v]" >&2
  exit 1
fi

if [ ! -f "$1" ]; then
  if [[ $verbose -eq 1 ]]; then
    echo "File $1 does not exist." >&2
  fi
  exit 1
fi

if [ ! -f "$2" ]; then
  if [[ $verbose -eq 1 ]]; then
    echo "File $2 does not exist." >&2
  fi
  exit 1
fi

declare -a lines_1

while IFS= read -r line; do
  lines_1+=("$line")
done <"$1"

declare -a lines_2

while IFS= read -r line; do
  lines_2+=("$line")
done <"$2"

if [[ "${lines_1[*]}" == "${lines_2[*]}" ]]; then
  if [[ $verbose -eq 1 ]]; then
    echo "Equal"
  fi
  exit 0
else
  if [[ $verbose -eq 1 ]]; then
    echo "Not equal"
  fi
  exit 1
fi
