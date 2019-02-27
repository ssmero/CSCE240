#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

// This is basically the sample program from 'cplusplus.com' but with some
// additional embellishments.

using namespace std;

int main () {

/*
*/
  std::ifstream is ("test.txt", std::ifstream::binary);
  if (is) {
    // get length of file:
    is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);

    cout << "length " << length << endl;

    char * buffer = new char [length];

    std::cout << "Reading " << length << " characters... ";
    // read data as a block:
    is.read (buffer,length);

    if (is)
      std::cout << "all characters read successfully." << endl;
    else
      std::cout << "error: only " << is.gcount() << " could be read" << endl;
    is.close();

    // ...buffer contains the entire file...

    cout << "char 0: " << buffer[0] << endl;
    cout << "char 1: " << buffer[1] << endl;
    cout << "char 2: " << buffer[2] << endl;
    cout << "char 3: " << buffer[3] << endl;

//    exit(0);

    int* intPtr;

    // first we "read" the first four bytes in the buffer
    // this cast allows us to change one kind of pointer into another 
    intPtr = reinterpret_cast<int*>(&buffer[0]);

    int theInt;
    int byte0, byte1, byte2, byte3;

    theInt = *intPtr;
    cout << theInt << endl;

    // now mod down and divide down so as to separate the four
    // bytes of the integer into four successive bytes.
    byte3 = theInt % 256;
    theInt = theInt / 256;
    byte2 = theInt % 256;
    theInt = theInt / 256;
    byte1 = theInt % 256;
    theInt = theInt / 256;
    byte0 = theInt % 256;
 
    cout << byte0 << " " << byte1 << " " << byte2 << " " << byte3 << " " << endl;

    // then we "read" the next four bytes in the buffer
    intPtr = reinterpret_cast<int*>(&buffer[4]);

    theInt = *intPtr;
    cout << theInt << endl;

    byte3 = theInt % 256;
    theInt = theInt / 256;
    byte2 = theInt % 256;
    theInt = theInt / 256;
    byte1 = theInt % 256;
    theInt = theInt / 256;
    byte0 = theInt % 256;
 
    cout << byte0 << " " << byte1 << " " << byte2 << " " << byte3 << " " << endl;


    delete[] buffer;
  }
  return 0;
}
