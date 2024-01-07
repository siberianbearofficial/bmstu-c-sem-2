#!/bin/bash
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

if [ -f "$3" ]; then
  args=$("cat" "$3")
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
  cd "${SCRIPT_DIR}/../../" || return 4
  if [ "$memcheck" == "--memcheck" ]; then
    # shellcheck disable=SC2086
    eval valgrind -q --leak-check=yes --track-origins=yes "./app.exe" $args <"$in_stream" >"$tmp_stream"
    exit_code=$?
  else
    # shellcheck disable=SC2086
    eval "./app.exe" $args <"$in_stream" >"$tmp_stream"
    exit_code=$?
  fi
  cd "$dir" || return 4
  return $exit_code
}

run
return_code=$?

if [ "$verbose" == "-v2" ]; then
  echo "Code: $return_code"
fi

if [ $return_code -eq 0 ]; then
  return_code=1
else
  return_code=0
fi

if [ $return_code -eq 0 ] && [ -f "$out_stream" ] && ! "${SCRIPT_DIR}/comparator.sh" "$tmp_stream" "$out_stream" "$verbose"; then
  return_code=2
fi

if [ $return_code -eq 0 ] && [ -f "$file_out_stream" ] && ! "${SCRIPT_DIR}/comparator.sh" "$file_tmp_stream" "$file_out_stream" "$verbose"; then
  return_code=3
fi

exit $return_code

