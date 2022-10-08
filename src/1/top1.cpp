#include <iostream>
#include <string>
#include <verilated.h>

#include "Vtop1.h"

using namespace std;

void logtbl(std::string mod_name, Vtop1 *top, int inc, CData *inv, char *inl, int outc, CData *outv, char *outl);

int main(int argc, char **argv, char **env) {
  Verilated::commandArgs(argc, argv);
  auto top1 = make_unique<Vtop1>();

  {
    auto name = "Nand";
    int inc = 2;
    CData *inv[] = {&(top1->a), &(top1->b)};
    char inl[] = {'a', 'b'};
    int outc = 1;
    CData *outv[] = {&(top1->nand_out)};
    char outl[] = {'o'};
    logtbl(name, top1.get(), inc, *inv, inl, outc, *outv, outl);
  }

  {
    auto name = "Not";
    int inc = 1;
    CData *inv[] = {&(top1->in)};
    char inl[] = {'i'};
    int outc = 1;
    CData *outv[] = {&(top1->not_out)};
    char outl[] = {'o'};
    logtbl(name, top1.get(), inc, *inv, inl, outc, *outv, outl);
  }

  {
    auto name = "And";
    int inc = 2;
    CData *inv[] = {&(top1->a), &(top1->b)};
    char inl[] = {'a', 'b'};
    int outc = 1;
    CData *outv[] = {&(top1->and_out)};
    char outl[] = {'o'};
    logtbl(name, top1.get(), inc, *inv, inl, outc, *outv, outl);
  }

  {
    auto name = "Or";
    int inc = 2;
    CData *inv[] = {&(top1->a), &(top1->b)};
    char inl[] = {'a', 'b'};
    int outc = 1;
    CData *outv[] = {&(top1->or_out)};
    char outl[] = {'o'};
    logtbl(name, top1.get(), inc, *inv, inl, outc, *outv, outl);
  }

  {
    auto name = "Xor";
    int inc = 2;
    CData *inv[] = {&(top1->a), &(top1->b)};
    char inl[] = {'a', 'b'};
    int outc = 1;
    CData *outv[] = {&(top1->xor_out)};
    char outl[] = {'o'};
    logtbl(name, top1.get(), inc, *inv, inl, outc, *outv, outl);
  }

  // Mux
  cout << "Mux Test" << endl;
  cout << " s  a  b || o " << endl;
  cout << "---------**---" << endl;
  for (int i = 0; i < 8; i++) {
    int sel = (i & 1 << 2) >> 2;
    int a = (i & 1 << 1) >> 1;
    int b = (i & 1 << 0) >> 0;
    top1->sel = sel;
    top1->a = a;
    top1->b = b;
    top1->eval();
    cout << " " << to_string(!!sel) << " ";
    cout << " " << to_string(!!a) << " ";
    cout << " " << to_string(!!b) << " ";
    cout << "|| " << to_string(top1->mux_out) << endl;
  }
  cout << endl;

  {
    auto name = "Mux";
    int inc = 3;
    CData *inv[] = {&(top1->sel), &(top1->a), &(top1->b)};
    char inl[] = {'s', 'a', 'b'};
    int outc = 1;
    CData *outv[] = {&(top1->mux_out)};
    char outl[] = {'o'};
    logtbl(name, top1.get(), inc, *inv, inl, outc, *outv, outl);
  }

  // DMux
  cout << "DMux Test" << endl;
  cout << " s  i || a  b " << endl;
  cout << "------**------" << endl;
  for (int i = 0; i < 4; i++) {
    int sel = (i & 1 << 1) >> 1;
    int in = (i & 1 << 0) >> 0;
    top1->sel = sel;
    top1->in = in;
    top1->eval();
    cout << " " << to_string(!!sel) << " ";
    cout << " " << to_string(!!in) << " ";
    cout << "|| " << to_string(top1->dmux_out_a) << " ";
    cout << " " << to_string(top1->dmux_out_b) << endl;
  }
  cout << endl;

  {
    auto name = "DMux";
    int inc = 2;
    CData *inv[] = {&(top1->sel), &(top1->in)};
    char inl[] = {'s', 'i'};
    int outc = 2;
    CData *outv[] = {&(top1->dmux_out_a), &(top1->dmux_out_b)};
    char outl[] = {'a', 'b'};
    logtbl(name, top1.get(), inc, *inv, inl, outc, *outv, outl);
  }

  top1->final();
  return 0;
}

void error(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  exit(1);
}

void logtbl(std::string mod_name, Vtop1 *top, int inc, CData *inv, char *inl, int outc, CData *outv, char *outl) {
  cout << mod_name << " Test" << endl;

  for (int i = 0; i < inc; i++)
    cout << " " << inl[i] << " ";
  cout << "||";
  for (int i = 0; i < outc; i++)
    cout << " " << outl[i] << " ";
  cout << endl;

  for (int i = 0; i < inc; i++)
    cout << "---";
  cout << "**";
  for (int i = 0; i < outc; i++)
    cout << "---";
  cout << endl;

  for (int i = 0; i < (1 << inc); i++) {
    for (int j = inc - 1; j >= 0; j--) {
      inv[inc - j - 1] = (i & 1 << j) >> j;
      cout << " TEMP<" << inl[inc - j - 1] << ">";
      cout << " " << to_string((i & 1 << j) >> j) << " ";
    }
    top->eval();
    cout << "||";
    for (int j = 0; j < outc; j++) {
      cout << " TEMP<" << outl[j] << ">";
      cout << " " << to_string(outv[j]) << " ";
    }
    cout << endl;
  }
  cout << endl;
}
