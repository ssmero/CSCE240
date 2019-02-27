/****************************************************************
 * Header for the 'Record' class
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/

#ifndef RECORD_HEADER
#define RECORD_HEADER

#include "../../Utilities/utils.h"

using namespace std;

class Record {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
 Record();
 Record(string name, string office, string phone, int teaching);
 virtual ~Record();

/****************************************************************
 * General functions.
**/
 static bool CompareName(Record a, Record b);
 static bool CompareOffice(Record a, Record b);
 static bool ComparePhone(Record a, Record b);
 static bool CompareTeaching(Record a, Record b);

 string GetName() const;
 string GetOffice() const;
 string GetPhone() const;
 int GetTeaching() const;

 bool IsNull() const;

 string ToString();

private:
 string name_;
 string office_;
 string phone_;
 int teaching_;

/****************************************************************
 * General private functions.
**/
};

#endif // RECORD_HEADER
