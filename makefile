CC     = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2
 
PRINCIPAL = principal
GERADOR   = gerador
 
OBJ_PRINCIPAL = maincomandos.o cartasbaralho.o historico.o
HEADERS       = cartasbaralho.h historico.h
 
all: $(PRINCIPAL) $(GERADOR)
 
# programa principal: interpreta os comandos do baralho
$(PRINCIPAL): $(OBJ_PRINCIPAL)
	$(CC) $(CFLAGS) -o $@ $^
 
# gerador de rajadas: programa a parte, nao usa o TAD
$(GERADOR): gerador.o
	$(CC) $(CFLAGS) -o $@ $^
 
# regra geral: qualquer .o depende do seu .c e dos headers
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm -f *.o $(PRINCIPAL) $(GERADOR)

  CC     = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2
 
PRINCIPAL = principal
GERADOR   = gerador
 
OBJ_PRINCIPAL = maincomandos.o cartasbaralho.o historico.o
HEADERS       = cartasbaralho.h historico.h
 
all: $(PRINCIPAL) $(GERADOR)
 
# programa principal: interpreta os comandos do baralho
$(PRINCIPAL): $(OBJ_PRINCIPAL)
	$(CC) $(CFLAGS) -o $@ $^
 
# gerador de rajadas: programa a parte, nao usa o TAD
$(GERADOR): gerador.o
	$(CC) $(CFLAGS) -o $@ $^
 
# regra geral: qualquer .o depende do seu .c e dos headers
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm -f *.o $(PRINCIPAL) $(GERADOR)

# monta o zip de entrega, com os arquivos na raiz: make zip NUSP=<numero USP>
zip: clean
	@test -n "$(NUSP)" || (echo "uso: make zip NUSP=<numero USP>"; exit 1)
	zip T2_$(NUSP).zip *.c *.h Makefile relatorio.pdf
 
.PHONY: all clean zip
 

 
