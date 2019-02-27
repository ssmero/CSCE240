/****************************************************************
 * Header for the 'Record' class.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

#ifndef RECORD_H
#define RECORD_H

#include <string>
using namespace std;

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class Record {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
 Record();
 virtual ~Record();

/****************************************************************
 * General functions.
**/

 void SetValue(const string& what);
 void Swap(Record& one, Record& two);

 string ToString();

private:
/****************************************************************
 * Variables.
**/
 string the_string_;
 int the_array_[1024];

};

#endif // RECORD_H
