//================================================================
// Author      : Donner Hanson
// Date        : 03/26/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Delimiter Checker
// File Name   : Processor.hpp
// Assignment  : Assignment 3
// Version     : 0.0
// Instructor  : Rene German
// Description : Processes string that contains delimiters and
//               Successfully fails program if delimiter syntax is
//               not correct (Interface of functions)
//================================================================

#ifndef Processor_hpp
#define Processor_hpp

#include <string>

#include "GenStack.h"

using namespace std;
class Processor
{
public:
    Processor(int numLines, string fullText):
        numLines(numLines), fullText(fullText){};
    ~Processor();
    void checkDelimiters();
    void throwClosingRunTimeErr(int currLine, int col,
                         char closingDelim, char openingDelim);
    void throwEmptyRunTimeErr(int currLine, int col,
                                char closingDelim);
private:
    // this holds opening delimiters
    GenStack<char> delimStack;
    // total number of lines
    int numLines;
    string fullText;
};

#endif /* Processor_hpp */
