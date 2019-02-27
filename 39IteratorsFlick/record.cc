#include "record.h"

static const string kTag = "RECORD: ";

/****************************************************************
 * Class for storing office phonebook data.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
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
Record::Record(Scanner& inFile)
{
  this->name = inFile.next();
  this->office = inFile.next();
  this->phone = inFile.next();
  this->teaching = inFile.nextInt();
}
**/

/****************************************************************
 * Constructor.
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
 *
**/

/****************************************************************
 * General functions.
**/

/****************************************************************
 * 
**/
bool Record::CompareName(Record a, Record b) {
  return (a.name_ < b.name_);
} // bool Record::CompareName()

/****************************************************************
 * 
**/
bool Record::CompareOffice(Record a, Record b) {
  return (a.office_ < b.office_);
} // bool Record::CompareOffice()

/****************************************************************
 * 
**/
bool Record::ComparePhone(Record a, Record b) {
  return (a.phone_ < b.phone_);
} // bool Record::ComparePhone()

/****************************************************************
 * 
**/
bool Record::CompareTeaching(Record a, Record b) {
  return (a.teaching_ < b.teaching_);
} // bool Record::CompareTeaching()

/****************************************************************
 * 
**/
bool Record::IsNull() const
{
  return (name_ == "NAME");
} // bool Record::IsNull()

/****************************************************************
 * 
**/
string Record::ToString() {
  string s = "";

  s += Utils::Format(name_, 15, "left");
  s += Utils::Format(office_, 6, "left");
  s += Utils::Format(phone_, 9, "left");
  s += Utils::Format(teaching_, 6);

  return s;
} // string ToString()
