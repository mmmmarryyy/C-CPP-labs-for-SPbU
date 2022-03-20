all: lab-07_matrix

obj:
	if [ ! -d "obj" ]; then mkdir "obj"; fi

obj/matrix.o: src/matrix.cpp 
	g++ -c -std=c++17 src/matrix.cpp -Iinclude -o obj/matrix.o

obj/main.o: src/main.cpp
	g++ -c -std=c++17 src/main.cpp -Iinclude -o obj/main.o

lab-07_matrix: obj obj/matrix.o obj/main.o
	g++ -std=c++17 obj/matrix.o obj/main.o -o lab-07_matrix

clean:
	rm -R obj lab-07_matrix