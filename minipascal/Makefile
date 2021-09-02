minipascal: parser.tab.o lex.yy.o izrazi.o naredba.o
	g++ -Wall -o $@ $^
parser.tab.o: parser.tab.cpp izrazi.hpp naredba.hpp
	g++ -Wall -c -o $@ $<
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -dv $<
lex.yy.o: lex.yy.c parser.tab.hpp izrazi.hpp naredba.hpp
	g++ -Wall -Wno-sign-compare -c -o $@ $<
lex.yy.c: lexer.lex
	flex $<
izrazi.o: izrazi.cpp izrazi.hpp
	g++ -Wall -c -o $@ $<
naredba.o: naredba.cpp naredba.hpp izrazi.hpp
	g++ -Wall -c -o $@ $<

	
.PHONY: clean

clean:
	rm -f *~ *.o *.c *.tab.* *.output minipascal