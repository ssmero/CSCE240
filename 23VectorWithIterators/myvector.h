/****************************************************************
 * Header for the 'MyVector' class.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <vector>
using namespace std;

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class MyVector {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
 MyVector();
 virtual ~MyVector();

/****************************************************************
 * General functions.
**/
 void CreateVector(Scanner& in_file);

 string ToString() const;

private:
/****************************************************************
 * Variables.
**/
 vector<string> the_data_;

};

#endif // MYSET_H
