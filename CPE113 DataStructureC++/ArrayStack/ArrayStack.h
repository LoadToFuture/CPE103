#ifndef _ARRAYSTACK_H_
#define _ARRAYSTRCK_H_
#include "../ArrayList/ArrayList.h"
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
class ArrayStack : public ArrayList
{
private: // access L ANd CurSize  (via methods)
    int maxSize;
    stack<int> operandStack;

public:
    ArrayStack(int MaxSize);
    // ~ArrayStack();
    void UpdateMaxSize(int newMaxsize); //! done
    void push(int e);                   //! done
    int pop();                          //! done
    int top();                          //! done
    int peek() { return top(); }        //! done
    bool isEmpty();                     //! done
    bool isFull();                      //! done
    void Stackdisplay();                //! done
     // void swapLastAndBeforLast();    //!done

    bool isOperator(char c);                       //! done
    int precedence(char op);                       //! done
    string infixToPrefix(string infix);            //! done  
    string infixToPostfix(string infix);           //! done
    bool isOperand(char c);                        //! done
    double calculate(double a, double b, char op); //! done
    double postfixCalcutation(string postfix);     //! done

    //! display --
    void displayPostfixVertical(string postfix);   //! done
    void displayPrefixVertical(string postfix);    //! done
    void displayConversionSteps(string infix);     //! done
};

#endif //_ARRAYSTRCK_H_