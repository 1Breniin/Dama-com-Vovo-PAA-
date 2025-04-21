tp1: main.o tabuleiro.o estrategia.o tempo.o
	gcc -o tp1 main.o tabuleiro.o estrategia.o tempo.o

main.o: main.c tabuleiro.h estrategia.h tempo.h
	gcc -c main.c

tabuleiro.o: tabuleiro.c tabuleiro.h
	gcc -c tabuleiro.c

estrategia.o: estrategia.c estrategia.h tabuleiro.h
	gcc -c estrategia.c

tempo.o: tempo.c tempo.h
	gcc -c tempo.c

clean:
	rm -f *.o tp1
