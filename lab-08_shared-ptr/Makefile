all: lab-08_shared-ptr

obj:
	if [ ! -d "obj" ]; then mkdir "obj"; fi

obj/matrix.o: src/matrix.cpp 
	g++ -c -std=c++17 src/matrix.cpp -Iinclude -o obj/matrix.o

obj/shared_ptr.o: src/shared_ptr.cpp
	g++ -c -std=c++17 src/shared_ptr.cpp -Iinclude -o obj/shared_ptr.o

obj/main.o: src/main.cpp 
	g++ -c -std=c++17 src/main.cpp -Iinclude -o obj/main.o

lab-08_shared-ptr: obj obj/shared_ptr.o obj/main.o obj/matrix.o
	g++ -std=c++17 obj/shared_ptr.o obj/main.o obj/matrix.o -o lab-08_shared-ptr

clean:
	rm -R obj lab-08_shared-ptr
