APPEND = week3
all : main.o student.o  
	g++ main.o student.o -o $(APPEND)

student.o : student.cpp
	g++ -c student.cpp -o student.o

main.o : main.cpp
	g++ -c main.cpp -o main.o

clean :
	rm -f *.o $(APPEND)