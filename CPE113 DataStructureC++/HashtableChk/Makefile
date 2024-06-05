GCC = g++
CFLAGS = -Wall -Werror -g
TARGET = main
OBJECT = main.o hashtablechk.o Linked/Linked.o Node/Node.o ../ChainNode/ChainNode.o

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
	rm -f *.o hashtablechk.o Linked/Linked.o Node/Node.o ../ChainNode/ChainNode.o $(TARGET)
	clear