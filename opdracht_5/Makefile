CC=gcc
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -lm
DEPS = tictactoedrawable.hpp cross.hpp cursor.hpp circle.hpp tictactoegrid.hpp tictactoegridspot.hpp game.hpp bigdrawer.hpp coutdrawer.hpp
OBJ = cross.o cursor.o circle.o tictactoegrid.o tictactoegridspot.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ)
	rm -f build