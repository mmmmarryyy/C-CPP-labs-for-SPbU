all: obj lab-02

obj:
	if [ ! -d "obj" ]; then mkdir "obj"; fi

obj/str.o: src/str.c
	gcc -c src/str.c -Iinclude -o obj/str.o 

obj/test.o: src/test.c
	gcc -c src/test.c -Iinclude -o obj/test.o

obj/test_str.o: src/test_str.c
	gcc -c src/test_str.c -Iinclude -o obj/test_str.o

lab-02: obj/str.o obj/test.o obj/test_str.o
	gcc obj/str.o obj/test.o obj/test_str.o -o lab-02

clean:
	rm -R obj lab-02