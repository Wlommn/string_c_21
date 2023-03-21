#include "./s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  int result = 0;
  s21_format_p *format_d = InitPrintFormat();
  char *start = str;
  va_list args;
  va_start(args, format);
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
    } else {
      format = SetConfig(format, format_d, args);
      str = ParseValue(str, format_d, args);
      if (format_d->spec == n) {
        int *n_pointer = va_arg(args, int *);
        *n_pointer = str - start;
      }
      SetDefaultPrintFormat(format_d);
    }
  }
  *str = '\0';
  result = (int)(str - start);
  va_end(args);
  FreePrintFormat(format_d);
  return result;
}

static const char *SetConfig(const char *format_s, s21_format_p *format_d,
                             va_list args) {
  format_s++;
  format_s = SetFlag(format_s, format_d);
  format_s = SetWidth(format_s, format_d, args);
  format_s = SetPrecision(format_s, format_d, args);
  format_s = SetLength(format_s, format_d);
  format_s = SetSpec(format_s, format_d);
  return format_s;
}

static const char *SetFlag(const char *format_s, s21_format_p *format_d) {
  while (IsFlag(*format_s)) {
    switch (*format_s) {
      case '0':
        format_d->zero = true;
        break;
      case '-':
        format_d->minus = true;
        break;
      case '+':
        format_d->plus = true;
        break;
      case ' ':
        format_d->space = true;
        break;
      case '#':
        format_d->sharp = true;
        break;
      default:
        break;
    }
    format_s++;
  }
  return format_s;
}

static const char *SetWidth(const char *format_s, s21_format_p *format_d,
                            va_list args) {
  if (*format_s == '*') {
    format_s++;
    format_d->width = va_arg(args, int);
  } else if (IsDigit(*format_s)) {
    char temp[BUFF_SIZE];
    s21_memset(temp, '\0', BUFF_SIZE);
    for (int i = 0; IsDigit(*format_s); i++, format_s++) {
      temp[i] = *format_s;
    }
    format_d->width = ConvertStrToInt(temp);
  }
  return format_s;
}

static const char *SetPrecision(const char *format_s, s21_format_p *format_d,
                                va_list args) {
  if (*format_s == '.') {
    format_d->prec_set = true;
    format_s++;
  }
  if (*format_s == '*') {
    format_s++;
    format_d->prec = va_arg(args, int);
  } else if (IsDigit(*format_s)) {
    char temp[BUFF_SIZE];
    s21_memset(temp, '\0', BUFF_SIZE);
    for (int i = 0; IsDigit(*format_s); i++, format_s++) {
      temp[i] = *format_s;
    }
    format_d->prec = ConvertStrToInt(temp);
  }
  return format_s;
}

static const char *SetLength(const char *format_s, s21_format_p *format_d) {
  switch (*format_s) {
    case 'h':
      format_d->len = short_l;
      format_s++;
      break;
    case 'l':
      format_d->len = long_l;
      format_s++;
      break;
    case 'L':
      format_d->len = double_l;
      format_s++;
      break;
    default:
      break;
  }
  return format_s;
}

static const char *SetSpec(const char *format_s, s21_format_p *format_d) {
  switch (*format_s) {
    case 'c':
      format_d->spec = c;
      break;
    case 'd':
      format_d->spec = d;
      break;
    case 'i':
      format_d->spec = i;
      break;
    case 'e':
      format_d->spec = e;
      break;
    case 'E':
      format_d->spec = E;
      break;
    case 'f':
      format_d->spec = f;
      break;
    case 's':
      format_d->spec = s;
      break;
    case 'g':
      format_d->spec = g;
      break;
    case 'G':
      format_d->spec = G;
      break;
    case 'u':
      format_d->spec = u;
      break;
    case 'o':
      format_d->spec = o;
      break;
    case 'x':
      format_d->spec = x;
      break;
    case 'X':
      format_d->spec = X;
      break;
    case 'p':
      format_d->spec = p;
      break;
    case 'n':
      format_d->spec = n;
      break;
    case '%':
      format_d->spec = perc;
      break;
    default:
      format_d->spec = non_spec;
      break;
  }
  format_s++;
  return format_s;
}

