//================================================================
// Author      : Donner Hanson
// Date        : 03/26/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Delimiter Checker
// File Name   : main.cpp
// Assignment  : Assignment 3
// Version     : 0.0
// Instructor  : Rene German
// Description : main
//================================================================

#include <stdexcept>
#include <iostream>
#include <sstream>

#include "FileHandler.hpp"
#include "GenStack.h"
#include "Processor.hpp"

using namespace std;

/***********************************************************/
/*              FUNCTION DECLARATIONS BEGIN                */
/***********************************************************/

bool askContinue();

/***********************************************************/
/*              FUNCTION DECLARATIONS END                  */
/***********************************************************/
/***********************************************************/
/*                      MAIN BEGIN                         */
/***********************************************************/

const string ASK_CONT_Y_N = "Check another file?... (Y/N)\n";


int main(int argc, const char * argv[]) {
    try{
        if (argc <= 1)
        {
            throw invalid_argument("Not enough arguments passed.");
        }
        if (argc > 2)
        {
            throw invalid_argument("Too many arguments passed.");
        }
        bool contProgram(true), passes(false);
        while (contProgram)
        {
            FileHandler* fh = new FileHandler();
            string fileName;
            if (!passes)
                fileName = argv[1];
            else
                fileName = fh->GetInFileName();
            
            bool fOpenSuccess = false;
            // input file
            ifstream inFile;
            // tracks number of lines in file
            int numLines(0);
            if ((fOpenSuccess = fh->SafeOpenRead(inFile, fileName)))
            {
                // this holds opening delimiters
                GenStack<char> delimStack;
                string fullText("");
                string line;
                // while stream is good
                while(inFile)
                {
                    getline(inFile, line);
                    // insert delimiting endline for processing
                    fullText+=(line+'\n');
                    // if eof flagged
                    if(inFile.eof())
                    {
                        break;
                    }
                    numLines++;
                }
                Processor* pPtr = new Processor(numLines, fullText);
                // will throw error and exit if delims not matched
                pPtr->checkDelimiters();
                //cout << "Delimiters Matched\n";
                delete  pPtr;
                inFile.close();
            }
            else
            {
                cout << "error opening file: " << fileName << "\n";
            }
            
            delete fh;
            // ask user to continue
            contProgram = askContinue();
            if (contProgram)
                passes = true;
        }
    }
    catch (runtime_error &e)
    {
        cout << e.what() << "Exiting...\n";
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << "Exiting....\n";
    }
    catch (...)
    {
        cout << "Unhandled exception... \nExiting...\n";
    }
    return 0;
}

/***********************************************************/
/*                      MAIN END                           */
/***********************************************************/
/***********************************************************/
/*              FUNCTION DEFINITIONS BEGIN                 */
/***********************************************************/


bool askContinue()
{
    string input;
    // clear in stream
    cin.sync();
    cout << ASK_CONT_Y_N;
    getline(cin, input);
    bool cont(false);
    while (toupper(input[0]) != 'Y' && toupper(input[0]) != 'N')
    {
        cin.sync();
        cout << ASK_CONT_Y_N;
        getline(cin, input);
    }
    switch (toupper(input[0]))
    {
        case 'Y':
            cont = true;
            break;
        default:
            break;
    }
    return cont;
}


/***********************************************************/
/*              FUNCTION DEFINITIONS END                   */
/***********************************************************/
