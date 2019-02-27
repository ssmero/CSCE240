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

  for(int i = 0; i < 30; ++i)
  {
    cout << Utils::Format(i, 6) << " "
         << &array[i] << " "
         << Utils::Format(array[i], 18) << endl;
  }
  cout << endl;
  cout << endl;

  cout << kTag << " and this is why arrays are evil " << endl;
  for(int i = 1; i < 20; ++i)
  {
    cout << Utils::Format(-i, 6) << " "
         << &array[-i] << " "
         << Utils::Format(array[-i], 18) << endl;
  }
  cout << endl;
  cout << endl;

  for(int i = 30; i < 1000; ++i)
  {
    cout << Utils::Format(i, 6) << " "
         << &array[i] << " "
         << Utils::Format(array[i], 18) << endl;
  }

  cout << kTag << "Ending execution" << endl;

  return 0;
}
