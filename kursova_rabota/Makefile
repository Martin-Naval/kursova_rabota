CC = gcc
CFLAGS = -std=c11 -Wall -Wextra
SRC = animal_species.c
TARGET = animal_species

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
