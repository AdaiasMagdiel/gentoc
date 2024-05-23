#include "string_utils.h"

bool str_startsWith(char *string, char *needle) {
	int len = strlen(needle);

	for (int i=0; i<len; i++) {
		if (string[i] != needle[i]) {
			return false;
		}
	}

	return true;
}

int str_countChar(char *string, char ch) {
	int len = strlen(string);
	int count = 0;

	for (int i=0; i < len; i++) {
		if (string[i] == ch) count++;
	}

	return count;
}
