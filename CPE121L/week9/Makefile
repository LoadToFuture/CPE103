APPEND = week9

all: main.o Area.o Circle.o Squre.o
	g++ main.o Area.o Circle.o Squre.o -o $(APPEND)
main.o : main.cpp
	g++ -c main.cpp -o main.o
Circle.o : ../week9-1/Circle.cpp
	g++ -c ../week9-1/Circle.cpp -o Circle.o
Squre.o : ../week9-1/Squre.cpp
	g++ -c ../week9-1/Squre.cpp -o Squre.o
Area.o : ../week9-1/Circle.cpp
	g++ -c ../week9-1/Area.cpp -o Area.o
clean : 
	rm -f *.o $(APPEND)