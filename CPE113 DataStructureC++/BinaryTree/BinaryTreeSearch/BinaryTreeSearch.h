#ifndef _BINARYTREESEARCH_H
#define _BINARYTREESEARCH_H

#include "../BinaryTreeNode/BinaryTreeNode.h"

class BinaryTreeSearch
{
public:
    BinaryTreeNode *root;

public:
    BinaryTreeSearch(/* args */);
    ~BinaryTreeSearch();

    void insert(BinaryTreeNode *&root, int e);
   

    void remove(int e);
    void removeHelper(BinaryTreeNode *&root, int e);
    BinaryTreeNode *findMax(BinaryTreeNode *p);
  
     void displayBNT();
};

#endif //_BINARYTREESEARCHTREE_H