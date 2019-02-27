#include "main.h"

static const string kTag = "MAIN: ";

/****************************************************************
 * Main program for swapping data.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

void SwapValue(Record one, Record two)
{
  Record temp = one;
  one = two;
  two = temp;

  cout << "val  addresses one, two       " << &one << " " << &two << endl;
}

void SwapReference(Record& one, Record& two)
{
  Record temp = one;
  one = two;
  two = temp;

  cout << "ref  addresses one, two       " << &one << " " << &two << endl;
}

int main(int argc, char *argv[])
{
  Record rec1;
  Record rec2;

  cout << kTag << "Beginning execution" << endl;

  rec1.SetValue("one");
  rec2.SetValue("two");

  cout << kTag << "before one: " << rec1.ToString() << endl;
  cout << kTag << "before two: " << rec2.ToString() << endl << endl;

  cout << kTag << "main addresses one, two " << &rec1 << " " << &rec2 << endl;
  SwapValue(rec1, rec2);
  cout << kTag << "one after val:  " << rec1.ToString() << endl;
  cout << kTag << "two after val:  " << rec2.ToString() << endl << endl;

  cout << endl;

  cout << kTag << "main addresses one, two " << &rec1 << " " << &rec2 << endl;
  SwapReference(rec1, rec2);

  cout << kTag << "one after ref:  " << rec1.ToString() << endl;
  cout << kTag << "two after ref:  " << rec2.ToString() << endl << endl;

  cout << kTag << "Ending execution" << endl;

  return 0;
}
