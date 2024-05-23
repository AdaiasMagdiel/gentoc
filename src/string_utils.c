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

bool char_isLetter(char c) {
	return (
		((int) c >= 65 && (int) c <= 90)     || // A-Z
		((int) c >= 192 && (int) c <= 222)   || // À-Þ
		((int) c >= 97 && (int) c <= 122)    || // a-z
		((int) c == 159) || ((int) c == 142) || // Ÿ || Ž
		((int) c == 140) || ((int) c == 138)    // Œ || Š
	);
}

char char_toLower(char c) {
	if (
		((int) c >= 65 && (int) c <= 90)
	) { // A-Z || À-Þ
		return (char) ((int) c + 32);
	} else if (
		(int) c >= 97 && (int) c <= 122
	) { // a-z
		return c;
	} else if ((int) c == 159) {
		// Ÿ -> ÿ
		return (char) 255;
	} else if ((int) c == 142) {
		// Ž -> ž
		return (char) 158;
	} else if ((int) c == 140) {
		// Œ -> œ
		return (char) 156;
	} else if ((int) c == 138) {
		// Š -> š
		return (char) 154;
	}

	return '\0';
}
