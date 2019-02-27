#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

using namespace std;

int main () {

  std::ofstream output_stream ("znewbinary.txt", std::ofstream::binary);

  int arr[4];
  arr[0] =  4*256*256*256 +  3*256*256 +  2*256 +  1;
  arr[1] =  8*256*256*256 +  7*256*256 +  6*256 +  5;
  arr[2] = 12*256*256*256 + 11*256*256 + 10*256 +  9;
  arr[3] = 16*256*256*256 + 15*256*256 + 14*256 + 13;

  char* char_ptr = reinterpret_cast<char*>(&arr[0]);
  output_stream.write(char_ptr, 16);
  output_stream.close();

  FILE *fp = fopen("znewbinary.txt", "r");
  char c;
  while ( (c = getc(fp)) != EOF) {
    printf("%0x", c);
  }
  printf("\n");

  return 0;
}
