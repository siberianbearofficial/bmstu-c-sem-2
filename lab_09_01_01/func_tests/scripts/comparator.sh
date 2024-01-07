#!/bin/bash

verbose="$3"

if [ $# -lt 2 ] || [ $# -gt 3 ]; then
  echo "Usage: $0 file1 file2 [-v]" >&2
  exit 2
fi

if [ ! -f "$1" ]; then
  exit 21
fi

if [ ! -f "$2" ]; then
  exit 22
fi

if [ "$verbose" == "-v" ]; then
  python3 -c "from sys import exit; exit(open('$1', encoding='utf-8').read().strip().split() != open('$2', encoding='utf-8').read().strip().split());"
  exit $?
else
  python3 -c "from sys import exit; exit(open('$1', encoding='utf-8').read().strip().split() != open('$2', encoding='utf-8').read().strip().split());"
  exit $?
fi
