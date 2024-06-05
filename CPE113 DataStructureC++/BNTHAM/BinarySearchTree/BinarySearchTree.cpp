#include "BinarySearchTree.h"
#include <iostream>
#include <iomanip>
using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    // You need to implement destructor if necessary
}
BinaryTreeNode *findMax(BinaryTreeNode *node)
{
    // ตรวจสอบว่าโหนดที่รับเข้ามาเป็น nullptr หรือไม่
    if (node == nullptr)
        return nullptr;

    // วนลูปไปที่โหนดทางขวาสุดของต้นไม้
    while (node->right != nullptr)
        node = node->right;

    // คืนค่าโหนดทางขวาสุดของต้นไม้
    return node;
}
BinaryTreeNode *findParent(BinaryTreeNode *node, BinaryTreeNode *child)
{
    // ถ้าโหนดเป็น nullptr หรือโหนดเท่ากับโหนดลูก ให้คืนค่า nullptr
    if (node == nullptr || node == child)
    {
        return nullptr;
    }

    // ถ้าโหนดลูกทางซ้ายหรือขวาของโหนดปัจจุบันคือโหนดลูก ให้คืนค่าโหนดปัจจุบัน
    if (node->left == child || node->right == child)
    {
        return node;
    }
    // ถ้าค่าของโหนดลูกน้อยกว่าค่าของโหนดปัจจุบัน ให้ค้นหาในต้นไม้ย่อยทางซ้าย
    if (child->element < node->element)
    {
        return findParent(node->left, child);
    }
    // ถ้าค่าของโหนดลูกมากกว่าหรือเท่ากับค่าของโหนดปัจจุบัน ให้ค้นหาในต้นไม้ย่อยทางขวา
    else
    {
        return findParent(node->right, child);
    }
    // สุดท้ายคืนค่าโหนดที่เป็นโหนดก่อนโหนดที่จะโดนลบ
}
void insert(BinaryTreeNode *&root, int e)
{
    // ถ้าโหนดRootเป็น nullptr ให้สร้างโหนดใหม่
    if (root == nullptr)
    {
        root = new BinaryTreeNode(e);
    }
    // ถ้าค่าที่ต้องการแทรกน้อยกว่าค่าของโหนดRoot
    else if (e < root->element)
    {
        // ถ้าโหนดลูกทางซ้ายของโหนดRootเป็น nullptr ให้แทรกโหนดใหม่เป็นโหนดลูกทางซ้าย
        if (root->left == nullptr)
        {
            root->left = new BinaryTreeNode(e);
        }
        // ถ้าโหนดลูกทางซ้ายของโหนดRootไม่เป็น nullptr ให้ทำการเรียกฟังก์ชัน insert ในต้นไม้ย่อยทางซ้าย
        else
        {
            insert(root->left, e); // recursive function
        }
    }
    // ถ้าค่าที่ต้องการแทรกมากกว่าหรือเท่ากับค่าของโหนดRoot
    else
    {
        // ถ้าโหนดลูกทางขวาของโหนดRootเป็น nullptr ให้แทรกโหนดใหม่เป็นโหนดลูกทางขวา
        if (root->right == nullptr)
        {
            root->right = new BinaryTreeNode(e);
        }
        // ถ้าโหนดลูกทางขวาของโหนดRootไม่เป็น nullptr ให้ทำการเรียกฟังก์ชัน insert ในต้นไม้ย่อยทางขวา
        else
        {
            insert(root->right, e);
        }
    }
}

void BinarySearchTree::add(int e)
{
    insert(root, e);
}

BinaryTreeNode *BinarySearchTree::find(int e)
{
    // เริ่มต้นการค้นหาที่โหนดราก
    BinaryTreeNode *current = root;

    // วนลูปจนกว่าจะค้นพบโหนดที่มีค่าเท่ากับค่าที่ต้องการหรือพบว่าต้นไม้ว่าง
    while (current != nullptr && e != current->element)
    {
        // ถ้าค่าที่ต้องการค้นหาน้อยกว่าค่าของโหนดปัจจุบัน
        if (e < current->element)
        {
            // ค้นหาในต้นไม้ย่อยทางซ้าย
            current = current->left;
        }
        // ถ้าค่าที่ต้องการค้นหามากกว่าค่าของโหนดปัจจุบัน
        else if (e > current->element)
        {
            // ค้นหาในต้นไม้ย่อยทางขวา
            current = current->right;
        }
        // ถ้าค่าที่ต้องการค้นหาเท่ากับค่าของโหนดปัจจุบัน
        else
        {
            // คืนค่าโหนดปัจจุบัน
            return current;
        }
    }
    // คืนค่าโหนดปัจจุบัน (โหนดที่ไม่พบหรือต้นไม้ว่าง)
    return current;
}

