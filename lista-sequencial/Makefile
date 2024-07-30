TARGET = lista-seq

CC = g++

CFLAGS = -Wall -Wextra -std=c++11

SRC = main.cpp lista-seq.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

test: $(TARGET)
	./$(TARGET)
