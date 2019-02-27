#include "main.h"

using namespace std;

static const string kTag = "MAIN: ";

/****************************************************************
 * Main program for showing reference of 'array' items.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/
int main(int argc, char *argv[]) {
  cout << kTag << "Beginning execution" << endl;

  vector<Record> the_vector;

  for(int i = 0; i < 30; ++i) {
    Record rec = Record();
    the_vector.push_back(rec);
  }
  cout << endl;
  cout << endl;

  for(int i = 0; i < 30; ++i) {
    Record rec = Record();
    the_vector.push_back(rec);
    cout << Utils::Format(i, 6) << " "
         << &the_vector.at(i) << " "
         << the_vector.at(i).ToString() << endl;
  }
  cout << endl;
  cout << endl;

  Record* recPtr = &the_vector.at(29);
  cout << "With ptr at end "
       << recPtr << " "
       << recPtr->ToString() << endl;

  for (int i = 0; i < 1000; ++i) {
    ++recPtr;
    cout << "With ptr after increment "
         << recPtr << " "
         << recPtr->ToString() << endl;
  }

/**
  cout << kTag << " and this is why arrays are evil " << endl;
  for(int i = 1; i < 20; ++i) {
    cout << Utils::Format(-i, 6) << " "
         << &array[-i] << " "
         << array[i].ToString() << endl;
  }
  cout << endl;
  cout << endl;

  for(int i = 30; i < 1000; ++i) {
    cout << Utils::Format(i, 6) << " "
         << &array[i] << " "
         << array[i].ToString() << endl;
  }

  cout << kTag << "Ending execution" << endl;
**/

  return 0;
}