static bool IsFlag(char format_c) {
  bool result = false;
  if (s21_strchr("-+ 0#", format_c) != S21_NULL) {
    result = true;
  }
  return result;
}

static char *ParseValue(char *str, s21_format_p *format_d, va_list args) {
  char temp[BUFF_SIZE];
  s21_memset(temp, '\0', BUFF_SIZE);
  UseHandlers(temp, format_d, args);
  for (int i = 0; temp[i]; i++, str++) {
    *str = temp[i];
  }
  return str;
}

static void UseHandlers(char *str, s21_format_p *format_d, va_list args) {
  switch (format_d->spec) {
    case d:
    case i:
      ParseInt(str, format_d, args);
      break;
    case o:
      ParseOctal(str, format_d, args);
      break;
    case u:
      ParseUnsigned(str, format_d, args);
      break;
    case x:
    case X:
      ParseHex(str, format_d, args);
      break;
    case c:
      ParseChar(str, format_d, args);
      break;
    case s:
      ParseString(str, format_d, args);
      break;
    case p:
      ParsePointer(str, format_d, args);
      break;
    case f:
      ParseFloat(str, format_d, args);
      break;
    case e:
    case E:
      ParseExp(str, format_d, args);
      break;
    case g:
    case G:
      ParseSmartNum(str, format_d, args);
      break;
    case perc:
      str[0] = '%';
      break;
    default:
      break;
  }
}

static void ParseInt(char *str, s21_format_p *format_d, va_list args) {
  int64_t temp = va_arg(args, int64_t);
  if (format_d->len == short_l) {
    temp = (int16_t)temp;
  } else if (format_d->len == default_l) {
    temp = (int32_t)temp;
  }
  ConvertNumToString(temp, str, 10);
  Handler_Precision(str, format_d);
  Handler_Flag(str, format_d);
}

static void Handler_Precision(char *str, s21_format_p *format_d) {
  char temp[BUFF_SIZE];
  s21_memset(temp, '\0', BUFF_SIZE);
  s21_size_t len = s21_strlen(str);
  bool isNegative = false;
  if (str[0] == '-') {
    temp[0] = '-';
    isNegative = true;
  }
  if (format_d->prec > len) {
    int i = 0, j = 0;
    if (isNegative) {
      i = 1, j = 1;
    }
    for (; i < format_d->prec - len; i++) {
      temp[i] = '0';
    }
    for (; str[j]; i++, j++) {
      temp[i] = str[j];
    }
    s21_strcpy(str, temp);
  }
  if (format_d->prec_set && format_d->prec == 0 && IsDigSpec(format_d->spec) &&
      str[0] == '0') {
    str[0] = '\0';
  }
}

static bool IsDigSpec(spec sp) {
  bool result = false;
  if (sp == d || sp == i || sp == o || sp == u || sp == x || sp == X) {
    result = true;
  }
  return result;
}

static void Handler_Flag(char *str, s21_format_p *format_d) {
  char temp[BUFF_SIZE + 1];
  s21_memset(temp, '\0', BUFF_SIZE + 1);
  if (format_d->plus && !IsUnsignedSpec(format_d->spec)) {
    Handler_IntPlusFlag(temp, str);
  } else if (format_d->space && str[0] != '-' &&
             !IsUnsignedSpec(format_d->spec)) {
    Handler_IntSpaceFlag(temp, str);
  }
  if (format_d->width > s21_strlen(str)) {
    int i = format_d->width - s21_strlen(str);
    if (!format_d->minus) {
      Handler_IntZeroFlag(format_d->zero, temp, i);
      s21_strcpy(temp + i, str);
    } else {
      Handler_IntMinusFlag(temp, str, i);
    }
    s21_strcpy(str, temp);
  }
}

static bool IsUnsignedSpec(spec sp) {
  bool result = false;
  if (sp == o || sp == u || sp == x || sp == X) {
    result = true;
  }
  return result;
}

