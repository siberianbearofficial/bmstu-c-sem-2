#!/bin/bash
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

memcheck="$1"
verbose="$2"

function two_digit_number() {
  if [[ $1 -lt 10 ]]; then
    echo "0$1"
  else
    echo "$1"
  fi
}

function run_pos() {
  "${SCRIPT_DIR}/pos_case.sh" "$pos_in_name" "$pos_out_name" "$pos_args_name" "$memcheck" "$verbose"
  return $?
}

function run_neg() {
  "${SCRIPT_DIR}/neg_case.sh" "$neg_in_name" "$neg_out_name" "$neg_args_name" "$memcheck" "$verbose"
  return $?
}

pos_start="${SCRIPT_DIR}/../data/pos_"
in_end="_in.txt"
out_end="_out.txt"
args_end="_args.txt"
neg_start="${SCRIPT_DIR}/../data/neg_"

echo "POSITIVES:"
i=1
while true; do
  test_number=$(two_digit_number $i)
  pos_in_name="${pos_start}${test_number}${in_end}"
  pos_out_name="${pos_start}${test_number}${out_end}"
  pos_args_name="${pos_start}${test_number}${args_end}"

  if [[ ! -e $pos_in_name ]]; then
    break
  fi

  run_pos
  return_code=$?
  if [[ $return_code -eq 0 ]]; then
    echo -e "$test_number - \033[1;92mPASSED\033[0m"
  else
    echo -e "$test_number - \033[1;91mFAILED\033[0m (code: $return_code)"
  fi

  i=$((i + 1))
done

echo "NEGATIVES:"
i=1
while true; do
  test_number=$(two_digit_number $i)
  neg_in_name="${neg_start}${test_number}${in_end}"
  neg_out_name="${neg_start}${test_number}${out_end}"
  neg_args_name="${neg_start}${test_number}${args_end}"

  if [[ ! -e $neg_in_name ]]; then
    break
  fi

  run_neg
  return_code=$?
  if [[ $return_code -eq 0 ]]; then
    echo -e "$test_number - \033[1;92mPASSED\033[0m"
  elif [[ $return_code -eq 1 ]]; then
    echo -e "$test_number - \033[1;91mFAILED\033[0m (code: 0)"
  elif [[ $return_code -eq 2 ]]; then
    echo -e "$test_number - \033[1;91mFAILED\033[0m (stdout)"
  elif [[ $return_code -eq 3 ]]; then
    echo -e "$test_number - \033[1;91mFAILED\033[0m (fileout)"
  fi

  i=$((i + 1))
done
