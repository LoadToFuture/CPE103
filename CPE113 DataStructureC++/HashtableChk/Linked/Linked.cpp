#include "Linked.h"
#include <iostream>
using namespace std;

Linked::~Linked()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
}
// Function to add a value to the end of the linked list
void Linked ::add(string value)
{
    if (head == nullptr)
    {
        head = new Node(value);
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node(value);
    }
}
bool Linked::search(string value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return true; // พบค่าที่ต้องการค้นหา
        }
        current = current->next;
    }
    return false; // ไม่พบค่าที่ต้องการค้นหาหา
}

// Function to display the linked list
void Linked::display()
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
}
