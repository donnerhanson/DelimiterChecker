//================================================================
// Author      : Donner Hanson
// Date        : 03/26/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Delimiter Checker
// File Name   : GenStack.h
// Assignment  : Assignment 3
// Version     : 0.0
// Instructor  : Rene German
// Description : Template Stack
//================================================================

#ifndef GenStack_hpp
#define GenStack_hpp

#include <algorithm>
#include <iostream>
#include <stdexcept>

const unsigned int ARR_MAX = 10;

using namespace std;
template <typename T>
class GenStack{
public:
    GenStack() : sizeM(ARR_MAX), numElems (0) // default constructor
    {
        // initialize size of array
        internalArr = new T[sizeM];
    }
    GenStack(unsigned int sz) : sizeM(sz), numElems(0)
    {
        // initialize size of array
        internalArr = new T[sizeM];
    }
    ~GenStack()
    {
        delete [] internalArr;
    }
    void push(T val)
    {
        if (!isFull())
        {
            internalArr[++topElem] = val;
            numElems++;
        }
        else
        {
            resizeLarger();
            internalArr[++topElem] = val;
            numElems++;
        }
    }
    T pop()
    {
        try{
            if (isEmpty())
                throw runtime_error("Error: Can not pop from empty stack\n");
            else if (numElems < sizeM - ARR_MAX &&
                     sizeM - ARR_MAX - 1 > ARR_MAX + 1)
            {
                resizeSmaller();
            }
            numElems--;
            return internalArr[topElem--];
        }
        catch(runtime_error &e)
        {
            cout << e.what();
            throw e;
        }
    }
    T top() const // aka Peek
    {
        try{
            if (isEmpty())
                throw runtime_error("Error: No items in stack\n");
            return internalArr[topElem];
        }
        catch(runtime_error &e)
        {
            cout << e.what();
            throw e;
        }
    }
    bool isFull() const throw()
    {
        return (numElems == sizeM - 1);
    }
    bool isEmpty() const throw()
    {
        return (numElems == 0);
    }
    unsigned int getSize() const throw()
    {
        return numElems;
    }
    unsigned int getSizeM() const throw()
    {
        return sizeM;
    }
    
private:
    void resizeLarger()
    {
        // tempArr is + SIZE_M size
        T* tempArr = new T [sizeM + ARR_MAX];
        // copy elements from source, size source, into temp
        copy(internalArr, internalArr + sizeM, tempArr);
        // set size accessible to new size - 1
        sizeM += ARR_MAX - 1;
        // swap the two pointers
        swap(internalArr, tempArr);
        // delete the old array
        delete [] tempArr;
    }
    void resizeSmaller()
    {
        // tempArr is size numElems + 1
        T* tempArr = new T [numElems + 1];
        // copy elements from source, size source, into temp
        copy(internalArr, internalArr + numElems + 1, tempArr);
        // set size accessible to new size - 1
        sizeM = numElems;
        // swap the two pointers
        swap(internalArr, tempArr);
        // delete the old array
        delete [] tempArr;
    }
    unsigned int sizeM;
    int topElem;
    T* internalArr;
    int numElems;
};
#endif /* GenStack_hpp */
