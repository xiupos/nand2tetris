#include <iostream>
#include <string>
#include <verilated.h>

#include "Vtop1.h"

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
  Vtop1 *top1 = new Vtop1;

  // Nand
  cout << "Nand Test" << endl;
  cout << " a  b || o " << endl;
  cout << "------**---" << endl;
  for (int i = 0; i < 4; i++) {
    int a = (i & 1 << 1) >> 1;
    int b = (i & 1 << 0) >> 0;
    top1->a = a;
    top1->b = b;
    top1->eval();
    cout << " " << to_string(!!a) << " ";
    cout << " " << to_string(!!b) << " ";
    cout << "|| " << to_string(top1->nand_out) << endl;
  }
  cout << endl;

  // Not
  cout << "Not Test" << endl;
  cout << " i || o " << endl;
  cout << "---**---" << endl;
  for (int i = 0; i < 2; i++) {
    int a = (i & 1 << 0) >> 0;
    top1->a = a;
    top1->eval();
    cout << " " << to_string(!!a) << " ";
    cout << "|| " << to_string(top1->not_out) << endl;
  }
  cout << endl;

  // And
  cout << "And Test" << endl;
  cout << " a  b || o " << endl;
  cout << "------**---" << endl;
  for (int i = 0; i < 4; i++) {
    int a = (i & 1 << 1) >> 1;
    int b = (i & 1 << 0) >> 0;
    top1->a = a;
    top1->b = b;
    top1->eval();
    cout << " " << to_string(!!a) << " ";
    cout << " " << to_string(!!b) << " ";
    cout << "|| " << to_string(top1->and_out) << endl;
  }
  cout << endl;

  // Or
  cout << "Or Test" << endl;
  cout << " a  b || o " << endl;
  cout << "------**---" << endl;
  for (int i = 0; i < 4; i++) {
    int a = (i & 1 << 1) >> 1;
    int b = (i & 1 << 0) >> 0;
    top1->a = a;
    top1->b = b;
    top1->eval();
    cout << " " << to_string(!!a) << " ";
    cout << " " << to_string(!!b) << " ";
    cout << "|| " << to_string(top1->or_out) << endl;
  }

  top1->final();
  delete top1;
  return 0;
}
