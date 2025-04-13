#ifndef FILE_HPP
#define FILE_HPP

#include "FileSystem.hpp"
#include <bits/stdc++.h>
using namespace std;

class FileSystem;

class File : public FileSystem{
    public:
        string fileName;

        File(string name)
        {
            this->fileName = name;
        }

        void ls() override
        {
            cout << "File name : " << this->fileName << endl;
        }
};


#endif