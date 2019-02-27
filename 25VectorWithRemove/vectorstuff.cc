#include "vectorstuff.h"

static const string kTag = "VECTORSTUFF: ";

/****************************************************************
 * Class for demonstrating removal from a 'vector'
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

/****************************************************************
 * Constructor.
**/
VectorStuff::VectorStuff() {
}

/****************************************************************
 * Destructor.
**/
VectorStuff::~VectorStuff() {
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function to read the data and create the 'vector' of records.
 *
 * All we do is read records one at a time and append them to
 * the 'vector'.
 *
 * Parameters:
 *   in_scanner: the 'Scanner' from which to read
**/
void VectorStuff::CreateVector(Scanner& in_scanner) {
  Record* rec;

  while(in_scanner.HasNext()) {
    rec = new Record(in_scanner);

    the_data_.push_back(*rec);
//    cout << (*rec).ToString() << endl;
  } // while(in_scanner.HasNext())

} // void VectorStuff::createVector(Scanner& in_scanner)

/****************************************************************
 * Function to remove a single record.
 *
 * This is written to show that 'erase' for a 'vector' will
 * change the iteration. If we erase while iterating, we will wind
 * up skipping a record.
**/
void VectorStuff::RemoveRecord() {
  vector<Record>::iterator iter;

  for(iter = the_data_.begin(); iter != the_data_.end(); ++iter) {
    cout << "TEST   " << (*iter).ToString() << endl; // for demo/testing
    if((*iter).GetName() == "Three")
    {
      cout << "REMOVE " << (*iter).ToString() << endl; // for demo/testing
      the_data_.erase(iter);
    }
  }
} // void VectorStuff::RemoveRecord()

/****************************************************************
 * Usual 'ToString' function.
 *
 * Returns:
 *   the 'string' version of the data in the class
**/
string VectorStuff::ToString() const {
  string return_value;

  vector<Record>::const_iterator iter;

  for(iter = the_data_.begin(); iter != the_data_.end(); ++iter) {
    return_value += (*iter).ToString() + "\n";
  }

  return return_value;
} // string VectorStuff::ToString()
