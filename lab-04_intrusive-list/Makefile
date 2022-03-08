all: lab-04_intrusive-list

obj: 
	if [ ! -d "obj" ]; then mkdir "obj"; fi

obj/clist.o: src/clist.c include/clist.h
	gcc -c src/clist.c -Iinclude -o obj/clist.o 

obj/main.o: src/main.c include/clist.h
	gcc -c src/main.c -Iinclude -o obj/main.o 

lab-04_intrusive-list: obj obj/clist.o obj/main.o
	gcc obj/clist.o obj/main.o -o lab-04_intrusive-list

clean:
	rm -R obj lab-04_intrusive-list