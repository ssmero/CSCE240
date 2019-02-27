#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

using namespace std;

int main () {

//////////////////////////////////////////////////////////////////
  // open a file for writing.
  // since we are going to write in binary, there is no point in using 
  // a 'txt' suffix.
  FILE *fp = fopen("zork", "w");

  // we will use numeric value 65 as example, which  is also the character 'A'
  int n = 65;

  // write from 'n', using 4 bytes from the address of 'n', and write 1 item
  // to the 'fp' stream. then close the file.
  fwrite(&n, 4, 1, fp);
  fclose(fp);

  // we will reopen the file and read the values in as integers.
  // note that we don't in fact read past end of file.
  // the 'm2' value does not get set.
  int m1 = -1;
  int m2 = -2;
  fp = fopen("zork", "r");
  fread(&m1, 4, 1, fp);
  fread(&m2, 4, 1, fp);
  cout << "m1,m2  '" << m1 << "' '" << m2 << "'" << endl;
  fclose(fp);


//////////////////////////////////////////////////////////////////
  // now let's do it again, but write some junk out
  fp = fopen("zork2", "w");
  // we will use numeric value 65 as example, which  is also the character 'A'

  // we only defined 'n' as one integer, but we are perfectly free to write
  // out two integers worth of memory contents.
  fwrite(&n, 4, 2, fp);
  fclose(fp);

  // we will reopen the file and read the values in as integers.
  // this time, we get values for both but the second is junk...
  m1 = -1;
  m2 = -2;
  fp = fopen("zork2", "r");
  fread(&m1, 4, 1, fp);
  fread(&m2, 4, 1, fp);
  cout << "m1,m2  '" << m1 << "' '" << m2 << "'" << endl;
  fclose(fp);

//////////////////////////////////////////////////////////////////
  // and now let's open and read the characters of an ascii file
  // this is simpler--we (mostly) understand ascii data
  fp = fopen("test.txt", "r");
  char carray[81];
  fread(carray, 1, 10, fp);
  for(int i = 0; i < 5; ++i)
  {
    cout << "char " << i << " '" << carray[i] << "'" << endl;
  }

  return 0;
}
