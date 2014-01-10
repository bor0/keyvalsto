@all:
	gcc main.c src/*.c -Iinclude/ -o keyvalsto -Wall -std=c99 -O3

clean:
	@rm -f keyvalsto keyvalsto.data