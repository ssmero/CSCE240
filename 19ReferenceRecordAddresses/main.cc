#include "main.h"

static const string kTag = "MAIN: ";

using namespace std;

/****************************************************************
 * Main program for showing reference of 'array' items.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

int main(int argc, char *argv[])
{
  cout << kTag << "Beginning execution" << endl;

  Record array[30];

  for(int i = 0; i < 30; ++i)
  {
    cout << Utils::Format(i, 6) << " "
         << &array[i] << " "
         << array[i].ToString() << endl;

//    array[i].printAddresses();

  }
  cout << endl;
  cout << endl;

  cout << kTag << " and this is why arrays are evil " << endl;
  for(int i = 1; i < 20; ++i)
  {
    cout << Utils::Format(-i, 6) << " "
         << &array[-i] << " "
         << array[i].ToString() << endl;
  }
  cout << endl;
  cout << endl;

  for(int i = 30; i < 1000; ++i)
  {
    cout << Utils::Format(i, 6) << " "
         << &array[i] << " "
         << array[i].ToString() << endl;
  }

  cout << kTag << "Ending execution" << endl;

  return 0;
}
