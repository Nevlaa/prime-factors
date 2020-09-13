#ifndef PRIMESTACK_H_INCLUDED
#define PRIMESTACK_H_INCLUDED
#include<cmath>
#include<cassert>
#include<iostream>

#include"stackADT.h"

using namespace std;
//***************************************
//Definition of class template stackType:
//***************************************
template <class Type>
class stackType: public stackADT<Type>
{
public:
    const stackType<Type>& operator=(const stackType<Type>&);
    bool isEmptyStack() const;
    bool isFullStack() const;
    void initializeStack();
    void push(const Type& newItem);
    void primeFact(int num);
    Type top() const;
    void pop();
    stackType(int stackSize = 100);
      //Default constructor
      //Postcondition: stackTop = 0, maxStackSize = stackSize;
    stackType(const stackType<Type>& copyOfStack);
      //Copy constructor
    ~stackType();
      //Destructor
private:
    int maxStackSize;
    int stackTop;
    Type *list;

    void copyStack(const stackType<Type>& copyOfStack);
};

//*****************************************************
//Definitions of member functions are discussed here:
//*****************************************************
template <class Type>
void stackType<Type>::primeFact(int num)
{
    /*
    int n, i;
    n = num;

    if (n == 1)
    {
        cout<<"Smallest prime number is :: 2" << endl;
        break;
    }
     for(i = 2;i <= n;i++)
      {
        if ( n % i == 0)
        cout<<"The Entered Number "<< num <<" is NOT a prime number." << endl;
            break;
      }
        if (n == i)
        {
            cout<<"The Entered Number "<< num <<" is a prime number." << endl;
        }
*/
} /*End of primeFact()*/

template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}/*End of initializeStack()*/

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return(stackTop == 0);
}/*End of isEmptyStack()*/

template <class Type>
bool stackType<Type>::isFullStack() const
{
    return(stackTop == maxStackSize);
}/*End of isFullStack()*/

template <class Type>
void stackType<Type>::push(const Type& number)//checking for overflow
{
	if (!isFullStack())
    {
        list[stackTop] = number;
        stackTop++;
    }
    else
        cout << "Cannot add to a full stack." << endl;
}/*End of push()*/

template <class Type>
Type stackType<Type>::top() const
{
    assert(stackTop != 0);
    return list[stackTop - 1];
}/*End of top()*/

template <class Type>
void stackType<Type>::pop()//checking for underflow
{
	if (!isEmptyStack())
        stackTop--;
    else
        cout << "Cannot remove from an empty stack." << endl;
}/*End of pop()*/

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& copyOfStack)
{
    delete [] list;
    maxStackSize = copyOfStack.maxStackSize;
    stackTop = copyOfStack.stackTop;
    list = new Type[maxStackSize];

    for (int j = 0; j < stackTop; j++)
        list[j] = copyOfStack.list[j];
}/*End of copyStack()*/

template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {

        cout << "Size of the array to hold the stack must be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;

    stackTop = 0;
    list = new Type[maxStackSize];
}/*End of Constructor*/

template <class Type>
stackType<Type>::~stackType()
{
    delete [] list;
}/*End of Destructor*/

template <class Type>
stackType<Type>::stackType(const stackType<Type>& copyOfStack)
{
    list = NULL;
    copyStack(copyOfStack);
}/*end of copy Constructor*/

template <class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& copyOfStack)
{
    if (this != &copyOfStack)
        copyStack(copyOfStack);
    return *this;
}/*end of operator=*/
#endif
