#include "record.h"

static const string kTag = "RECORD: ";

/****************************************************************
 * Class for a record.
 * In this case, we have just a single 'string'.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 10 May 2016
**/

/****************************************************************
 * Constructor.
**/
Record::Record() {
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
void Record::SetValue(string what) {
  the_string_ = what;
}

/****************************************************************
 * General functions.
**/

/****************************************************************
 * Usual 'ToString' to return the contents of the class.
**/
string Record::ToString() {
  return kTag + " " + the_string_;
}
