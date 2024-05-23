OS := $(shell uname)

CC = gcc
CFLAGS = -Wall -Wextra
SOURCE = gentoc.c

ifeq ($(OS), Linux)
	TARGET = gentoc
else
	TARGET = gentoc.exe
endif

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -f $(TARGET)

all: $(TARGET)
