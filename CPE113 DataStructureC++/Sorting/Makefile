GCC = g++
CFLAGS = -Wall -Werror -g
TARGET = Sort
OBJECT = main.o Sorting.o ../ArrayList/ArrayList.o

.SILENT:

all : $(OBJECT)
	$(GCC) $(OBJECT) -o $(TARGET) $(LIBS)
	./$(TARGET)

debug: $(OBJECT)
	$(GCC) $(OBJECT) -o $(TARGET) $(LIBS)
	gdb ./$(TARGET)

%.o : %.cpp
	$(GCC) $(CFLAGS) -c $< -o $@

clean :
	rm -f *.o $(TARGET)
	clear