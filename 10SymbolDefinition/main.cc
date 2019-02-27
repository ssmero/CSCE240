#include "main.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Example program: symbols must be declared before they are used.
 *
 * Author: Duncan A. Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
**/

/******************************************************************************
 * Function 'MyFunctionAbove'.
**/
void MyFunctionAbove() {
  cout << "Printing from 'MyFunctionAbove' above the 'main'" << endl;
} // void MyFunctionAbove()

/******************************************************************************
 * Forward declaration of the function that appears later.
**/
// void MyFunctionBelow();

/******************************************************************************
 * Function 'main'.
**/
int main( ) {
  cout << "Execution beginning\n"; 

  MyFunctionAbove();

//  MyFunctionBelow();

  cout << "Execution ending\n"; 

  return 0;
} // int main( )

/******************************************************************************
 * Function 'MyFunctionBelow'.
**/
void MyFunctionBelow() {
  cout << "Printing from 'MyFunctionBelow' below the 'main'" << endl;
} // void MyFunctionBelow()

