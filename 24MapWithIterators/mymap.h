/****************************************************************
 * Header for the 'MyMap' class.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

#ifndef MYMAP_H
#define MYMAP_H

#include <map>
using namespace std;

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

#include "record.h"

class MyMap {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
 MyMap();
 virtual ~MyMap();

/****************************************************************
 * General functions.
**/
 void CreateMap(Scanner& in_file);

 string ToString() const;

private:
/****************************************************************
 * Variables.
**/
 map<string, Record> the_data_;

};

#endif // MYMAP_H
