#include "main.h"

using namespace std;

/****************************************************************
 * Example use of 'assert'.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
**/

/****************************************************************
 *
**/
int main () {
  int n = 0;

  cout << "Beginning execution" << endl;

  assert (n == 0);

  n = 1;
  assert (n == 0);

  cout << "Ending execution" << endl;

  return 0;
}
