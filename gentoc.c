#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "src/processor.h"


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
