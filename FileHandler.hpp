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
// Description : header functions interface to open file safely
//================================================================

#ifndef FileHandler_hpp
#define FileHandler_hpp

#include <fstream>
#include <iostream>
#include <string>


using namespace std;

class FileHandler{
public:
    bool SafeOpenRead(ifstream& inFile, string fileName);
    bool fileIsBlank(ifstream& inFile);
    bool isNotWS(const string &str);
    fstream& SafeOpenOutput(fstream& inFile, string fileName);
    string GetInFileName();
private:
};

#endif /* FileHandler_hpp */


