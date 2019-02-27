#include "main.h"

/****************************************************************
 * Main program for demonstrating templates.
 * Author and copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 13 May 2016
 *
 * This program shows the use of the 'template' feature in C++.
 * This is the analog to the Java 'generic'.
**/

// In order to use a 'template' we need to include the code
// in the module in which the template will be compiled.
// We cannot compile completely externally as is (sort of)
// done in Java.
// Note also the dot hpp extension.  There are some who
// argue that '*.h' and '*.c' go together and that the
// corresponding extension for C++ programs should be
// 'hpp' and not 'h'.

/****************************************************************
 * A main program for demonstrating 'template'-based swaps.
**/
int main( ) {
/****************************************************************
 * Demonstrate the templated swap with primitive types.
**/
  int m = 11;
  int n = 12;
  double x = 10.5;
  double y = 23.6;

  cout << "FIRST TEST: original 'int' values "
       << m << " "
       << n << endl;
  TemplateElementSwap(m, n);
  cout << "values after the templated 'TemplateElementSwap' "
       << m << " "
       << n << endl << endl;

  cout << "SECOND TEST: original 'double' values "
       << x << " "
       << y << endl;
  TemplateElementSwap(x, y);
  cout << "values after the templated 'TemplateElementSwap' "
       << x << " "
       << y << endl << endl;

/****************************************************************
 * Now demonstrate the swap with a complex class that uses templates.
**/

  MyPair<int> pair_one, pair_two;

  pair_one.SetFirst(11);
  pair_one.SetSecond(22);

  pair_two.SetFirst(33);
  pair_two.SetSecond(44);

  cout << "THIRD TEST: original 'int' values "
       << pair_one.GetFirst() << " "
       << pair_one.GetSecond() << endl;
  pair_one.Swap();
  cout << "values after the 'swap' inside the 'MyPair' class "
       << pair_one.GetFirst() << " "
       << pair_one.GetSecond() << endl << endl;

  cout << "FOURTH TEST: original values "
       << pair_one.ToString() << " "
       << pair_two.ToString() << endl;
  TemplateElementSwap(pair_one, pair_two);
  cout << "after templated swap of 'MyPair' objects "
       << pair_one.ToString() << " "
       << pair_two.ToString() << endl;

  if (pair_one.Equals(pair_two)) {
    cout << "pair one equals pair two" << endl;
  } else {
    cout << "pair one does not equal pair two" << endl;
  }

/****************************************************************
 * Now demonstrate the swap with another complex class.
**/
  MyPair<string> string_pair_one, string_pair_two;

  string_pair_one.SetFirst("one first");
  string_pair_one.SetSecond("one second");

  string_pair_two.SetFirst("two first");
  string_pair_two.SetSecond("two second");

  cout << "FIFTH TEST: original 'string' values "
       << string_pair_one.GetFirst() << " "
       << string_pair_one.GetSecond() << endl;
  string_pair_one.Swap();
  cout << "values after the 'swap' inside the 'MyPair' class "
       << string_pair_one.GetFirst() << " "
       << string_pair_one.GetSecond() << endl << endl;

  cout << "SIXTH TEST: original values "
       << string_pair_one.ToString() << " "
       << string_pair_two.ToString() << endl;
  TemplateElementSwap(string_pair_one, string_pair_two);
  cout << "after templated swap of 'MyPair' objects "
       << string_pair_one.ToString() << " "
       << string_pair_two.ToString() << endl;

  if (string_pair_one.Equals(string_pair_two)) {
    cout << "string_pair_one equals string_pair_two" << endl;
  } else {
    cout << "string_pair_one does not equal string_pair_two" << endl;
  }

/****************************************************************
 * And finally one that does not work without more stuff.
**/
  MyPair<Record> mypair_pair_one, mypair_pair_two;

  Record rec1 = Record("nameone", "officeone", "111-1111", 111);
  Record rec2 = Record("nametwo", "officetwo", "222-2222", 222);
  Record rec3 = Record("namethr", "officethr", "333-3333", 333);
  Record rec4 = Record("namefou", "officefou", "444-4444", 444);

  mypair_pair_one.SetFirst(rec1);
  mypair_pair_one.SetSecond(rec2);

  mypair_pair_two.SetFirst(rec3);
  mypair_pair_two.SetSecond(rec4);

  cout << "SEVENTH TEST: original 'record' values " << endl
       << mypair_pair_one.GetFirst().ToString() << " " << endl
       << mypair_pair_one.GetSecond().ToString() << endl;
  mypair_pair_one.Swap();
  cout << "values after the 'swap' inside the 'MyPair' class " << endl
       << mypair_pair_one.GetFirst().ToString() << " " << endl
       << mypair_pair_one.GetSecond().ToString() << endl << endl;

  // swap it back so we don't get confused in the next step
  mypair_pair_one.Swap();
  cout << "values after 'swap' back to the original " << endl
       << mypair_pair_one.GetFirst().ToString() << " " << endl
       << mypair_pair_one.GetSecond().ToString() << endl << endl;

  cout << "EIGHTH TEST: original values " << endl
       << mypair_pair_one.GetFirst().ToString() << " " << endl
       << mypair_pair_one.GetSecond().ToString() << endl << endl
       << mypair_pair_two.GetFirst().ToString() << " " << endl
       << mypair_pair_two.GetSecond().ToString() << endl << endl;
  TemplateElementSwap(mypair_pair_one, mypair_pair_two);
  cout << "after templated swap of 'MyPair' objects " << endl
       << mypair_pair_one.GetFirst().ToString() << " " << endl
       << mypair_pair_one.GetSecond().ToString() << endl << endl
       << mypair_pair_two.GetFirst().ToString() << " " << endl
       << mypair_pair_two.GetSecond().ToString() << endl << endl;

  if (mypair_pair_one.Equals(mypair_pair_two)) {
    cout << "mypair_pair_one equals mypair_pair_two" << endl;
  } else {
    cout << "mypair_pair_one does not equal mypair_pair_two" << endl;
  }

  if (mypair_pair_one.Equals(mypair_pair_one)) {
    cout << "mypair_pair_one equals mypair_pair_one" << endl;
  } else {
    cout << "mypair_pair_one does not equal mypair_pair_one" << endl;
  }

  cout << "Using overloaded output of 'Record' objects " << endl
       << mypair_pair_one.ToString() << endl
       << mypair_pair_two.ToString() << endl << endl;
/*
*/

  return 0;
}
