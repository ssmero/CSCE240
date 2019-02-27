#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

using namespace std;

int main () {

  std::ifstream is ("test.txt", std::ifstream::binary);
  if (is) {
    // get length of file:
    is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);

    cout << "length " << length << endl;

    char* buffer = new char [length];

    std::cout << "Reading " << length << " characters... " << endl;

    // this uses 'seekg' to move forward and backward in the file
    // unlike 'cin' and 'cout' we can position randomly into a file
    // and read as we wish.
    is.seekg(0, is.beg);
    is.read (buffer,1);
    cout << "char 0: " << buffer[0] << endl;

    is.seekg(2, is.beg);
    is.read (buffer,1);
    cout << "char 2: " << buffer[0] << endl;

    is.seekg(1, is.beg);
    is.read (buffer,1);
    cout << "char 1: " << buffer[0] << endl;

    delete[] buffer;
  }
  return 0;
}
