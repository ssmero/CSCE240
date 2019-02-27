#include "main.h"

/****************************************************************
 * Example use of character reading.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/
int main (int argc, char* argv[]) {
  char c;

/*
*/
// Reading with file pointers and 'getc'
  while((c = getchar()) != EOF) {
    if ('\xd' == c) {
      putchar('\n');
    }
    else {
      putchar(c);
    }
//    printf("(AA PRINTF: %3d %02x %3c)", c, c, c);
//    cout << " COUT: " << c << endl;
  }

/*
// Reading with file pointers and 'getc'
  FILE *fp;
  fp = fopen(argv[1], "r");
  while((c = getc(fp)) != EOF) {
    printf("(AA PRINTF: %3d %02x %3c)", c, c, c);
    cout << " COUT: " << c << endl;
  }
*/

/*
// Reading with 'getchar'
  while((c = getchar()) != EOF) {
    printf("(BB PRINTF: %3d %02x %3c)", c, c, c);
    cout << " COUT: " << c << endl;
  }
  cout << endl;
*/

  return 0;
}
