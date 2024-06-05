APPEND = week1
all : main.o
	g++ main.o -o $(APPEND)

main.o : main.cpp
	g++ -c main.cpp -o main.o

clean :
	rm main.o $(APPEND)