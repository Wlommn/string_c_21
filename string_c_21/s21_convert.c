#include "./s21_convert.h"

#define NUMS "0123456789abcdef"

int ConvertStrToInt(const char *str) {
  int res = 0, sign = 1;
  bool overflow = false;
  while (*str == ' ') {
    str++;
  }
  sign = GetSign(str);
  while (!overflow && *str && IsDigit(*str)) {
    res = res * 10 + (*str - '0');
    if (res < 0) {
      overflow = true;
    } else {
      str++;
    }
  }
  res = AddSign(overflow, res, sign);
  return res;
}

int GetSign(const char *str) {
  int sign = 1;
  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    str++;
  }
  return sign;
}

int AddSign(bool overflow, int res, int sign) {
  if (overflow) {
    if (sign > 0) {
      res = INT32_MAX;
    } else {
      res = INT32_MIN;
    }
  } else {
    res *= sign;
  }
  return res;
}

void ConvertNumToString(int64_t num, char *str, int base) {
  char temp[BUFF_SIZE];
  s21_memset(temp, '\0', BUFF_SIZE);
  int index = BUFF_SIZE - 2;
  bool isNegatie = CheckNegative(num);
  if (isNegatie) {
    num *= -1;
  }
  if (num == 0) {
    temp[index] = '0';
  } else {
    while (num > 0) {
      index--;
      temp[index] = NUMS[num % base];
      num /= base;
    }
  }
  WriteTemp(temp, str, isNegatie, index);
}

bool CheckNegative(int64_t num) {
  bool result = false;
  if (num < 0) {
    result = true;
  }
  return result;
}

void WriteTemp(char *temp, char *str, bool isNegative, int index) {
  int i = 0;
  if (isNegative) {
    str[i] = '-';
    i++;
  }
  for (; temp[index]; index++, i++) {
    str[i] = temp[index];
  }
}

void ConvertUIntToString(uint64_t num, char *str, int base) {
  char temp[BUFF_SIZE];
  s21_memset(temp, '\0', BUFF_SIZE);
  int index = BUFF_SIZE - 1;
  if (num == 0) {
    index--;
    temp[index] = '0';
  } else {
    while (num && index) {
      index--;
      temp[index] = NUMS[num % base];
      num /= base;
    }
  }
  for (int i = 0; temp[index]; index++, i++) {
    str[i] = temp[index];
  }
}

void ConvertDoubleToString(long double num, char *str, int prec, bool sharp) {
  char temp[BUFF_SIZE] = {'\0'}, temp_fract[BUFF_SIZE] = {'\0'};
  int index = BUFF_SIZE - 2;
  bool isNegative = CheckNegativeLD(num);
  if (isNegative) {
    num *= -1;
  }
  long double tempIntPart = 0, tempFractPart = modfl(num, &tempIntPart);
  long long intPart = 0, fractPart = 0;
  if (prec == 0) {
    tempIntPart = roundl(num);
    tempFractPart = 0;
  }
  AllocFract(&tempFractPart, temp_fract, prec);
  fractPart = roundl(tempFractPart);
  intPart = tempIntPart;
  FillTempFractPart(fractPart, temp, temp_fract, prec, &index);
  if ((prec > 0) || (int)tempFractPart || s21_strlen(temp_fract) || sharp) {
    temp[index--] = '.';
  }
  FillTempIntPart(intPart, temp, &index);
  for (int i = 0; temp[index + 1]; index++, i++) {
    if (isNegative && i == 0) {
      str[i] = '-';
      i++;
    }
    str[i] = temp[index + 1];
  }
}

void AllocFract(long double *tempFractPart, char *temp_fract, int prec) {
  for (int i = 0; i < prec; i++) {
    *tempFractPart = *tempFractPart * 10;
    temp_fract[i] = (int)*tempFractPart + '0';
  }
}

void FillTempFractPart(long long fractPart, char *temp, char *temp_fract,
                       int prec, int *index) {
  if (!fractPart) {
    for (int i = 0; i < prec; *index = *index - 1, i++) {
      temp[*index] = '0';
    }
  } else {
    for (int i = s21_strlen(temp_fract); fractPart || i > 0;
         fractPart /= 10, *index = *index - 1, i--)
      temp[*index] = (int)(fractPart % 10 + 0.05) + '0';
  }
}

void FillTempIntPart(long long intPart, char *temp, int *index) {
  if (!intPart) {
    temp[*index] = '0';
    *index = *index - 1;
  } else {
    for (; intPart; intPart /= 10, *index = *index - 1) {
      temp[*index] = (int)(intPart % 10) + '0';
    }
  }
}

bool CheckNegativeLD(long double num) {
  bool result = false;
  if (num < 0.0) {
    result = true;
  }
  return result;
}

bool IsDigit(char ch) {
  bool result = false;
  if (s21_strchr("0123456789", ch) != S21_NULL) {
    result = true;
  }
  return result;
}
