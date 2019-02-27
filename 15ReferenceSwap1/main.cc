#include "main.h"

static const string kTag = "MAIN: ";

/****************************************************************
 * Main program for swapping data.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
**/

void swapValue(int one, int two) {
  int temp = one;
  one = two;
  two = temp;

  cout << "val  addresses one, two       " << &one << " " << &two << endl;
}

void swapReference(int& one, int& two) {
  int temp = one;
  one = two;
  two = temp;

  cout << "ref  addresses one, two       " << &one << " " << &two << endl;
}

int main(int argc, char *argv[]) {
  int one = 1;
  int two = 2;

  cout << kTag << "Beginning execution" << endl;

  cout << kTag << "before one: " << one << endl;
  cout << kTag << "before two: " << two << endl << endl;

  cout << kTag << "main addresses one, two " << &one << " " << &two << endl;
  swapValue(one, two);
  cout << kTag << "one after val:  " << one << endl;
  cout << kTag << "one after val:  " << two << endl;
  cout << endl;

  cout << kTag << "main addresses one, two " << &one << " " << &two << endl;
  swapReference(one, two);

  cout << kTag << "one after ref:  " << one << endl;
  cout << kTag << "two after ref:  " << two << endl;

  cout << kTag << "Ending execution" << endl;

  return 0;
}
