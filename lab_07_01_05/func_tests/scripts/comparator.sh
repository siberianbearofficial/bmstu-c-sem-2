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
  cmp "$1" "$2"
  exit $?
else
  cmp -s "$1" "$2"
  exit $?
fi
