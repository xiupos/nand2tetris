#include <iostream>
#include <string>
#include <verilated.h>

#include "VNot.h"

using namespace std;

void error(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  exit(1);
}

int main(int argc, char **argv, char **env) {
  Verilated::commandArgs(argc, argv);
  VNot *top = new VNot;

  if (argc != 2) {
    error("コマンドライン引数の数が無効です");
  }

  bool in_i = stoi(argv[1]);

  while (!Verilated::gotFinish()) {
    top->in = in_i;
    top->eval();
    cout << to_string(top->out);
    break;
  }

  top->final();
  delete top;
  return 0;
}
