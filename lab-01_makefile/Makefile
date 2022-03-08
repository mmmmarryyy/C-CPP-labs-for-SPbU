all: lab-01_makefile

obj/main.o: src/main.c
	mkdir -p obj/
	gcc -c src/main.c -Iinclude -o obj/main.o

obj/io.o: src/io.c
	mkdir -p obj/
	gcc -c src/io.c -Iinclude -o obj/io.o

obj/algorithm.o: src/algorithm.c
	mkdir -p obj/
	gcc -c src/algorithm.c -Iinclude -o obj/algorithm.o

obj/util.o: src/util.c
	mkdir -p obj/
	gcc -c src/util.c -Iinclude -o obj/util.o

lab-01_makefile: obj/main.o obj/io.o obj/algorithm.o obj/util.o
	gcc obj/main.o obj/io.o obj/algorithm.o obj/util.o -Iinclude -o lab-01_makefile

clean:
	rm -R obj lab-01_makefile