APPEND = Triangle
all : main.o Triangle.o
	g++ main.o Triangle.o -o $(APPEND)

main.o : main.cpp
	g++ -c main.cpp -o main.o
Triangle.o : Triangle.cpp
	g++ -c Triangle.cpp -o Triangle.o

clean :
	rm -f main.o Triangle.o $(APPEND)