void BinarySearchTree::remove(int e)
{
    // ค้นหาโหนดที่ต้องการลบ
    BinaryTreeNode *current = find(e);

    // ถ้าพบโหนดที่ต้องการลบ
    if (current != nullptr)
    {
        // หากโหนดที่ต้องการลบไม่มีโหนดลูกทั้งสองข้าง
        if (current->left == nullptr && current->right == nullptr)
        {
            // ลบโหนดที่มีดีกรีเป็น 0 (ไม่มีโหนดลูก)
            deleteDegree(0, current);
        }
        // หากโหนดที่ต้องการลบมีโหนดลูกทั้งสองข้าง
        else if (current->left != nullptr && current->right != nullptr)
        {
            // ลบโหนดที่มีดีกรีเป็น 2 (มีโหนดลูกสองข้าง)
            deleteDegree(2, current);
        }
        // หากโหนดที่ต้องการลบมีโหนดลูกที่ด้านซ้ายหรือด้านขวาเท่านั้น
        else
        {
            // ลบโหนดที่มีดีกรีเป็น 1 (มีโหนดลูกด้านซ้ายหรือด้านขวาเท่านั้น)
            deleteDegree(1, current);
        }
    }
}

void BinarySearchTree::deleteDegree(int degree, BinaryTreeNode *p)
{
    if (degree == 0)
    {
        if (p == root) // ถ้าโหนดที่ต้องการลบคือโหนดราก
        {
            delete root;
            root = nullptr;
        }
        else
        {
            // หาโหนดบ่งบอกของโหนดที่ต้องการลบ
            BinaryTreeNode *parent = findParent(root, p);
            // กำหนดโหนดลูกของโหนดบ่งบอกให้เป็น nullptr
            if (parent->left == p)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
            delete p;
        }
    }
    else if (degree == 1)
    {
        // เลือกโหนดลูกที่ไม่ใช่ nullptr
        BinaryTreeNode *child = (p->left != nullptr) ? p->left : p->right;

        if (p == root) // ถ้าโหนดที่ต้องการลบคือโหนดราก
        {
            root = child;
        }
        else
        {
            // หาโหนดบ่งบอกของโหนดที่ต้องการลบ
            BinaryTreeNode *parent = findParent(root, p);
            // เชื่อมโหนดลูกของโหนดบ่งบอกเข้ากับโหนดบ่งบอกของโหนดที่ต้องการลบ
            if (parent->left == p)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }
        delete p;
    }
    else if (degree == 2)
    {
        // ค้นหาโหนดที่มีค่ามากที่สุดในต้นไม้ย่อยทางซ้าย
        BinaryTreeNode *maxInLeft = findMax(p->left);
        // หาโหนดก่อนโหลดที่มากที่สุดในฝั่งซ้าย
        BinaryTreeNode *parentOfMaxInLeft = findParent(root, maxInLeft);

        // เปลี่ยนค่าของ P ให้เป็นค่าที่มากที่สุดในฝั่งซ้าย
        p->element = maxInLeft->element;
        
         // เช็คว่าโหนดที่มากที่สุดในฝั่งซ้ายมีโหนดลูกหรือไม่
        if (parentOfMaxInLeft->left == maxInLeft)
        {
            parentOfMaxInLeft->left = maxInLeft->left;
        }
        else
        {
            parentOfMaxInLeft->right = maxInLeft->left;
        }
        // ลบโหนดที่มากที่สุดในฝั่งซ้าย
        delete maxInLeft;
    }
}

void printBST(BinaryTreeNode *node, BinaryTreeNode *root, string indent = "", bool last = true)
{
    cout << indent;
    if (node == root)
    {
        cout << "\033[1;34mROOT \033[0m"; // Blue
        indent += "       ";
    }
    else if (last)
    {
        cout << "\033[1;31mR\033[0m---"; // Red
        indent += "     ";
    }
    else
    {
        cout << "\033[1;32mL\033[0m---"; // Green
        indent += "|    ";
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

void BinarySearchTree::display()
{
    printBST(root, root);
}