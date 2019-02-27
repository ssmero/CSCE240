#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

using namespace std;

int main ()
{

  std::ofstream output ("rawbinary.txt", std::ofstream::binary);
  if (output)
  {
    char* buffer = new char [4];

    for(short i = 1; i <= 12; ++i)
    {
      buffer = reinterpret_cast<char*>(&i);
      output.write(buffer, 2);
    }
    output.close();
  }

  std::ifstream input ("rawbinary.txt", std::ifstream::binary);
  if (input)
  {
    char* buffer = new char[1];

    for(int i = 0; i < 24; ++i)
    {
      input.read(buffer, 1); // read one character
      char c = *buffer;      // dereference
      printf("CHAR  %2d\n", c);
    }
    input.close();
  }

  std::ifstream input2 ("rawbinary.txt", std::ifstream::binary);
  if (input2)
  {
    char* buffer = new char[2];

    for(int i = 0; i < 12; ++i)
    {
      input2.read(buffer, 2); // read two characters
      short n = *buffer;      // dereference
      printf("SHORT %2d %2d    %4d\n", buffer[0], buffer[1], n);
    }
    input2.close();
  }

  std::ifstream input3 ("rawbinary.txt", std::ifstream::binary);
  if (input3)
  {
    char* buffer = new char[4];
    buffer[0] = 0;
    buffer[1] = 0;
    buffer[2] = 0;
    buffer[3] = 0;

    for(int i = 0; i < 8; ++i)
    {
      input3.read(buffer, 3); // read three characters
      int n = *buffer;
      printf("THREE %2d %2d %2d %2d   %4d\n", buffer[0], buffer[1], buffer[2], buffer[3], n);
    }
    input3.close();
  }

  std::ifstream input4 ("rawbinary.txt", std::ifstream::binary);
  if (input4)
  {
    char* buffer = new char[4];

    for(int i = 0; i < 6; ++i)
    {
      input4.read(buffer, 4); // read three characters
      int n = 16*16*16*buffer[1] + 16*16*buffer[0] + 16*buffer[3] + buffer[2];
      printf("FOUR  %2d %2d %2d %2d   %4d\n", buffer[0], buffer[1], buffer[2], buffer[3], n);
    }
    input4.close();
  }

  FILE *fp = fopen("rawbinary.txt", "r");
  char c;
  printf("FILE ");
  while ((c = getc(fp)) != EOF)
  {
    printf(" %2d", c);
  }
  printf("\n");

  return 0;
}
