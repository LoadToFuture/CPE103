#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#define DEFAULT_MAX_SIZE 5

class ArrayList
{
private:
    int *L;
    int maxSize;
    int curSize;
public:
    ArrayList(int maxSize = DEFAULT_MAX_SIZE);
    ~ArrayList();
    int size();
    int indexOf(int e);
    int get(int i);
    int remove(int i);
    void set(int i, int e);
    void add(int i, int e);
    void display();
    int CurSize;

    void setMaxsize(int i);
    int CheckSize(int i);

    int maxVal();
    int minVal();
    void clear();
    bool isEmpty();
    void removelast(int limit);
    void removefirst(int limit);
};
#endif