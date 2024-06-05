#ifndef _FASTARRAYQUQUE_H
#define _FASTARRAYQUQUQ_H

class FastArrayQueue
{
private:
    int *L;
    int maxSize;
    int curSize;
    int in;
    int out;

public:
    FastArrayQueue(int maxSize);
    ~FastArrayQueue();
    void UpdateMaxSize(int ModifyMaxSize);
    void enQueue(int e);                         //! done
    void append(int e) { enQueue(e); }           //! done
    int deQueueFront();                          //! done
    int removeFront() { return deQueueFront(); } //! done
    int deQueueRear();                           //! done
    int removeRear() { return deQueueRear(); }
    int front();                   //! done
    int head() { return front(); } //! done
    int rear();                    //! done
    int back() { return rear(); }; //! done
    //! aux
    int size();
    void display();

    bool isEmpty();
    void clear();
};

#endif //_FASTARRAYQUQUQ_H