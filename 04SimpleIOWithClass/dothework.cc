#include "dothework.h"

/****************************************************************
 * Code file for 'DoTheWork' for the example using classes.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
 *
**/

/****************************************************************
 * Constructor.
**/
DoTheWork::DoTheWork() {
  this->Init();
}

/****************************************************************
 * Destructor.
**/
DoTheWork::~DoTheWork() {
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function for initializing the class.
 *
 * Note that Google says don't actually put real stuff in the
 * constructor.
**/
void DoTheWork::Init() {
  cout << "What is your name? ";
  cin >> name_string_;
}

/****************************************************************
 * Usual 'ToString' function.
 *
 * Returns: The 'string' version of the class.
 *          In this case, this is 'Hello, NAME!'
**/
string DoTheWork::ToString() {
  string return_value;

  return_value = "Hello, " + name_string_ + "!";

  return return_value;
}