static void Handler_IntPlusFlag(char *temp, char *str) {
  bool isNegative = false;
  if (str[0] == '-') {
    temp[0] = '-';
    isNegative = true;
  } else {
    temp[0] = '+';
  }
  if (isNegative) {
    s21_strcpy(temp + 1, str + 1);
  } else {
    s21_strcpy(temp + 1, str);
  }
  s21_strcpy(str, temp);
}

static void Handler_IntSpaceFlag(char *temp, char *str) {
  temp[0] = ' ';
  s21_strcpy(temp + 1, str);
  s21_strcpy(str, temp);
}

static void Handler_IntMinusFlag(char *temp, char *str, int index) {
  s21_strcpy(temp, str);
  s21_memset(temp + s21_strlen(temp), ' ', index);
}

static void Handler_IntZeroFlag(bool zero, char *temp, int index) {
  if (zero) {
    s21_memset(temp, '0', index);
  } else {
    s21_memset(temp, ' ', index);
  }
}

static void ParseOctal(char *str, s21_format_p *format_d, va_list args) {
  int offset = 0;
  if (format_d->sharp) {
    str[0] = '0';
    offset += 1;
  }
  ConvertNumToString(va_arg(args, int64_t), str + offset, 8);
  Handler_Precision(str, format_d);
  Handler_Flag(str, format_d);
}

static void ParseUnsigned(char *str, s21_format_p *format_d, va_list args) {
  uint64_t temp = va_arg(args, uint64_t);
  if (format_d->len == default_l) {
    temp = (uint32_t)temp;
  } else if (format_d->len == short_l) {
    temp = (uint16_t)temp;
  }
  ConvertUIntToString(temp, str, 10);
  Handler_Precision(str, format_d);
  Handler_Flag(str, format_d);
}

static void ParseHex(char *str, s21_format_p *format_d, va_list args) {
  uint64_t temp = va_arg(args, uint64_t);
  if (format_d->len == short_l) {
    temp = (uint16_t)temp;
  } else if (format_d->len == long_l) {
    temp = (uint64_t)temp;
  } else {
    temp = (uint32_t)temp;
  }
  ConvertUIntToString(temp, str, 16);
  Handler_Precision(str, format_d);
  Handler_HexPrefix(str, format_d);
  Handler_Flag(str, format_d);
  Handler_Hex(str, format_d);
}

static void Handler_Hex(char *str, s21_format_p *format_d) {
  if (format_d->sharp && format_d->zero) {
    char *xPos = s21_strchr(str, 'x');
    if (str[0] == '0' && str[1] == '0') {
      str[1] = 'x';
      *xPos = '0';
    }
  }
  if (format_d->spec == X) {
    Handler_X(str);
  }
}

static void Handler_HexPrefix(char *str, s21_format_p *format_d) {
  if ((format_d->sharp && IsDigSpec(format_d->spec)) || format_d->spec == p) {
    bool isZero = true;
    for (int i = 0; str[i] && isZero; i++) {
      if (str[i] != '0') {
        isZero = false;
      }
    }
    if ((!isZero && IsDigSpec(format_d->spec)) || format_d->spec == p) {
      s21_memmove(str + 2, str, s21_strlen(str));
      str[0] = '0';
      str[1] = 'x';
    }
  }
}

static void Handler_X(char *str) {
  s21_size_t len = s21_strlen(str);
  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 97 && str[i] <= 122) {
      str[i] = str[i] - 32;
    }
  }
}

static void ParseChar(char *str, s21_format_p *format_d, va_list args) {
  if (format_d->len == long_l) {
    wchar_t ch = va_arg(args, wchar_t);
    Handler_WChar(str, format_d, ch);
  } else {
    unsigned char ch = va_arg(args, int);
    Handler_Char(str, format_d, ch);
  }
}

