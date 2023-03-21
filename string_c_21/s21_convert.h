#ifndef SRC_S21_CONVERT_H_
#define SRC_S21_CONVERT_H_

#include <math.h>
#include <stdint.h>

#include "./s21_format.h"
#include "./s21_string.h"

int ConvertStrToInt(const char *str);
int GetSign(const char *str);
int AddSign(bool overflow, int res, int sign);

void ConvertNumToString(int64_t num, char *str, int base);
bool CheckNegative(int64_t num);
void WriteTemp(char *temp, char *str, bool isNegative, int index);

void ConvertUIntToString(uint64_t num, char *str, int base);

void ConvertDoubleToString(long double num, char *str, int prec, bool sharp);
void AllocFract(long double *tempFractPart, char *temp_fract, int prec);
void FillTempFractPart(long long fractPart, char *temp, char *temp_fract,
                       int prec, int *index);
void FillTempIntPart(long long intPart, char *temp, int *index);
bool CheckNegativeLD(long double num);

bool IsDigit(char ch);

#endif  //  SRC_S21_CONVERT_H_
