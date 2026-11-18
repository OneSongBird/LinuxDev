all:	labirinth.c
	patch -o labirinth_2.c labirinth.c 0001-Ninth-task-Second-version.patch
	patch -o labirinth_3.c labirinth_2.c 0002-Ninth-task-Third-version.patch
	patch -o labirinth_4.c labirinth_3.c 0003-Ninth-task-Fourth-version.patch
	cc labirinth.c -o labirinth1
	cc labirinth_2.c -o labirinth2
	cc labirinth_3.c -o labirinth3
	cc labirinth_4.c -o labirinth4
	./labirinth1
	./labirinth2 3
	./labirinth2 10
	./labirinth3 ' @' 5
	./labirinth3 '.#' 3
	./labirinth4 10 ' @' 7
	./labirinth4 20 ' @' 7
	./labirinth4 10 ' @' 7

clean:
	rm -rf labirinth1 labirinth2 labirinth3 labirinth4 labirinth_2.c labirinth_3.c labirinth_4.c