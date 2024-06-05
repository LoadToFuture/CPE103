#include "BinaryTreeSearch.h"
#include <iostream>
#include <queue>
#include<iomanip>
using namespace std;
BinaryTreeSearch::BinaryTreeSearch()
{
    root = nullptr; // กำหนดให้ root เป็น nullptr เมื่อสร้างวัตถุ
}
BinaryTreeSearch::~BinaryTreeSearch()
{
}
void BinaryTreeSearch::insert(BinaryTreeNode *&root, int e)
{
    if (root == nullptr)
    {
        root = new BinaryTreeNode(e);
        cout << "Added " << e << " as root" << endl;
    }
    else if (e < root->element)
    {
        if (root->left == nullptr)
        {
            root->left = new BinaryTreeNode(e);
            cout << "Added " << e << " as left child of " << root->element << endl;
        }
        else
        {
            insert(root->left, e);
        }
    }
    else
    {
        if (root->right == nullptr)
        {
            root->right = new BinaryTreeNode(e);
            cout << "Added " << e << " as right child of " << root->element << endl;
        }
        else
        {
            insert(root->right, e);
        }
    }
}

void BinaryTreeSearch::remove(int e)
{
    removeHelper(root, e);
}

void BinaryTreeSearch::removeHelper(BinaryTreeNode *&root, int e)
{
    if (root == nullptr)
        return;
    if (e < root->element)
        removeHelper(root->left, e);
    else if (e > root->element)
        removeHelper(root->right, e);
    else
    {
        if (root->left == nullptr)
        {
            BinaryTreeNode *temp = root->right; //! delete left node 
            delete root;
            root = temp;
        }
        else if (root->right == nullptr)
        {
            BinaryTreeNode *temp = root->left; //! delete right
            delete root;
            root = temp;
        }
        else
        {
            BinaryTreeNode *maxLeft = findMax(root->left);
            root->element = maxLeft->element;
            removeHelper(root->left, maxLeft->element);
        }
    }
}

BinaryTreeNode *BinaryTreeSearch::findMax(BinaryTreeNode *p)
{
    while (p->right != nullptr)
    {
        p = p->right;
    }
    return p;
}
void printBST(BinaryTreeNode *node, BinaryTreeNode *root, string indent = "", bool last = true)
{
    cout << indent;
    if (node == root)
    {
        cout << " ROOT  "; // Blue
        indent += "       ";
    }
   
    else if (!last)
    {
        cout <<" L ---"; // Green
        indent += "|    ";
    }
    else
    {
        cout << " R ---"; // Red
        indent += "     ";
    }
    if (node != nullptr)
    {
        cout << "[" << node->element << "]" << endl;
        printBST(node->left, root, indent, false);
        printBST(node->right, root, indent, true);
    }
    else
    {
        cout << "[null]" << endl;
    }
}
void BinaryTreeSearch::displayBNT()
{
    printBST(root, root);
}
