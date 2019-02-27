/****************************************************************
 * Header for the 'Perms' class
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/

#ifndef PERMS_H
#define PERMS_H

#include <vector>

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

using namespace std;

class Perms {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
 Perms();
 virtual ~Perms();

/****************************************************************
 * General functions.
**/
 vector<string> GenPerms(Scanner& in_stream);

private:
 vector<string> to_be_assigned_; // the elements of which to gen perms

 void DoPerms(vector<string>& all_perms, vector<string>& this_perm,
              const vector<string>& not_yet_used);
 string ToStringVector(const vector<string>& vec);

/****************************************************************
 * General private functions.
**/
};

#endif // PERMS_H
