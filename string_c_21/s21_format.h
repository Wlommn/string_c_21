#ifndef SRC_S21_FORMAT_H_
#define SRC_S21_FORMAT_H_

#include <stdlib.h>

#include "./s21_string.h"

typedef enum SPEC {
  non_spec,
  c,
  d,
  i,
  e,
  E,
  f,
  g,
  G,
  u,
  s,
  o,
  x,
  X,
  p,
  n,
  perc
} spec;

typedef enum LENGHT { default_l, short_l, long_l, double_l } len;

typedef struct s21_format_p {
  spec spec;
  bool minus;
  bool plus;
  bool space;
  bool zero;
  bool sharp;
  int prec;
  bool prec_set;
  int width;
  len len;
} s21_format_p;

s21_format_p *InitPrintFormat();
void SetDefaultPrintFormat(s21_format_p *format);
void FreePrintFormat(s21_format_p *format);

#endif  //  SRC_S21_FORMAT_H_
