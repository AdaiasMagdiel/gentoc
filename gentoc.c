#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

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

FILE *openFile(char *filepath) {
	FILE *fp = fopen(filepath, "r");
	if (fp == NULL) {
		printf("Error: Unable to open file.\n");
		exit(1);
	}

	return fp;
}

bool char_isLetter(unsigned char c) {
	return (
		((int) c >= 65 && (int) c <= 90)     || // A-Z
		((int) c >= 192 && (int) c <= 222)   || // À-Þ
		((int) c >= 97 && (int) c <= 122)    || // a-z
		((int) c == 159) || ((int) c == 142) || // Ÿ || Ž
		((int) c == 140) || ((int) c == 138)    // Œ || Š
	);
}

char char_toLower(unsigned char c) {
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

void processLine(char *string) {
	if (!str_startsWith(string, "##")) return;

	int len = strlen(string);
	int count = str_countChar(string, '#');

	char buffer[MAX_LINE_LENGTH];
	int ptr = 0;

	for (int i=0; i<count-1; i++) {
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

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: main.exe [file]");
		exit(1);
	}

	FILE *fp = openFile(argv[1]);

	char buffer[MAX_LINE_LENGTH];

	while((fgets(buffer, sizeof(buffer), fp)) != NULL) {
		processLine(buffer);
	}

	fclose(fp);
	return 0;
}
