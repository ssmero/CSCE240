#include "main.h"

static const string kTag = "MAIN: ";

/****************************************************************
 * Main program for swapping data.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 10 May 2016
**/

void SwapValue(Record one, Record two, string kTag) {
  Record temp = one;
  one = two;
  two = temp;

  cout << kTag << "val  addresses one, two " << &one << " "
       << &two << endl;
}

void SwapReference(Record& one, Record& two, string kTag) {
  Record temp = one;
  one = two;
  two = temp;

  cout << kTag << "ref  addresses one, two " << &one << " "
       << &two << endl;
}

int main(int argc, char *argv[]) {
//  const string kTag = "MAIN: ";

  Record rec1;
  Record rec2;
  Record rec3;

  cout << kTag << "Beginning execution" << endl;

  rec1.SetValue("one");
  rec2.SetValue("We the people of the United States, in order to form a more perfect union, establish justice, insure domestic tranquility, provide for the common defense, promote the general welfare, and secure the blessings of liberty to ourselves and our posterity, do ordain and establish this Constitution for the United States");
  rec3.SetValue("two");

  cout << kTag << "before one: " << rec1.ToString() << endl;
  cout << kTag << "before two: " << rec2.ToString() << endl << endl;
  cout << kTag << "before thr: " << rec3.ToString() << endl << endl;

  cout << kTag << "sizeof 1 : " << sizeof(rec1) << endl << endl;
  cout << kTag << "sizeof 2 : " << sizeof(rec2) << endl << endl;
  cout << kTag << "sizeof 3 : " << sizeof(rec3) << endl << endl;

  cout << kTag << "main addresses one, two " << &rec1 << " " << &rec2 << endl;
  SwapValue(rec1, rec2, kTag);
  cout << kTag << "one after val:  " << rec1.ToString() << endl;
  cout << kTag << "two after val:  " << rec2.ToString() << endl << endl;

  cout << endl;

  cout << kTag << "main addresses one, two " << &rec1 << " " << &rec2 << endl;
  SwapReference(rec1, rec2, kTag);

  cout << kTag << "one after ref:  " << rec1.ToString() << endl;
  cout << kTag << "two after ref:  " << rec2.ToString() << endl << endl;

  cout << kTag << "Ending execution" << endl;

  return 0;
}
