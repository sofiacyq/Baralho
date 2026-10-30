CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11

ifeq ($(OS),Windows_NT)
RM = del /Q
EXE = .exe
else
RM = rm -f
EXE =
endif

all: main gerador

main: maincomandos.o cartasbaralho.o historico.o
	$(CC) $(CFLAGS) -o main$(EXE) maincomandos.o cartasbaralho.o historico.o

gerador: gerador.o
	$(CC) $(CFLAGS) -o gerador$(EXE) gerador.o

maincomandos.o: maincomandos.c cartasbaralho.h historico.h
	$(CC) $(CFLAGS) -c maincomandos.c

cartasbaralho.o: cartasbaralho.c cartasbaralho.h historico.h
	$(CC) $(CFLAGS) -c cartasbaralho.c

historico.o: historico.c historico.h
	$(CC) $(CFLAGS) -c historico.c

gerador.o: gerador.c
	$(CC) $(CFLAGS) -c gerador.c

clean:
	$(RM) *.o main$(EXE) gerador$(EXE)
