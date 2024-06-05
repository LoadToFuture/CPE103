#ifndef _BINARYTREENODE_
#define _BINARYTREENODE_
#include <iostream>
 
class BinaryTreeNode
{
public:
   int element ;
   BinaryTreeNode *left;
   BinaryTreeNode *right; 
public:
//!constructors
    BinaryTreeNode(int element = 0,BinaryTreeNode *left = NULL,BinaryTreeNode *right =NULL);
  //  ~BinaryTreeNode();
  
};




#endif //_BINARYTREENODE_