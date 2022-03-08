all: lab-06_int-vector

obj:
	if [ ! -d "obj" ]; then mkdir "obj"; fi

obj/my_vector.o: src/my_vector.cpp 
	g++ -c -std=c++17 src/my_vector.cpp -Iinclude -o obj/my_vector.o

obj/main.o: src/main.cpp
	g++ -c -std=c++17 src/main.cpp -Iinclude -o obj/main.o

lab-06_int-vector: obj obj/my_vector.o obj/main.o
	g++ -std=c++17 obj/my_vector.o obj/main.o -o lab-06_int-vector

clean:
	rm -R obj lab-06_int-vector