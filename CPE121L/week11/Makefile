APPEND = week11

all : main.o GrandFa.o GrandMa.o FaMa.o
	g++ main.o GrandFa.o GrandMa.o FaMa.o -o $(APPEND)
main.o : main.cpp
	g++ -c main.cpp -o main.o
GrandFa.o : class/GrandFa/GrandFa.cpp
	g++ -c class/GrandFa/GrandFa.cpp -o GrandFa.o
GrandMa.o : class/GrandMa/GrandMa.cpp
	g++ -c class/GrandMa/GrandMa.cpp -o GrandMa.o
FaMa.o : class/FaMa/FaMa.cpp
	g++ -c class/FaMa/FaMa.cpp -o FaMa.o
clean : 
	rm -f *.o $(APPEND)