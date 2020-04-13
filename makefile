main:main.o functions.o
		gcc -g -o main main.o functions.o
main.o:main.c header.h
		gcc -c main.c
functions.o:functions.c header.h
		gcc -c functions.c
clean:
		rm -f *.s *.o main
