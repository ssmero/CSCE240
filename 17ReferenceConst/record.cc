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
 * Assignment function
**/
void Record::SetValue(const string& what) {
  the_string_ = what;
}

/****************************************************************
 * General functions.
**/

/****************************************************************
 * Function for returning the result of the parse.
 *
 * @return the 'string' version of the rest of the line
**/
string Record::ToString() {
  return kTag + " " + the_string_;
}
