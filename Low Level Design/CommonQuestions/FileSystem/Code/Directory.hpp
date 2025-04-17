#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include "FileSystem.hpp"
#include <bits/stdc++.h>
using namespace std;

class FileSystem;

class Directory : public FileSystem{
    public:
        string directoryName;
        vector<FileSystem*> files;

        Directory(string name)
        {
            this->directoryName = name;
            this->files = vector<FileSystem*>();
        }

        void add(FileSystem* file) 
        {
            this->files.push_back(file);
        }

        void ls() override
        {
            cout << "Directory name : " << this->directoryName << endl;

            for(auto file : files)
            {
                file->ls();
            }
        }
};

#endif