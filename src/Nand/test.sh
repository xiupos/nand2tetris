#!/bin/bash

assert() {
  expected="$1"
  input_a="$2"
  input_b="$3"

  actual=$(./build/VNand $2 $3)

  if [ "$actual" = "$expected" ]; then
    echo "$input_a, $input_b => $actual"
  else
    echo "$input_a, $input_b => $expected expected, but got $actual"
    exit 1
  fi
}

assert 1 0 0
assert 1 0 1
assert 1 1 0
assert 0 1 1

echo OK
