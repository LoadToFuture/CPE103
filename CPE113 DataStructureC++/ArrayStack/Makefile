all : main.o ../ArrayList/ArrayList.o ArrayStack.o
	g++ main.o ../ArrayList/ArrayList.o ArrayStack.o -o ArrayStack

main.o: main.cpp
	g++ -c main.cpp -o main.o 

../ArrayList/ArrayList.o : ../ArrayList/ArrayList.cpp
	g++ -c ../ArrayList/ArrayList.cpp -o ../ArrayList/ArrayList.o

ArrayStack.o : ArrayStack.cpp
	g++ -c ArrayStack.cpp -o ArrayStack.o

clean :
	rm -f *.o ../ArrayList/ArrayList.o ArrayStack