static void Handler_WChar(char *str, s21_format_p *format_d, wchar_t ch) {
  int size = 0;
  if (!format_d->minus && format_d->width) {
    char temp[BUFF_SIZE];
    s21_memset(temp, '\0', BUFF_SIZE);
    wcstombs(temp, &ch, BUFF_SIZE);
    size = s21_strlen(temp);
    for (int i = 0; i < format_d->width - size; i++) {
      str[i] = ' ';
    }
    s21_strcat(str, temp);
  } else if (format_d->width) {
    wcstombs(str, &ch, BUFF_SIZE);
    size = s21_strlen(str);
    for (int i = size; i < format_d->width; i++) {
      str[i] = ' ';
    }
  } else {
    wcstombs(str, &ch, BUFF_SIZE);
  }
}

static void Handler_Char(char *str, s21_format_p *format_d, char ch) {
  if (!format_d->minus && format_d->width) {
    for (int i = 0; i < format_d->width; i++) {
      str[i] = ' ';
      if (i == format_d->width - 1) {
        str[i] = ch;
      }
    }
  } else if (format_d->width) {
    str[0] = ch;
    for (int i = 1; i < format_d->width; i++) {
      str[i] = ' ';
    }
  } else {
    str[0] = ch;
  }
}

static void ParseString(char *str, s21_format_p *format_d, va_list args) {
  if (format_d->len == long_l) {
    wchar_t *temp = va_arg(args, wchar_t *);
    Handler_WString(str, format_d, temp);
  } else {
    char *temp = va_arg(args, char *);
    Handler_String(str, format_d, temp);
  }
}

static void Handler_WString(char *str, s21_format_p *format_d,
                            wchar_t *wstring) {
  char temp[BUFF_SIZE];
  s21_memset(temp, '\0', BUFF_SIZE);
  wcstombs(temp, wstring, BUFF_SIZE);
  if (format_d->prec_set) {
    temp[format_d->prec] = '\0';
  }
  int len = s21_strlen(temp);
  int shift = format_d->width - len;

  if (format_d->minus && shift > 0) {
    s21_strcpy(str, temp);
    s21_memset(str + len, ' ', shift);
  } else if (shift > 0) {
    s21_memset(str, ' ', shift);
    s21_strcpy(str + shift, temp);
  } else {
    s21_strcpy(str, temp);
  }
}

static void Handler_String(char *str, s21_format_p *format_d, char *string) {
  char temp[BUFF_SIZE];
  s21_memset(temp, '\0', BUFF_SIZE);
  s21_strcpy(temp, string);
  if (format_d->prec_set) {
    temp[format_d->prec] = '\0';
  }
  int len = s21_strlen(temp);
  int shift = format_d->width - len;

  if (format_d->minus && shift > 0) {
    s21_strcpy(str, temp);
    s21_memset(str + len, ' ', shift);
  } else if (shift > 0) {
    s21_memset(str, ' ', shift);
    s21_strcpy(str + shift, temp);
  } else {
    s21_strcpy(str, temp);
  }
}

static void ParsePointer(char *str, s21_format_p *format_d, va_list args) {
  ConvertUIntToString(va_arg(args, uint64_t), str, 16);
  Handler_Precision(str, format_d);
  Handler_HexPrefix(str, format_d);
  Handler_Flag(str, format_d);
}

static void ParseFloat(char *str, s21_format_p *format_d, va_list args) {
  long double temp = 0;
  if (format_d->len == double_l) {
    temp = va_arg(args, long double);
  } else {
    temp = va_arg(args, double);
  }
  if (!format_d->prec_set) {
    format_d->prec = 6;
  }
  ConvertDoubleToString(temp, str, format_d->prec, format_d->sharp);
  Handler_Flag(str, format_d);
}

static void ParseExp(char *str, s21_format_p *format_d, va_list args) {
  long double temp = 0;
  if (format_d->len == double_l) {
    temp = va_arg(args, long double);
  } else {
    temp = va_arg(args, double);
  }
  char sign = '\0';
  int expNum = GetExpNum(&temp, &sign);
  if (!format_d->prec_set) {
    format_d->prec = 6;
  }
  ConvertDoubleToString(temp, str, format_d->prec, format_d->sharp);
  Handler_Exp(str, expNum, sign, format_d->spec);
  Handler_Flag(str, format_d);
}

