#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

using namespace std;

int main ()
{
  int r2 = 16*16;
  int r4 = r2*r2;
  int r6 = r4*r2;

  std::ofstream output ("rawbinary5.txt", std::ofstream::binary);
  if (output)
  {
    char* buffer = new char [4];

    for(int i = 1; i <= 24; i += 4)
    {
      int n = i + r2*(i+1) + r4*(i+2) + r6*(i+3);
      buffer = reinterpret_cast<char*>(&n);
      output.write(buffer, 4);
      printf("%12d %08x\n", n, n);
    }
    output.close();
  }

  std::ifstream input ("rawbinary5.txt", std::ifstream::binary);
  if (input)
  {
    char* buffer = new char[1];

    for(int i = 0; i < 24; ++i)
    {
      input.read(buffer, 1); // read one character
      char c = *buffer;      // dereference
      printf("CHAR  X%2dX\n", c);
    }
    input.close();
  }

  std::ifstream input2 ("rawbinary5.txt", std::ifstream::binary);
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

/*
  std::ifstream input3 ("rawbinary5.txt", std::ifstream::binary);
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
*/

  std::ifstream input4 ("rawbinary5.txt", std::ifstream::binary);
  if (input4)
  {
    char* buffer = new char[4];

    for(int i = 0; i < 6; ++i)
    {
      input4.read(buffer, 4); // read three characters
      int n = r6*buffer[3] + r4*buffer[2] + r2*buffer[1] + buffer[0];
      printf("FOUR  %2d %2d %2d %2d   %4d\n", buffer[0], buffer[1], buffer[2], buffer[3], n);
    }
    input4.close();
  }

  {
    FILE *fp = fopen("rawbinary5.txt", "r");
    char c;
    printf("FILE ");
    while ((c = getc(fp)) != EOF)
    {
      printf(" %2d", c);
    }
    printf("\n");
    fclose(fp);
  }


  {
    FILE *fp = fopen("rawbinary5.txt", "r");
    int n;
    for(int i = 0; i < 6; ++i)
    {
      fread(&n, 4, 1, fp);
      printf("READ %2d %12d\n", i, n);
    }
    fclose(fp);
  }

  return 0;
}
