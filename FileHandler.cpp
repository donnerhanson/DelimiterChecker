//================================================================
// Author      : Donner Hanson
// Date        : 03/26/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Delimiter Checker
// File Name   : FileHandler.cpp
// Assignment  : Assignment 3
// Version     : 0.0
// Instructor  : Rene German
// Description : functions to open file safely
//================================================================

#include <iostream>
#include <fstream>
#include <string>

#include "FileHandler.hpp"

using namespace std;

const string ASK_FILE = "Enter file path....\n";


bool FileHandler::SafeOpenRead(ifstream& inFile, string fileName)
{
    inFile.open(fileName, ios::in);
    
    if(inFile.is_open() && !fileIsBlank(inFile))
    {
        cout << "File: <" << fileName << ">\nOpened successfully...\n";
        return true;
    }
    return false;
}
fstream& FileHandler::SafeOpenOutput(fstream& outFile, string fileName)
{
    outFile.open(fileName, ios::out);
    
    if(outFile.is_open())
    {
        cout << "File: " << fileName << " opened successfully...\n";
        
    }
    else
        cout << "Failed to open file or file was empty!\n";
    return outFile;
}

bool FileHandler::fileIsBlank(ifstream& inFile)
{
    return inFile.peek() == ifstream::traits_type::eof();
}

bool FileHandler::isNotWS(const string &str)
{
    return str.find_first_not_of(' ') != string::npos;
}

string FileHandler::GetInFileName()
{
    string fileName;
    cout << ASK_FILE;
    getline(cin, fileName);
    // if the filename is greater than zero
    // if user dragged file sometimes there is
    // ending whitespace in string
    //fileName = TEST_FILE_IN;
    if (fileName.size() > 0 && isNotWS(fileName))
    {
        while(fileName.at(fileName.size()-1) == '\n' ||
              fileName.at(fileName.size()-1) == ' ')
        {
            // remove ending whitespace
            fileName.pop_back();
        }
    }
    return fileName;
}

