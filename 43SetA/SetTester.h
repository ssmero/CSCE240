/****************************************************************
 * Header for the 'SetTester' class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 9 May 2013
 *
**/

#ifndef SETTESTER_H
#define SETTESTER_H

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

#include "Set.h"

class SetTester
{
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  SetTester();
  virtual ~SetTester();

/****************************************************************
 * General functions.
**/
  void testConstructors(Scanner& inStream, ofstream& outStream);
  void testFunctions(Scanner& inStream, ofstream& outStream);

private:
/****************************************************************
 * Variables.
**/
  vector<Set> setVector;
  Set s1, s2, s3, s4, s5, s6, s7, s8;

/****************************************************************
 * Private functions.
**/
  void dumpSet(string label, const Set& theSet, ofstream& outStream);

  void testConstructorsWhiteBox(ofstream& outStream);
  void testConstructorDefault(string label, ofstream& outStream);
  void testConstructorSetFromSet(string label, ofstream& outStream);
  void testConstructorSetFromString(string label, ofstream& outStream);
  void testConstructorSetFromVector(string label, ofstream& outStream);
  void testConstructorSingleton(string label, ofstream& outStream);

  void testFunctionEquals(string label, ofstream& outStream);
};

#endif // SETTESTER_H
