
CFLAGS=-DUNIX -lreadline -lcurses 
DEBUG=-g
#DEBUG=

all: shell


shell:	shell.c parse.c headers/parse.h
	gcc $(DEBUG) shell.c parse.c -o shell $(CFLAGS)
clean:
	rm -f shell *~

