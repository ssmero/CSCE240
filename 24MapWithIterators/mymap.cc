#include "mymap.h"

static const string kTag = "MYMAP: ";

/****************************************************************
 * Class for reading and dumping a 'map' using iterators.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

/****************************************************************
 * Constructor.
**/
MyMap::MyMap() {
}

/****************************************************************
 * Destructor.
**/
MyMap::~MyMap() {
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function to read the data and create the 'map' of 'Record's.
 *
 * Parameters:
 *   inFile -- the opened 'Scanner' for reading from
**/
void MyMap::CreateMap(Scanner& in_file)
{
#ifdef EBUG3
  Utils::log_stream << kTag << "enter CreateMap" << endl;
  Utils::log_stream.flush();
#endif

  Scanner& local_file = in_file;

  while(local_file.HasNext())
  {
    Record* rec_ptr = new Record(local_file);

    string name_key = (*rec_ptr).GetName();
    if(the_data_.find(name_key) == the_data_.end())
    {
//      the_data_.at(name_key) = (*rec_ptr);
      the_data_[name_key] = (*rec_ptr);
      Utils::log_stream << kTag << "ADD " << (*rec_ptr).ToString()<< endl;
      Utils::log_stream.flush();
    }
    else
    {
      Utils::log_stream << kTag << "SKIP " << (*rec_ptr).ToString()<< endl;
      Utils::log_stream.flush();
    }

  } // while(localFile.hasNext())

#ifdef EBUG3
  Utils::log_stream << kTag << "leave CreateMap" << endl;
  Utils::log_stream.flush();
#endif
} // void MyMap::CreateMap(Scanner& inFile)

/****************************************************************
 * Function for returning a 'ToString' of the 'map' data.
 *
 * @return the 'string' version of the data
**/
string MyMap::ToString() const {
  string return_value;

//  map<string, Record>::iterator iter;
  map<string, Record>::const_iterator iter;

  for(iter = the_data_.begin(); iter != the_data_.end(); ++iter)
  {
    return_value += (iter->second).ToString() + "\n";
  }

  return return_value;
} // string MyMap::ToString()
