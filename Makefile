OS := $(shell uname)

CC = gcc
CFLAGS = -Wall -Wextra
SOURCE = gentoc.c
FILES  = ./src/string_utils.c ./src/processor.c

ifeq ($(OS), Linux)
	TARGET = gentoc
else
	TARGET = gentoc.exe
endif

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET) $(FILES)

clean:
	rm -f $(TARGET)

all: $(TARGET)
