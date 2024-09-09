dadlib: dadlibs.o process.o prompt.o
		gcc dadlibs.o process.o prompt.o -o dadlibs
		rm dadlibs.o process.o prompt.o

dadlibs.o: dadlibs.c
		gcc -c dadlibs.c

process.o: process.c
		gcc -c process.c

prompt.o: prompt.c
		gcc -c prompt.c

clean:
		rm *.o dadlibs