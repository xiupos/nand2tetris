#include <iostream>
#include <string>
#include <verilated.h>

#include "VNand.h"

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
  VNand *top = new VNand;

  if (argc != 3) {
    error("コマンドライン引数の数が無効です");
  }

  bool a_i = stoi(argv[1]);
  bool b_i = stoi(argv[2]);

  while (!Verilated::gotFinish()) {
    top->a = a_i;
    top->b = b_i;
    top->eval();
    cout << to_string(top->out);
    break;
  }

  top->final();
  delete top;
  return 0;
}
