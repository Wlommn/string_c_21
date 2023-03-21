#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <stdarg.h>
#include <stdint.h>

#include "./s21_convert.h"
#include "./s21_format.h"
#include "./s21_string.h"

static const char *SetConfig(const char *format_s, s21_format_p *format_d,
                             va_list args);
static const char *SetFlag(const char *format_s, s21_format_p *format_d);
static const char *SetWidth(const char *format_s, s21_format_p *format_d,
                            va_list args);
static const char *SetPrecision(const char *format_s, s21_format_p *format_d,
                                va_list args);
static const char *SetLength(const char *format_s, s21_format_p *format_d);
static const char *SetSpec(const char *format_s, s21_format_p *format_d);

static bool IsFlag(char format_c);

static char *ParseValue(char *str, s21_format_p *format_d, va_list args);
static void UseHandlers(char *str, s21_format_p *format_d, va_list args);

static void ParseInt(char *str, s21_format_p *format_d, va_list args);

static void Handler_Precision(char *str, s21_format_p *format_d);

static bool IsDigSpec(spec sp);

static void Handler_Flag(char *str, s21_format_p *format_d);

static bool IsUnsignedSpec(spec sp);

static void Handler_IntPlusFlag(char *temp, char *str);
static void Handler_IntSpaceFlag(char *temp, char *str);
static void Handler_IntMinusFlag(char *temp, char *str, int index);
static void Handler_IntZeroFlag(bool zero, char *temp, int index);

static void ParseOctal(char *str, s21_format_p *format_d, va_list args);
static void ParseUnsigned(char *str, s21_format_p *format_d, va_list args);

static void ParseHex(char *str, s21_format_p *format_d, va_list args);
static void Handler_HexPrefix(char *str, s21_format_p *format_d);
static void Handler_Hex(char *str, s21_format_p *format_d);
static void Handler_X(char *str);

static void ParseChar(char *str, s21_format_p *format_d, va_list args);
static void Handler_WChar(char *str, s21_format_p *format_d, wchar_t ch);
static void Handler_Char(char *str, s21_format_p *format_d, char ch);

static void ParseString(char *str, s21_format_p *format_d, va_list args);
static void Handler_WString(char *str, s21_format_p *format_d,
                            wchar_t *wstring);
static void Handler_String(char *str, s21_format_p *format_d, char *string);

static void ParsePointer(char *str, s21_format_p *format_d, va_list args);
static void ParseFloat(char *str, s21_format_p *format_d, va_list args);

static void ParseExp(char *str, s21_format_p *format_d, va_list args);
static int GetExpNum(long double *num, char *sign);
static void Handler_Exp(char *str, int expNum, char sign, spec spec);

static void ParseSmartNum(char *str, s21_format_p *format_d, va_list args);
static bool SwitchToExp(long double num, s21_format_p *format_d);
static void CorrectPrec(long double num, s21_format_p *format_d);
static int GetFractPrec(long double num, s21_format_p *format_d);
static void Handler_SmartNumPrecision(char *str, s21_format_p *format_d);
static void Handler_SmarpSharpFlag(char *str, s21_format_p *format_d);
static void CleanZero(char *str, s21_format_p *format_d);

#endif  //  SRC_S21_SPRINTF_H_
