#include "record.h"

static const string kTag = "RECORD: ";

/****************************************************************
 * Class for a record.
 * In this case, we have just a single 'string'.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

/****************************************************************
 * Constructor.
**/
Record::Record() {
  the_string_ = "DUMMY_STRING";
  for (int i = 0; i < 10; ++i)
  {
    the_array_[i] = i;
  }
}

/****************************************************************
 * Destructor.
**/
Record::~Record() {
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/

/****************************************************************
 * Print addresses
**/
void Record::PrintAddresses() {
  cout << "       " << &(the_array_[0])
       << " " << &(the_array_[1024])<< " "
       << &(the_array_[2048]) << endl;
}

/****************************************************************
 * Usual 'ToString' function for returning the data of the class.
 *
 * @return the 'string' version of the rest of the line
**/
string Record::ToString() {
  string s = "";
  for (int i = 0; i < 10; ++i)
  {
    s += Utils::Format(the_array_[i], 4);
  }
  return s;
}
