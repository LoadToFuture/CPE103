GCC = g++
CFLAGS = -Wall -Werror -g
TARGET = main
OBJECT = main.o BinarySearchTree/BinarySearchTree.o BinaryTreeNode/BinaryTreeNode.o
.SILENT:

all : $(OBJECT)
	$(GCC) $(OBJECT) -o $(TARGET)
	./$(TARGET) 

debug: $(OBJECT)
	$(GCC) $(OBJECT) $(CFLAGS) -o $(TARGET)
	gdb ./$(TARGET)

%.o : %.cpp
	$(GCC) -c $< -o $@

clean :
	rm -f *.o */*.o */*/*.o $(TARGET)
	clear