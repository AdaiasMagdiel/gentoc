#ifndef STRING_UTILS
#define STRING_UTILS

#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool str_startsWith(char *string, char *needle);
int str_countChar(char *string, char ch);
bool char_isLetter(char c);
char char_toLower(char c);

#endif // STRING_UTILS
