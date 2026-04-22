all: hangman

hangman: main.o game.o words.o
	gcc main.o game.o words.o -o hangman

main.o: main.c game.h words.h
	gcc -c main.c

game.o: game.c game.h
	gcc -c game.c

words.o: words.c words.h
	gcc -c words.c

clean:
	rm -f *.o hangman