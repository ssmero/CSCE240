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
    // read data as a block:
    is.read (buffer,4);

    // this basically shows that we can output the hex one byte at
    // a time and thus determine what's in the array of bytes and
    // in what order.
    unsigned int zuzu0 = static_cast<unsigned int>(*buffer);
    printf("zuzu0: %08x\n", zuzu0);

    unsigned int zuzu1 = static_cast<unsigned int>(*buffer+1);
    printf("zuzu1: %08x\n", zuzu1);

    unsigned int zuzu2 = static_cast<unsigned int>(*buffer+2);
    printf("zuzu2: %08x\n", zuzu2);

    unsigned int zuzu3 = static_cast<unsigned int>(*buffer+3);
    printf("zuzu3: %08x\n", zuzu3);

    int integer1 = zuzu0*256*256*256 + zuzu1*256*256 + zuzu2*256 + zuzu3;
    printf("integer1: %08x\n", integer1);

    int integer2 = *(reinterpret_cast<int*>(buffer));
    printf("integer2: %08x\n", integer2);

    char* char_ptr = reinterpret_cast<char*>(&integer1);
//    char x = *char_ptr;
//    printf("int_to_char: %08x\n", x);
    printf("int_to_char0: %08x\n", *(char_ptr  ));
    printf("int_to_char1: %08x\n", *(char_ptr+1));
    printf("int_to_char2: %08x\n", *(char_ptr+2));
    printf("int_to_char3: %08x\n", *(char_ptr+3));

//    exit(0);
  }
  return 0;
}
