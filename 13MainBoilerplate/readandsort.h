/****************************************************************
 * Header for the 'ReadAndSort' class.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
**/

#ifndef READANDSORT_H
#define READANDSORT_H

#include <iostream>
using namespace std;

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class ReadAndSort {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  ReadAndSort();
  virtual ~ReadAndSort();

/****************************************************************
 * General functions.
**/
  // do not worry about the ampersand yet. just use it as written.
  void ReadData(Scanner& in_scanner);

  void SortData();

  string ToString();

private:
/****************************************************************
 * Variables.
**/
  vector<string> the_data_;

/****************************************************************
 * Functions.
**/
  void AddIfNotDup(string data_value);

};

#endif // READANDSORT_H
