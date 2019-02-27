#include "main.h"

/****************************************************************
 * Example iterator program from cplusplus.com, modified to use
 * a private array in a separate class.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/

/****************************************************************
 *
**/
int main () {

  MyArray zork;
  for(int i = 1; i < 6; ++i) {
    string s = Utils::Format(i*10+1);
    Record rec;
    rec = Record(s, "dummy", "dummydummy", i*100+1); 
    zork.Add(rec);
    cout << "ADD " << rec.ToString() << endl;
  }
  cout << endl;

  cout << "USING TOSTRING" << endl;
  std::cout << zork.ToString() << endl;

  cout << "USING ITERATOR" << endl;
  for(MyArray::TheIterator iter = zork.begin(); iter != zork.end(); ++iter) {
    cout << (*iter).ToString() << endl;
  } 

  return 0;
}
