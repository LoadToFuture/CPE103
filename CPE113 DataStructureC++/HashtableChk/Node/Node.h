#ifndef _NODE_H
#define _NODE_H
#include <string>
using namespace std;
class Node
{
public:
    string value;
    Node *next;

    // Constructor
    Node(string val) : value(val), next(nullptr) {}
};

#endif //_NODE_H