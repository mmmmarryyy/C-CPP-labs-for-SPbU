all: lab-03_mergesort

obj: 
	if [ ! -d "obj" ]; then mkdir "obj"; fi

obj/mergesort.o: src/mergesort.c
	gcc -c src/mergesort.c -Iinclude -o obj/mergesort.o 

obj/main.o: src/main.c include/mergesort.h
	gcc -c src/main.c -Iinclude -o obj/main.o

lab-03_mergesort: obj obj/mergesort.o obj/main.o
	gcc obj/mergesort.o obj/main.o -o lab-03_mergesort

clean:
	rm -R obj lab-03_mergesort