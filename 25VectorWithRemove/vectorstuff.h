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
/****************************************************************
 * Constructors and destructors for the class. 
**/
 VectorStuff();
 virtual ~VectorStuff();

/****************************************************************
 * General functions.
**/
 void CreateVector(Scanner& in_file);

 void RemoveRecord();

 string ToString() const;

private:
/****************************************************************
 * Variables.
**/
 vector<Record> the_data_;

};

#endif // VECTORSTUFF_H

