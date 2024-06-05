APPEND = rac66044768
all : main.o ractan.o
	g++ main.o ractan.o -o $(APPEND)

main.o : main.cpp
	g++ -c main.cpp -o main.o
ractan.o : ractan.cpp
	g++ -c ractan.cpp -o ractan.o

clean :
	rm -f main.o ractan.o $(APPEND)