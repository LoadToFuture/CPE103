#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "../ChainNode/ChainNode.h" //re-use
#include "../Node/Node.h" //re-use
class LinkedList
{
private:
    /* data */
    int curSize;
    int maxSize;
    ChainNode *firstNode;

public:
    LinkedList(int maxSize);
    ~LinkedList();
    void add(int i, int e);                //! done
    void UpdateMaxSize(int UpdateMaxsize); //! done
    int size();                            //! done
    int indexOf(int e);                    //! done
    int get(int i);                        //! done
    int remove(int i);                     //! done
    void removeFirst(int index);           //! done
    void removeValue(int Value);           //! done
    void removeLast(int index);            //! done
    void set(int i, int e);                //! done
    //! Aux .function
    void display();
    //! Other
    int max();              //! done
    int min();              //! done
    int oddCount();         //! done
    int EvenCount();        //! done
    double sum();           //! done
    double Average();       //! done
    void sortvalue(char c); //! done
    void clearList();       //! done
};

#endif //  _LINKEDLIST_H_