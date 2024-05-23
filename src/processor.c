#include "processor.h"

FILE *openFile(char *filepath) {
	FILE *fp = fopen(filepath, "r");
	if (fp == NULL) {
		printf("Error: Unable to open file.\n");
		exit(1);
	}

	return fp;
}

void processLine(char *string) {
	if (!str_startsWith(string, "##")) return;

	int len = strlen(string);
	int count = str_countChar(string, '#');

	char buffer[MAX_LINE_LENGTH];
	int ptr = 0;

	for (int i=0; i<count-2; i++) {
		buffer[ptr++] = ' ';
		buffer[ptr++] = ' ';
	}
	buffer[ptr++] = '-';
	buffer[ptr++] = ' ';
	buffer[ptr++] = '[';

	bool chopped = false;
	for (int i=count; i<len; i++) {
		if (string[i] == '\n' || string[i] == '\0') continue;

		if (!chopped && string[i] == ' ') {
			while (string[i] == ' ') i++;
			chopped = true;
		}

		buffer[ptr++] = string[i];
	}

	buffer[ptr++] = ']';
	buffer[ptr++] = '(';
	buffer[ptr++] = '#';

	chopped = false;
	for (int i=count; i<len; i++) {
		if (string[i] == '\n' || string[i] == '\0') continue;

		if (!chopped && string[i] == ' ') {
			while (string[i] == ' ') i++;
			chopped = true;
		}

		char c = string[i];

		if (char_isLetter(c)){
			buffer[ptr++] = char_toLower(c);
		}

		if (c == ' ') {
			buffer[ptr++] = '-';
		}

		if (
			c == '_' ||
			c == '-' ||
			((int) c >= 48 && (int) c <= 57) // Numbers
		) {
			buffer[ptr++] = c;
		}
	}

	buffer[ptr++] = ')';
	buffer[ptr++] = '\0';

	printf("%s\n", buffer);
}
