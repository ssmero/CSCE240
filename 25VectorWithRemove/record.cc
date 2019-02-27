#include "record.h"

static const string kTag = "RECORD: ";

/****************************************************************
 * Class for storing office phonebook data.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

/****************************************************************
 * Constructor.
**/
Record::Record() {
  name_ = "NAME";
  office_ = "OFFICE";
  phone_ = "PHONE";
  teaching_ = 999;
}

/****************************************************************
 * Constructor.
 *
 * We read an entire line and then parse that line.
 * This avoids the end of file problem.
 *
 * Parameters:
 *   in_file -- the opened 'Scanner' from which to read
**/
Record::Record(Scanner& in_file) {
  ScanLine scanline;

  string thisline = in_file.NextLine();
  scanline.OpenString(thisline);

  name_ = scanline.Next();
  office_ = scanline.Next();
  phone_ = scanline.Next();
  teaching_ = scanline.NextInt();
}

/****************************************************************
 * Constructor.
 *
 * Parameters:
 *   name -- the 'name' value to assign when constructing
 *   office -- the 'office' value to assign when constructing
 *   phone -- the 'phone' value to assign when constructing
 *   teaching -- the 'teaching' value to assign when constructing
**/
Record::Record(string name, string office,
               string phone, int teaching) {
  name_ = name;
  office_ = office;
  phone_ = phone;
  teaching_ = teaching;
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
 * Accessor for the 'name'.
 *
 * Returns:
 *   the 'name'
**/
string Record::GetName() const {
  return name_;
} // string Record::GetName()

/****************************************************************
 * General functions.
**/

/****************************************************************
 * Comparison function to compare one 'Record' against another.
 * This compares based on the value of 'name_' 
 *
 * Parameters:
 *   a -- the first 'Record' instance
 *   b -- the second 'Record' instance
 *
 * Returns:
 *   A 'bool' as to whether a is less than b or not.
**/
bool Record::CompareName(Record a, Record b) const {
  return (a.name_ < b.name_);
} // bool Record::CompareName()

/****************************************************************
 * Comparison function to compare one 'Record' against another.
 * This compares based on the value of 'office_' 
 *
 * Parameters:
 *   a -- the first 'Record' instance
 *   b -- the second 'Record' instance
 *
 * Returns:
 *   A 'bool' as to whether a is less than b or not.
**/
bool Record::CompareOffice(Record a, Record b) const {
  return (a.office_ < b.office_);
} // bool Record::CompareOffice()

/****************************************************************
 * Comparison function to compare one 'Record' against another.
 * This compares based on the value of 'phone_' 
 *
 * Parameters:
 *   a -- the first 'Record' instance
 *   b -- the second 'Record' instance
 *
 * Returns:
 *   A 'bool' as to whether a is less than b or not.
**/
bool Record::ComparePhone(Record a, Record b) const {
  return (a.phone_ < b.phone_);
} // bool Record::ComparePhone()

/****************************************************************
 * Comparison function to compare one 'Record' against another.
 * This compares based on the value of 'teaching_' 
 *
 * Parameters:
 *   a -- the first 'Record' instance
 *   b -- the second 'Record' instance
 *
 * Returns:
 *   A 'bool' as to whether a is less than b or not.
**/
bool Record::CompareTeaching(Record a, Record b) const {
  return (a.teaching_ < b.teaching_);
} // bool Record::CompareTeaching()

/****************************************************************
 * Usual 'ToString', in this case a formatted line with the
 * data from the instance of this class.
 * 
**/
string Record::ToString() const
{
  string s = "";

  s += Utils::Format(name_, 15, "left");
  s += Utils::Format(office_, 6, "left");
  s += Utils::Format(phone_, 9, "left");
  s += Utils::Format(teaching_, 6);

  return s;
} // string ToString()
