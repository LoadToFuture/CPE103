#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include "ArrayStack.h"
#include <vector>
#include <string>

vector<char> operators;
vector<string> operands;
using namespace std;
ArrayStack::ArrayStack(int MaxSize) : ArrayList(MaxSize)
{
    this->maxSize = MaxSize; // call parent constructor , L,CUrsize ,MaxSize
}
void ArrayStack::UpdateMaxSize(int newMaxsize)
{
    clearArray();
    maxSize = newMaxsize;
}
void ArrayStack::push(int e)
{
    if (size() == maxSize)
    {
        cerr << "Error List FULL!!\n";
        return;
    }
    add(size(), e);
}
int ArrayStack::pop()
{
    if (isEmpty())
    {
        return -1;
    }
    return remove(size() - 1);
}
bool ArrayStack::isOperand(char c)
{
    return (c >= '0' && c <= '9');
}

int ArrayStack::top()
{
    return get(size() - 1);
}

bool ArrayStack::isEmpty()
{
    return size() == 0;
}
bool ArrayStack::isFull()
{
    return size() == getMaxSize();
}
void ArrayStack::Stackdisplay()
{
    if (size() == 0)
    {
        for (int i = 0; i < 5; i++)
            cout << " [" << i << ":0]";
        cout << "  ..........[" << maxSize << ":0]";
        cout << "\033[1;33m\n\n+-------------------------------------------------------------------------------------------------------------+\n\033[0m\n";
        return;
    }
    int maxIndexWidth = floor(log10(maxSize)) + 1;
    int numRows = size() / 10;
    if (size() % 10 != 0)
        numRows++;
    for (int i = 9; i >= 0; i--)
    {
        for (int row = numRows - 1; row >= 0; row--)
        {
            int index = row * 10 + i;
            if (index >= size())
            {
                cout << setw(maxIndexWidth) << "[" << index << ": " << setw(4) << "0]";
            }
            else
            {
                cout << setw(maxIndexWidth) << "[" << index << ": " << setw(3) << get(index) << "]";
            }
        }
        cout << endl;
    }
    cout << "\033[1;33m\n\n+-------------------------------------------------------------------------------------------------------------+\n\033[0m\n";
}
bool ArrayStack::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'); //! check operater
}
int ArrayStack::precedence(char op) //! Priority is Operater
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return 0; //! isnot Operater not
}
string ArrayStack::infixToPrefix(string infix) {
    string prefix;
    stack<char> operatorStack;

    for (int i = infix.length() - 1; i >= 0; i--) {
        if (infix[i] == ' ') continue;

        if (isdigit(infix[i])) {
            string operand;
            while (i >= 0 && isdigit(infix[i])) {
                operand = infix[i] + operand;
                i--;
            }
            i++; // Adjust index after decrement in loop
            operands.push_back(operand);
            prefix += " " + operand + " "; // Add operand to prefix with space separator
        }

        else if (infix[i] == ')') {
            operatorStack.push(infix[i]);
        }

        else if (infix[i] == '(') {
            while (!operatorStack.empty() && operatorStack.top() != ')') {
                prefix += operatorStack.top(); // Add operator to prefix
                operatorStack.pop();
            }
            if (!operatorStack.empty()) operatorStack.pop(); // Pop ')'
        }

        else {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(infix[i])) {
                prefix += operatorStack.top(); // Add operator to prefix
                operatorStack.pop();
            }
            operatorStack.push(infix[i]);
        }
    }

    while (!operatorStack.empty()) {
        prefix += operatorStack.top(); // Add remaining operators to prefix
        operatorStack.pop();
    }

    reverse(prefix.begin(), prefix.end()); // Reverse the prefix expression
    return prefix;
}
void ArrayStack::displayPrefixVertical(string postfix)
{
    cout << "\n";
    cout << "\033[1;33m";
    cout << "  - Prefix -" << endl
         << endl;
    cout << "\033[0m";

    cout << "[ ";
    for (char c : postfix)
    {
        if (c == ' ')
        {
            cout << "";
        }
        else
        {
            cout << c << " ";
        }
    }
    cout << " ]\n\n";
}
string ArrayStack::infixToPostfix(string infix)
{
  string postfix;
 string operatorStack;

    for (char c : infix) {
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            operatorStack += c;
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.back() != '(') {
                postfix += ' ';
                postfix += operatorStack.back();
                operatorStack.pop_back();
            }
            if (!operatorStack.empty())
                operatorStack.pop_back(); // Pop '('
        } else {
            postfix += ' ';
            while (!operatorStack.empty() && (precedence(operatorStack.back()) > precedence(c) || (precedence(operatorStack.back()) == precedence(c) && c != '^'))) {
                postfix += operatorStack.back();
                postfix += ' ';
                operatorStack.pop_back();
            }
            operatorStack += c;
        }
    }

    while (!operatorStack.empty()) {
        postfix += ' ';
        postfix += operatorStack.back();
        operatorStack.pop_back();
    }

    return postfix;
}
double ArrayStack ::calculate(double a, double b, char op) //! calculator
{
    switch (op)
    {
    case '+':
        return b + a;
    case '-':
        return b - a;
    case '*':
        return b * a;
    case '/':
        return b / a;
    case '^':
        return pow(b, a);
    default:
        return 0;
    }
}
double ArrayStack::postfixCalcutation(string postfix)
{
    stringstream SSP(postfix);
    string token;
    while (getline(SSP, token, ' '))
    {
        if (isdigit(token[0]))
        {
            operandStack.push(stoi(token));
        }
        else
        {
            int a = operandStack.top();
            operandStack.pop();
            int b = operandStack.top();
            operandStack.pop();
            operandStack.push(calculate(a, b, token[0]));
        }
    }
    return operandStack.top();
}

