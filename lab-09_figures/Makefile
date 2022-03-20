all: lab-09_figures

obj:
	if [ ! -d "obj" ]; then mkdir "obj"; fi

obj/Scheme.o: src/Scheme.cpp 
	g++ -c -std=c++17 src/Scheme.cpp -Iinclude -o obj/Scheme.o

obj/Figure.o: src/Figure.cpp
	g++ -c -std=c++17 src/Figure.cpp -Iinclude -o obj/Figure.o

obj/Circle.o: src/Circle.cpp
	g++ -c -std=c++17 src/Circle.cpp -Iinclude -o obj/Circle.o

obj/Rectangle.o: src/Rectangle.cpp
	g++ -c -std=c++17 src/Rectangle.cpp -Iinclude -o obj/Rectangle.o

obj/main.o: src/main.cpp 
	g++ -c -std=c++17 src/main.cpp -Iinclude -o obj/main.o

lab-09_figures: obj obj/Circle.o obj/Rectangle.o obj/Figure.o obj/main.o obj/Scheme.o
	g++ -std=c++17 obj/Circle.o obj/Rectangle.o obj/Figure.o obj/main.o obj/Scheme.o -o lab-09_figures

clean:
	rm -R obj lab-09_figures

