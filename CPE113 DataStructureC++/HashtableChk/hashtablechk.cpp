#include "hashtablechk.h"
#include <iostream>
using namespace std;

hashtablechk::hashtablechk(int _tableSize) : tableSize(_tableSize) {
    L = new Linked[tableSize];
}
// Destructor
hashtablechk::~hashtablechk() {
    delete[] L;
}
void hashtablechk::add(string value )
{
 
    char firstChar = value[0];

    if (islower(firstChar)) {
        firstChar = toupper(firstChar);
    }

    int index = firstChar - 'A';

    // Check if the word already exists in the linked list
    if (L[index].search(value)) {
        cout << "Value already exists: " << value << endl;
        return;
    }
    // If the word is not a duplicate, add it to the linked list
    L[index].add(value);
    
}

void hashtablechk::display()
{
    cout << "+----------------------------------+" << endl;
    for (int i = 0; i < tableSize; ++i)
    {
        cout << "| " << (char)('A' + i) << " : " ;
        L[i].display();
        cout << endl;
    }
    cout << "+----------------------------------+" << endl;
}
