#include "main.h"

using namespace std;

/****************************************************************
 * Example use of a 'struct'.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

/****************************************************************
 *
**/
int main () {
  coordinate nola;
  coordinate columbia;

  columbia.latitude = 34.002680;
  columbia.longitude = -81.025318;

  nola.latitude = 29.961240;
  nola.longitude = -90.063633;

  cout << "Beginning execution" << endl;

  cout << "Columbia (lat,long) (" << columbia.latitude << ", " 
                                  << columbia.longitude << ")" << endl;

  cout << "New Orleans (lat,long) (" << nola.latitude << ", " 
                                     << nola.longitude << ")" << endl;

  cout << "Ending execution" << endl;

  return 0;
}
