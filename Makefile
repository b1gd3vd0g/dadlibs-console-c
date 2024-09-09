madlib: madlib.o process.o prompt.o
		gcc madlib.o process.o prompt.o -o madlib
		rm madlib.o process.o prompt.o

madlib.o: madlib.c
		gcc -c madlib.c

process.o: process.c
		gcc -c process.c

prompt.o: prompt.c
		gcc -c prompt.c

clean:
		rm *.o madlib