void ArrayStack::displayPostfixVertical(string postfix)
{
    cout << "\n";
    cout << "\033[1;33m";
    cout << "  - Postfix -" << endl
         << endl;
    cout << "\033[0m";
    cout << "[ ";
    for (char c : postfix)
    {
        if (c == ' ')
        {
            cout << "";
        }
        else
        {
            cout << c << " ";
        }
    }
    cout << " ]\n\n";
}

void ArrayStack::displayConversionSteps(string infix)
{
    cout << endl;
    cout << "\033[1;33m";
    cout << "Input String\tOutput Stack\tOperator Stack\n";
    cout << "\033[0m";
    cout << endl;
    stack<char> outputStack;
    stack<char> operatorStack;

    for (char c : infix)
    {
        // Display current step
        cout << infix << "\t\t";

        // Display output stack
        if (outputStack.empty())
            cout << "\t\t";
        else
        {
            stack<char> tempStack = outputStack;
            while (!tempStack.empty())
            {
                cout << tempStack.top() << " ";
                tempStack.pop();
            }
            cout << "\t\t";
        }

        // Display operator stack
        if (operatorStack.empty())
            cout << "\t\t";
        else
        {
            stack<char> tempStack = operatorStack;
            while (!tempStack.empty())
            {
                cout << tempStack.top() << " ";
                tempStack.pop();
            }
        }

        cout << endl;

        // Perform conversion
        if (isdigit(c))
        {
            outputStack.push(c);
        }
        else if (c == '(')
        {
            operatorStack.push(c);
        }
        else if (c == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                outputStack.push(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop '('
        }
        else
        {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c))
            {
                outputStack.push(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }
    // Empty remaining operators from operator stack to output stack
    while (!operatorStack.empty())
    {
        outputStack.push(operatorStack.top());
        operatorStack.pop();
    }
    // Display the final step
    cout << infix << "\t\t";
    if (outputStack.empty())
        cout << "\t\t";
    else
    {
        stack<char> tempStack;
        while (!outputStack.empty())
        {
            tempStack.push(outputStack.top());
            outputStack.pop();
        }
        while (!tempStack.empty())
        {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << "\t\t";
    }
    cout << endl;
}
