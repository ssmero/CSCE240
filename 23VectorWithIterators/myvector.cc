#include "myvector.h"

static const string kTag = "MYVECTOR: ";

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
MyVector::MyVector() {
}

/****************************************************************
 * Destructor.
**/
MyVector::~MyVector() {
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function to read the data and create the 'vector' of strings.
 *
 * Parameters:
 *   in_file -- the opened 'Scanner' for reading from
**/
void MyVector::CreateVector(Scanner& in_file)
{
#ifdef EBUG3
  Utils::log_stream << kTag << "enter CreateVector" << endl;
  Utils::log_stream.flush();
#endif

  Scanner& local_file = in_file;

  while(local_file.HasNext())
  {
    string word = local_file.Next();

    the_data_.push_back(word);
  } // while(local_file.HasNext())

#ifdef EBUG3
  Utils::log_stream << kTag << "leave CreateVector" << endl;
  Utils::log_stream.flush();
#endif
} // void MyVector::CreateVector(Scanner& in_file)

/****************************************************************
 * Function for returning a 'ToString' of 'vector' data.
 *
 * Returns:
 *   the 'string' version of the 'vector'
**/
string MyVector::ToString() const {
  string return_value;

  vector<string>::const_iterator iter;

  for(iter = the_data_.begin(); iter != the_data_.end(); ++iter)
  {
    return_value += (*iter) + "\n";
  }

  return return_value;
} // string MyVector::ToString()
