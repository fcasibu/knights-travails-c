CC = gcc
CFLAGS = -Wall -Wextra -std=c2x -pedantic
SRC_FILES = main.c path.c node.c queue.c set.c validmoves.c point.c
TARGET = kt

$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

