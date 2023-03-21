#include "./s21_format.h"

s21_format_p *InitPrintFormat() {
  s21_format_p *result = malloc(sizeof(s21_format_p));
  SetDefaultPrintFormat(result);
  return result;
}

void SetDefaultPrintFormat(s21_format_p *format) {
  format->spec = non_spec;
  format->minus = false;
  format->plus = false;
  format->space = false;
  format->zero = false;
  format->sharp = false;
  format->prec = 0;
  format->prec_set = false;
  format->width = 0;
  format->len = default_l;
}

void FreePrintFormat(s21_format_p *format) { free(format); }
