APPEND = week4
all : main.o circle.o
	g++ main.o circle.o -o $(APPEND)

circle.o : circle.cpp
	g++ -c circle.cpp -o circle.o

main.o : main.cpp
	g++ -c main.cpp -o main.o

clean :
	rm -f *.o $(APPEND)