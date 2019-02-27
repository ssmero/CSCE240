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
 * A local swap function with the parameter types hard coded. 
void mySwap(int& m, int& n)
{
  int temp;
  temp = m;
  m = n;
  n = temp;
}
**/

/****************************************************************
 * A main program for demonstrating 'template'-based swaps.
**/
int main( ) {
/****************************************************************
 * Demonstrate the swap with primitive types.
**/
  int m, n;
  double x, y;

  m = 11;
  n = 12;
  x = 10.5;
  y = 23.6;

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
 * Now demonstrate the swap with a complex class.
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
  cout << "values after the 'swap' inside the 'Pair' class "
       << pair_one.GetFirst() << " "
       << pair_one.GetSecond() << endl << endl;

  cout << "FOURTH TEST: original values "
       << pair_one.ToString() << " "
       << pair_two.ToString() << endl;
  TemplateElementSwap(pair_one, pair_two);
  cout << "after templated swap of 'Pair' objects "
       << pair_one.ToString() << " "
       << pair_two.ToString() << endl;

  return 0;
}
