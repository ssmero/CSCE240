/****************************************************************
 * Header for the 'VectorStuff' class.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

#ifndef VECTORSTUFF_H
#define VECTORSTUFF_H

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

#include "record.h"

using namespace std;

class VectorStuff {
public:
  /////////////////////////////////////////////////////////////////
  // Constructors and destructors for the class 
 VectorStuff();
 virtual ~VectorStuff();

 /////////////////////////////////////////////////////////////////
 // Public variables

 // none

 /////////////////////////////////////////////////////////////////
 // Public functions
 void CreateVector(Scanner& in_file);
 void RemoveRecord();
 void ShowUsage();
 string ToString() const;

private:
 /////////////////////////////////////////////////////////////////
 // Private variables
 vector<Record> the_data_;

 /////////////////////////////////////////////////////////////////
 // private functions

 // none

};

#endif // VECTORSTUFF_H
