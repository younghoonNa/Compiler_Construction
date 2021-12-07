20185124-simple: 20185124-simple.l 20185124-simple.y
	bison -d -o 20185124-simple.tab.c 20185124-simple.y
	flex -o 20185124-simple.lex.c 20185124-simple.l
	$(CC) -o 20185124-simple 20185124-simple.tab.c 20185124-simple.lex.c

clean:
	rm *.c *.h
