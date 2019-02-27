#include "main.h"

static const string kTag = "MAIN: ";

/****************************************************************
 * Main program for showing reference of 'array' items.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Date: 12 January 2014
 *
**/

int main(int argc, char *argv[])
{
  cout << kTag << "Beginning execution" << endl;

  int array[30];
  for(int i = 0; i < 15; ++i)
  {
    array[i] = i;
  }

  int* int_ptr = array;

  for(int i = 0; i < 30; ++i)
  {
    cout << *int_ptr << endl;
    ++int_ptr;
  }
  cout << endl;
  cout << endl;

  cout << kTag << "Ending execution" << endl;

  return 0;
}
