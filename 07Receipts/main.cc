#include "main.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Example program: basic grocery receipt, with the work of the program done
 * in a separate class.
 *
 * This program reads a sequence of grocery store transactions
 * from an input file, outputs the "receipt", and runs a total.
 *
 * Author: Duncan A. Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
**/

/******************************************************************************
 * Function 'main'.
 *
 * We do nothing in the main except invoke a 'doTheWork' function in a class
 * of essentially the same name.
 *
**/
int main( ) {
  DoTheWork do_the_work;

  cout << "Execution beginning\n"; 
  cout << "Reading from standard input\n"; 

  do_the_work.ProcessInput();

  cout << "Execution ending\n"; 

  return 0;
} // int main( )
