all: main

main: main.c
	gcc -std=c11 -o main main.c
	
clean: ./main
	rm main