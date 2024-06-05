#ifndef _BINARY_TREE_NODE_H_
#define _BINARY_TREE_NODE_H_

#include <iostream>

class BinaryTreeNode
{
public:
    int element;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int element = 0, BinaryTreeNode *left = nullptr, BinaryTreeNode *right = nullptr);
};

#endif
