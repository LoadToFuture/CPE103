#ifndef _HASH_TABLE
#define _HASH_TABLE

class Hashtable
{
private:
    int *L;
    int tableSize;
    int curSize;
    int hash_key;
    float loadFacter;
    void hashfunction(int key);

public:
    Hashtable(int _tableSize);
    ~Hashtable();

    void insert(int value);
    void display();
    void rehasting();
    int getData(int key);
   void deleteByIndex(int index);

    //! aux
    void clear();
    void loadFacterConfig(float loadFac);
    void UpdateMaxSize(int UpdateMaxSize);
};

#endif //_HASH_TABLE