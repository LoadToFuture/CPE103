APPEND = rectangle
all : main.o rectangle.o
	g++ main.o rectangle.o -o $(APPEND)

main.o : main.cpp
	g++ -c main.cpp -o main.o
rectangle.o : rectangle.cpp
	g++ -c rectangle.cpp -o rectangle.o

clean :
	rm -f main.o rectangle.o $(APPEND)