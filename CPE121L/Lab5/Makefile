GCC = g++
CFLAGS = -Wall -Werror -g
TARGET = main
OBJECT = main.o ArrayStack.o Arraylist.o

.SILENT:

all : $(OBJECT)
	$(GCC) $(OBJECT) -o $(TARGET)
	./$(TARGET) 

debug: $(OBJECT)
	$(GCC) $(OBJECT) -o $(TARGET)
	gdb ./$(TARGET)

%.o : %.cpp
	$(GCC) $(CFLAGS) -c $< -o $@

clean :
	rm -f *.o $(TARGET)
	clear