static int GetExpNum(long double *num, char *sign) {
  int result = 0;
  *sign = '+';
  if ((int)*num == 0) {
    *sign = '-';
  }
  if ((int)*num - *num) {
    while ((int)*num == 0) {
      result++;
      *num = *num * 10;
    }
  } else {
    *sign = '+';
  }
  while ((int)*num / 10 != 0) {
    result++;
    *num = *num / 10;
  }
  return result;
}

static void Handler_Exp(char *str, int expNum, char sign, spec spec) {
  int length = s21_strlen(str);
  if (spec == E || spec == G) {
    str[length] = 'E';
  } else if (spec == e || spec == g) {
    str[length] = 'e';
  }
  str[length + 1] = sign;
  str[length + 3] = expNum % 10 + '0';
  expNum /= 10;
  str[length + 2] = expNum % 10 + '0';
  str[length + 4] = '\0';
}

static void ParseSmartNum(char *str, s21_format_p *format_d, va_list args) {
  long double temp = 0;
  if (format_d->len == double_l) {
    temp = va_arg(args, long double);
  } else {
    temp = va_arg(args, double);
  }
  if (!format_d->prec_set) {
    format_d->prec = 6;
  }
  if (SwitchToExp(temp, format_d)) {
    CorrectPrec(temp, format_d);
    char sign = '\0';
    int expNum = GetExpNum(&temp, &sign);
    ConvertDoubleToString(temp, str, format_d->prec, format_d->sharp);
    Handler_Exp(str, expNum, sign, format_d->spec);
    Handler_Flag(str, format_d);
  } else {
    int fractPrec = GetFractPrec(temp, format_d);
    ConvertDoubleToString(temp, str, fractPrec, format_d->sharp);
    Handler_SmartNumPrecision(str, format_d);
    Handler_Flag(str, format_d);
  }
}

static bool SwitchToExp(long double num, s21_format_p *format_d) {
  bool result = false;
  if ((num / pow(10, format_d->prec)) > 1 ||
      (num * pow(10, 4) < 1 && num * (pow(10, 21)) >= 1)) {
    result = true;
  }
  return result;
}

static void CorrectPrec(long double num, s21_format_p *format_d) {
  if (num < 1 && format_d->prec == 0) {
    format_d->prec = 4;
  } else {
    format_d->prec--;
  }
}

static int GetFractPrec(long double num, s21_format_p *format_d) {
  int result = format_d->prec;
  int numCopy = num;
  int count = 0;
  while (numCopy != 0) {
    count++;
    numCopy /= 10;
  }
  if (count >= format_d->prec) {
    result = 0;
  }
  return result;
}

static void Handler_SmartNumPrecision(char *str, s21_format_p *format_d) {
  if (str && s21_strlen(str) > format_d->prec) {
    str[format_d->prec + 1] = '\0';
  }
  CleanZero(str, format_d);
  Handler_SmarpSharpFlag(str, format_d);
}

static void Handler_SmarpSharpFlag(char *str, s21_format_p *format_d) {
  if (format_d->sharp) {
    int length = s21_strlen(str) - 1;
    int tailSize = format_d->prec - length;
    if (tailSize > 0) {
      for (; tailSize < format_d->prec; tailSize++) {
        s21_strcat(str, "0");
      }
    }
  }
}

static void CleanZero(char *str, s21_format_p *format_d) {
  s21_size_t length = s21_strlen(str);
  char *precPos = s21_strchr(str, '.');
  bool breakPoint = false;
  if (precPos) {
    for (s21_size_t i = length - 1; str[i] != '.' && !breakPoint; i--) {
      if (str[i] == '0') {
        str[i] = '\0';
      } else {
        breakPoint = true;
      }
    }
    if (precPos[1] == '\0' && !format_d->sharp) {
      precPos[0] = '\0';
    }
  }
}
