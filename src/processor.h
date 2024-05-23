#ifndef PROCESSOR_HEADER
#define PROCESSOR_HEADER

#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"

#define MAX_LINE_LENGTH 1024

FILE *openFile(char *filepath);
void processLine(char *string);

#endif // PROCESSOR_HEADER
