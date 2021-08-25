all:main

main: cliente.o funcionario.o
	gcc main.c cliente.o funcionario.o -lncurses -o main
cliente.o:
	gcc -c cliente.c
funcionario.o:
	gcc -c funcionario.c
rm: 
	rm *o;