/****************************************************************
 * Header for the 'SetTester' class.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 13 May 2016
**/

#ifndef SETTESTER_H
#define SETTESTER_H

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

#include "set.h"

class SetTester {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
 SetTester();
 virtual ~SetTester();

/****************************************************************
 * General functions.
**/
 void TestConstructors(Scanner& in_stream, ofstream& out_stream);
 void TestFunctions(Scanner& in_stream, ofstream& out_stream);

private:
/****************************************************************
 * Variables.
**/
 vector<Set> set_vector_;
 Set s1_, s2_, s3_, s4_, s5_, s6_, s7_, s8_;

/****************************************************************
 * Private functions.
**/
 void dumpSet(string label, const Set& the_set, ofstream& out_stream);

 void TestConstructorsWhiteBox(ofstream& out_stream);
 void TestConstructorDefault(string label, ofstream& out_stream);
 void TestConstructorSetFromSet(string label, ofstream& out_stream);
 void TestConstructorSetFromString(string label, ofstream& out_stream);
 void TestConstructorSetFromVector(string label, ofstream& out_stream);
 void TestConstructorSingleton(string label, ofstream& out_stream);

 void TestFunctionEquals(string label, ofstream& out_stream);
};

#endif // SETTESTER_H
