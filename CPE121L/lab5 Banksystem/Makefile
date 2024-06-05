APPEND = lab5
all : main.o Bankfunction.o  
	g++ main.o Bankfunction.o -o $(APPEND)

main.o : main.cpp
	g++ -c main.cpp -o main.o

Bankfunction.o : Bankfunction.cpp
	g++ -c Bankfunction.cpp -o Bankfunction.o

clean :
	rm -f *.o $(APPEND)