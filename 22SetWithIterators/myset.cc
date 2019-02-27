#include "myset.h"

static const string kTag = "MYSET: ";

/****************************************************************
 * Class for reading and dumping a 'set' using an iterator.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

/****************************************************************
 * Constructor.
**/
MySet::MySet() {
}

/****************************************************************
 * Destructor.
**/
MySet::~MySet() {
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function to read the data and create the 'set' of strings.
 *
 * Parameters:
 *   inFile -- the opened 'Scanner' for reading from
**/
void MySet::CreateSet(Scanner& in_file) {
#ifdef EBUG
  Utils::log_stream << kTag << "enter CreateSet" << endl;
  Utils::log_stream.flush();
#endif

  Scanner& local_file = in_file;

  while(local_file.HasNext())
  {
    string word = local_file.Next();

    the_data_.insert(word);
  } // while(local_file.HasNext())

#ifdef EBUG
  Utils::log_stream << kTag << "leave CreateSet" << endl;
  Utils::log_stream.flush();
#endif
} // void MySet::createSet(Scanner& inFile)

/****************************************************************
 * Function for returning a 'toString' of the 'vector' of
 * 'set' data.
 *
 * This uses a constant iterator. Note that this is a 2011 feature.
 *
 * Returns:
 *   the 'string' version of the 'set'
**/
string MySet::ToString() const {
  string return_value;

  set<string>::const_iterator iter;
  for(iter = the_data_.begin(); iter != the_data_.end(); ++iter)
  {
    return_value += (*iter) + "\n";
  }

  return return_value;
} // string MySet::ToString()
