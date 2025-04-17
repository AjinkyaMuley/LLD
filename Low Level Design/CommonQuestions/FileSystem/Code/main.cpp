#include "Directory.hpp"
#include "File.hpp"
#include "FileSystem.hpp"

#include<bits/stdc++.h>
using namespace std;

class FileSystem;
class Directory;
class File;

int main()
{

    Directory* movieDirectory = new Directory("Movie");

    FileSystem* border = new File("Border");
    movieDirectory->add(border);

    Directory* comedyMovieDirectory = new Directory("ComedyMovie");
    File* hulchul = new File("Hulchul");
    comedyMovieDirectory->add(hulchul);
    movieDirectory->add(comedyMovieDirectory);

    movieDirectory->ls();

    return 0;   
}