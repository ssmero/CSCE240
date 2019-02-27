/****************************************************************
 * Header for the 'Record' class
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

#ifndef RECORD_H
#define RECORD_H

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

using namespace std;

class Record {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
 Record();
 Record(Scanner& in_file);
 Record(string name, string office, string phone, int teaching);
 virtual ~Record();

/****************************************************************
 * Public data.
**/
 bool CompareName(Record a, Record b) const;
 bool CompareOffice(Record a, Record b) const;
 bool ComparePhone(Record a, Record b) const;
 bool CompareTeaching(Record a, Record b) const;

/****************************************************************
 * Public functions.
**/
 string GetName() const;
 string GetOffice() const;
 string GetPhone() const;
 int GetTeaching() const;

 string ReadData(Scanner& in_file) const;

 string ToString() const;

private:
/****************************************************************
 * Private data.
**/
 string name_;
 string office_;
 string phone_;
 int teaching_;

/****************************************************************
 * Private functions.
**/
};

#endif // RECORD_H
