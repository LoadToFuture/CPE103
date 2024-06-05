 APPEND = week10
 all : main.o Area/Area.o Square/Square.o Circle/Circle.o Circle2/Circle2.o
	g++  main.o Area/Area.o Square/Square.o Circle/Circle.o Circle2/Circle2.o -o $(APPEND)

Area/Area.o : Area/Area.cpp
	g++ -c Area/Area.cpp -o Area/Area.o

Circle/Circle.o : Circle/Circle.cpp
	g++ -c Circle/Circle.cpp -o Circle/Circle.o

Circle2/Circle2.o : Circle2/Circle2.cpp
	g++ -c Circle2/Circle2.cpp -o Circle2/Circle2.o

Square/Square.o : Square/Square.cpp
	g++ -c Square/Square.cpp -o Square/Square.o

main.o : main.cpp
	g++ -c main.cpp -o main.o

clean :
	rm -f *.o Area/Area.o Square/Square.o Circle/Circle.o Circle2/Circle2.o $(APPEND)