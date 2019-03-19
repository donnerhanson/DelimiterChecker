//================================================================
// Author      : Donner Hanson
// Date        : 03/26/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Delimiter Checker
// File Name   : Processor.cpp
// Assignment  : Assignment 3
// Version     : 0.0
// Instructor  : Rene German
// Description : Processes string that contains delimiters and
//               Successfully fails program if delimiter syntax is
//               not correct (Implementation of functions)
//================================================================

#include <stdexcept>
#include <sstream>
#include <string>

#include "Processor.hpp"

Processor::~Processor(){};

void Processor::checkDelimiters()
{
    int chNum(0);
    // returns the column number of the character
    int col(0);
    for (int currLine(0); currLine <= numLines; currLine++)
    {
        // reset col on line
        col = 0;
        // run through each line and check delimiters
        while(fullText.at(chNum) != '\n')
        {
            // if opening delimiter
            if (fullText.at(chNum) == '(' ||
                fullText.at(chNum) == '[' ||
                fullText.at(chNum) == '{' )
            {
                // push delim to stack
                delimStack.push(fullText.at(chNum));
            }
            // if closing delimiter and empty
            if ((fullText.at(chNum) == ')'  ||
                 fullText.at(chNum) == ']'  ||
                 fullText.at(chNum) == '}' )&&
                delimStack.isEmpty())
            {
                throwEmptyRunTimeErr(currLine, col, fullText.at(chNum));
            }
            // if a closing delimiter and stack is not empty
            if ((fullText.at(chNum) == ')'  ||
                 fullText.at(chNum) == ']'  ||
                 fullText.at(chNum) == '}') &&
                !delimStack.isEmpty())
            {
                char openingDelim;
                // check if the delimiter matches with the last
                // opening delimiter in the stack
                if (fullText.at(chNum) == ')')
                {
                    // check opening delim
                    openingDelim = delimStack.top();
                    if (openingDelim != '(')
                    {
                        char closingDelim = ')';
                        throwClosingRunTimeErr(currLine, col,
                                        closingDelim, openingDelim);
                    }
                    // matched up - remove opening delimiter
                    delimStack.pop();
                }
                if (fullText.at(chNum) == ']')
                {
                    openingDelim = delimStack.top();
                    if (openingDelim != '[')
                    {
                        char closingDelim = ']';
                        throwClosingRunTimeErr(currLine, col,
                                        closingDelim, openingDelim);
                    }
                    // matched up - remove opening delimiter
                    delimStack.pop();
                }
                if (fullText.at(chNum) == '}')
                {
                    openingDelim = delimStack.top();
                    if (openingDelim != '{')
                    {
                        char closingDelim = '}';
                        throwClosingRunTimeErr(currLine, col,
                                        closingDelim, openingDelim);
                    }
                    // matched up - remove opening delimiter
                    delimStack.pop();
                }
            }
            ++chNum;
            ++col;
        }
        // fullText at chNum = \n - pass by \n
        ++chNum;
    }
    // if full string has passed but the opening stack still has delims
    if (!delimStack.isEmpty())
    {
        cout << "Reached End of File:\n";
        char expectedClosing('\0');
        while (!delimStack.isEmpty())
        {
            
            if (delimStack.top() == '{')
                expectedClosing = '}';
            else if (delimStack.top() == '(')
                expectedClosing = ')';
            else if (delimStack.top() == '[')
                expectedClosing = ']';
            cout << "No closing delimiter for '"
            << delimStack.pop() << "'\n";
            cout << "Expected : '" << expectedClosing << "'\n";
        }
        throw runtime_error("");
    }
    else
    {
        cout << "Delimiters Matched\n";
    }
}

void Processor::throwClosingRunTimeErr(int currLine, int col,
                                char closingDelim, char openingDelim)
{
    string expectedClosing;
    if (closingDelim == ')' && openingDelim != '(')
    {
        if(openingDelim == '[')
        {
            expectedClosing = "]";
        }
        if(openingDelim == '{')
        {
            expectedClosing = "}";
        }
    }
    if (closingDelim == '}' && openingDelim != '{')
    {
        if(openingDelim == '(')
        {
            expectedClosing = ")";
        }
        if(openingDelim == '[')
        {
            expectedClosing = "]";
        }
    }
    if (closingDelim == ']' && openingDelim != '[')
    {
        
        if(openingDelim == '(')
        {
            expectedClosing = ")";
        }
        if(openingDelim == '{')
        {
            expectedClosing = "}";
        }
    }
        string delimErrChar;
        delimErrChar += closingDelim;
        // get currLine as string
        std::stringstream ss;
        ss << ++currLine;
        string currLineStr(ss.str());
        ss.str("");
        ss << col;
        string currCol(ss.str());
        ss.str("");
        throw runtime_error("Error: Expected '" +
                            expectedClosing +
                            "' on line : " +
                            currLineStr +
                            " column : " +
                            currCol +
                            ", but found: '"
                            + delimErrChar +
                            "' instead.\n");
    
}

void Processor::throwEmptyRunTimeErr(int currLine, int col, char closingDelim)
{
    string delimErrChar;
    delimErrChar += closingDelim;
    // get int currLine as string
    stringstream ss;
    ss << ++currLine;
    string currLineStr(ss.str());
    ss.str("");
    // get int currCol as string
    ss << col;
    string currCol(ss.str());
    ss.str("");
    // throw error
    throw runtime_error("Error: no opening delimiter "
                        "for '"
                        + delimErrChar +  "' on line : "
                        + currLineStr + ", col : "
                        + currCol +".\n");
}
