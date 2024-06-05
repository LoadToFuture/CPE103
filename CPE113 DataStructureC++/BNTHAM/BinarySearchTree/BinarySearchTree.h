#ifndef _BINARY_SEACRH_TREE_H_
#define _BINARY_SEACRH_TREE_H_

#include "../BinaryTreeNode/BinaryTreeNode.h"

class BinarySearchTree
{
public:
    BinaryTreeNode *root;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void add(int e);
    BinaryTreeNode *find(int e);
    void remove(int e);
    void deleteDegree(int degree, BinaryTreeNode *p);
    
    void display();

};

#endif
