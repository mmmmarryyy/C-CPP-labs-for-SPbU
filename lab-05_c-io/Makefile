all: lab-05_c-io

obj: 
	if [ ! -d "obj" ]; then mkdir "obj"; fi

obj/clist.o: src/clist.c
	gcc -c src/clist.c -Iinclude -o obj/clist.o 

obj/point_list.o: src/point_list.c 
	gcc -c src/point_list.c -Iinclude -o obj/point_list.o 

obj/main.o: src/main.c
	gcc -c src/main.c -Iinclude -o obj/main.o

lab-05_c-io: obj obj/clist.o obj/point_list.o obj/main.o
	gcc obj/clist.o obj/point_list.o obj/main.o -o lab-05_c-io

clean:
	rm -R obj lab-05_c-io