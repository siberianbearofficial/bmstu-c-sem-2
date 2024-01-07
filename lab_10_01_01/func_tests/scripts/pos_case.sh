#!/bin/bash
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

if [ -f "$3" ]; then
  args=$(cat "$3")
else
  args=""
fi

in_stream="$1"
out_stream="$2"
out_name=$("basename" "$out_stream")
file_out_stream="${SCRIPT_DIR}/../data_files/${out_name%.*}1.txt"
tmp_stream="${SCRIPT_DIR}/../../tmp.txt"
file_tmp_stream="${SCRIPT_DIR}/../../out/temp_1.txt"
memcheck="$4"
verbose="$5"

function run() {
  dir=$(pwd)
  cd "${SCRIPT_DIR}/../../" || return 1
  if [ "$memcheck" == "--memcheck" ]; then
      # shellcheck disable=SC2086
      eval valgrind -q --leak-check=yes --track-origins=yes "./app.exe" $args <"$in_stream" >"$tmp_stream"
      exit_code=$?
    else
      eval "./app.exe" $args <"$in_stream" >"$tmp_stream"
      exit_code=$?
    fi
  cd "$dir" || return 1
  return $exit_code
}

run
return_code=$?

if [ $return_code -eq 0 ] && [ -f "$out_stream" ]; then
  "${SCRIPT_DIR}/comparator.sh" "$tmp_stream" "$out_stream" "$verbose"
  return_code=$?
fi

if [ $return_code -eq 0 ] && [ -f "$file_out_stream" ]; then
  "${SCRIPT_DIR}/comparator.sh" "$file_tmp_stream" "$file_out_stream" "$verbose"
  return_code=$?
fi

exit $return_code

