#!/bin/bash

assert() {
  expected="$1"
  input="$2"

  actual=$(./build/VNot $input)

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

assert 1 0
assert 0 1

echo OK
