CXX=g++

all: main

main: main.o
	mkdir -p bin
	$(CXX) -o bin/main main.o

main.o: src/main.cpp
	$(CXX) -c src/main.cpp

clean:
	rm -rf *.o