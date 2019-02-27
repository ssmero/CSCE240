/****************************************************************
 * Header for the 'MySet' class.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

#ifndef MYSET_H
#define MYSET_H

#include <set>
using namespace std;

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class MySet {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
 MySet();
 virtual ~MySet();

/****************************************************************
 * General functions.
**/
 void CreateSet(Scanner& in_file);

 string ToString() const;

private:
/****************************************************************
 * Variables.
**/
  set<string> the_data_;

};

#endif // MYSET_H
