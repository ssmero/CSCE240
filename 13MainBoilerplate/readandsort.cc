#include "readandsort.h"

static const string kTag = "READANDSORT: ";

/****************************************************************
 * Class for reading and sorting primitive data.
 * In this case, we use 'string' data and the 'vector' container. 
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
**/

/****************************************************************
 * Constructor.
**/
ReadAndSort::ReadAndSort() {
}

/****************************************************************
 * Destructor.
**/
ReadAndSort::~ReadAndSort() {
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function to add a data value if it's not a duplicate.
 *
 * The input 'string' is searched for in the 'vector'. If it is
 * not there, we push it back to the end. If it is there, we
 * do not add it again.
 *
 * We do a crude linear search to determine dups.
 *
 * Parameters:
 *   data_value -- the value to add or not
**/
void ReadAndSort::AddIfNotDup(string data_value) {
  bool is_new_value = true;

#ifdef EBUG
  Utils::log_stream << kTag << "enter AddIfNotDup\n";
  Utils::log_stream.flush();
#endif

  is_new_value = true;
  for(int i = 0; i < the_data_.size(); ++i) {
    if(the_data_.at(i) == data_value)
    {
      is_new_value = false;
      break;
    }
  }

  if(is_new_value) {
    the_data_.push_back(data_value);
  }

#ifdef EBUG
  Utils::log_stream << kTag << "leave AddIfNotDup\n";
  Utils::log_stream.flush();
#endif
} // void ReadAndSort::AddIfNotDup(string data_value)

/****************************************************************
 * Function to read the data and create the 'vector' of records.
 *
 * We read as long as there is data, and add the token that is
 * read if it isn't already there.
 *
 * Parameters:
 *   in_scanner -- the 'Scanner' from which to read
**/
void ReadAndSort::ReadData(Scanner& in_scanner)
{
  string data_value = "";

#ifdef EBUG
  Utils::log_stream << kTag << "enter ReadData\n";
  Utils::log_stream.flush();
#endif


  while(in_scanner.HasNext()) {
    data_value = in_scanner.Next();

    this->AddIfNotDup(data_value);

  } // while(in_scanner.hasNext()) {

#ifdef EBUG
  Utils::log_stream << TAG << "leave ReadData\n";
  Utils::log_stream.flush();
#endif
}

/****************************************************************
 * Function to sort the 'vector' based on the natural ordering
 * of the contents.
 *
 * For this simple example, we do a bubble sort.
**/
void ReadAndSort::SortData()
{
  for(int i = 0; i < the_data_.size()-1; ++i)
  {
    for(int j = i+1; j < the_data_.size(); ++j)
    {
      if(the_data_.at(i) > the_data_.at(j))
      {
        string temp = the_data_.at(i);
        the_data_.at(i) = the_data_.at(j);
        the_data_.at(j) = temp;
      }
    }
  }
}

/****************************************************************
 * Function for returning the string version of the data in
 * the container.
 *
 * Returns:
 *   the 'string' version of the 'vector'
**/
string ReadAndSort::ToString() {
  string return_value = "";

#ifdef EBUG
  Utils::log_stream << kTag << "enter ToString\n";
  Utils::log_stream.flush();
#endif

  for(int i = 0; i < the_data_.size(); ++i)
  {
    // note that you can't use 'percent n' but must use 'backslash n'
    return_value += the_data_.at(i) + "\n";
  }

#ifdef EBUG
  Utils::log_stream << kTag << "leave ToString\n";
  Utils::log_stream.flush();
#endif
  return return_value;
}
