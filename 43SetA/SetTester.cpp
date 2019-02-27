#include "SetTester.h"
/****************************************************************
 * Class for testing sets.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Date: 5 October 2013
 *
**/

static const string TAG = "SetTester: ";

/****************************************************************
 * Constructor.
**/
SetTester::SetTester()
{
}

/****************************************************************
 * Destructor.
**/
SetTester::~SetTester()
{
}

/****************************************************************
 * Accessors and mutators.
**/
/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function to dump a set for verification purposes.
**/
void SetTester::dumpSet(string label, const Set& theSet, ofstream& outStream)
{
#ifdef EBUG
  Utils::logStream << TAG << "ENTER DUMPSET " << endl;
  Utils::logStream.flush();
#endif

  outStream << TAG << label << " (" << theSet.card() << ")" << theSet.toString() << endl;
  outStream.flush();

#ifdef EBUG
  Utils::logStream << TAG << "LEAVE DUMPSET " << endl;
  Utils::logStream.flush();
#endif

}

/****************************************************************
 * Function to test constructors
**/
void SetTester::testConstructors(Scanner& inScanner, ofstream& outStream)
{
  string line;
  ScanLine scanLine;

  this->testConstructorsWhiteBox(outStream);

} // void SetTester::testConstructors()

/****************************************************************
 * Function to test the constructors.
**/
void SetTester::testConstructorsWhiteBox(ofstream& outStream)
{
#ifdef EBUG
  Utils::logStream << TAG << "ENTER TEST CONSTRUCTORS WHITE BOX " << endl;
  Utils::logStream.flush();
#endif

  outStream << "TEST THE CONSTRUCTORS" << endl;

  testConstructorDefault("A", outStream);
  testConstructorSingleton("B", outStream);
  testConstructorSetFromString("C", outStream);
  testConstructorSetFromVector("D", outStream);
  testConstructorSetFromSet("E", outStream);

#ifdef EBUG
  Utils::logStream << TAG << "LEAVE TEST CONSTRUCTORS WHITE BOX " << endl;
  Utils::logStream.flush();
#endif

} // void SetTester::testConstructorsWhiteBox(ofstream& outStream)

/****************************************************************
 * Function to test the default constructor.
**/
void SetTester::testConstructorDefault(string label, ofstream& outStream)
{
  Set theSet;
#ifdef EBUG
  Utils::logStream << TAG << "ENTER TEST CONSTRUCTOR DEFAULT " << endl;
  Utils::logStream.flush();
#endif

  outStream << label << "  TEST THE DEFAULT CONSTRUCTOR" << endl;
  outStream << label << "  INCLUDE 'isEmpty' IN THE TEST" << endl;

  for (int i = 1; i <= 5; ++i)
  {
    theSet = Set();
    outStream << label << "  NULL SET " << theSet.toString() << endl;
    if (theSet.isEmpty())
    {
      outStream << label << "  NULL SET does test as empty"
                << theSet.toString() << endl;
    }
    else
    {
      outStream << label << "  ERROR NULL SET does not test as empty"
                << theSet.toString() << endl;
      exit(0);
    }
  }

  // one blank line at the end of this test
  outStream << endl;

#ifdef EBUG
  Utils::logStream << TAG << "LEAVE TEST CONSTRUCTOR DEFAULT" << endl;
  Utils::logStream.flush();
#endif
} // void SetTester::testConstructorDefault(ofstream& outStream)

/****************************************************************
 * Function to test the singleton constructor.
**/
void SetTester::testConstructorSingleton(string label, ofstream& outStream)
{
  Set theSet;
#ifdef EBUG
  Utils::logStream << TAG << "ENTER TEST CONSTRUCTOR SINGLETON " << endl;
  Utils::logStream.flush();
#endif

  outStream << label << "  TEST THE SINGLETON CONSTRUCTOR" << endl;
  outStream << label << "  INCLUDE 'card' IN THE TEST" << endl;
  outStream << label << "  INCLUDE 'containsElement' IN THE TEST" << endl;

  for (int i = 1; i <= 5; ++i)
  {
    // create the set
    theSet = Set(i);

    // test cardinality
    if (1 == theSet.card())
    {
      outStream << "B  SINGLETON SET has card 1"
                << theSet.toString() << endl;
    }
    else
    {
      outStream << "B  ERROR SINGLETON SET has card not 1"
                << theSet.toString() << endl;
      exit(0);
    }

    // now let's test the 'is an element of' function
    if (!theSet.containsElement(i))
    {
      outStream << "B  ERROR SINGLETON SET fails to have the proper element "
                << i << " " << theSet.toString() << endl;
      exit(0);
    }
  }

  // one blank line at the end of this test
  outStream << endl;

#ifdef EBUG
  Utils::logStream << TAG << "LEAVE TEST CONSTRUCTOR SINGLETON" << endl;
  Utils::logStream.flush();
#endif
} // void SetTester::testConstructorSingleton(ofstream& outStream)

/****************************************************************
 * Function to test the set from string constructor.
**/
void SetTester::testConstructorSetFromString(string label, ofstream& outStream)
{
  Set theSet;

  // we include here the vector versions of the test data so we can
  // iterate over the elements as part of our test
  int card1 = 6;
  string str1 = " 1  4  3  2  5  6";
  int arr1[] = {1, 4, 3, 2, 5, 6};
  vector<int> v1 (arr1, arr1 + sizeof(arr1)/sizeof(int));

  int card2 = 5;
  string str2 = " 1  9  7  3  13";
  int arr2[] = {1, 9, 7, 3, 13};
  vector<int> v2 (arr2, arr2 + sizeof(arr2)/sizeof(int));

  int card3 = 0;
  string str3 = "";
  int arr3[] = {};
  vector<int> v3 (arr3, arr3 + sizeof(arr3)/sizeof(int));

//  int arr1[] = {1, 4, 3, 2, 5, 6};
//  vector<int> v1 (arr1, arr1 + sizeof(arr1)/sizeof(int));

//  int arr2[] = {1, 9, 7, 3, 13};
//  vector<int> v2 (arr2, arr2 + sizeof(arr2)/sizeof(int));

#ifdef EBUG
  Utils::logStream << TAG << "ENTER TEST CONSTRUCTOR SET FROM STRING " << endl;
  Utils::logStream.flush();
#endif

  outStream << label << "  TEST THE SET FROM STRING CONSTRUCTOR" << endl;
  outStream << label << "  INCLUDE 'card' IN THE TEST" << endl;
  outStream << label << "  INCLUDE 'containsElement' IN THE TEST" << endl;

  // test the first set
  theSet = Set(str1);
  if (card1 == theSet.card())
  {
    outStream << label << "1 STRING-CONSTRUCTED SET has correct card"
              << theSet.toString() << endl;
  }
  else
  {
    outStream << label << "1 ERROR STRING-CONSTRUCTED SET has incorrect card"
              << theSet.toString() << endl;
    exit(0);
  }

  // now we rely on the 'containsElement' function
  for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); ++iter)
  {
    if (!theSet.containsElement(*iter))
    {
      outStream << label << "2 ERROR SET FROM STRING fails to have the proper element "
                << *iter << " " << theSet.toString() << endl;
      exit(0);
    }
  }

  // test the second set
  theSet = Set(str2);
  if (card2 == theSet.card())
  {
    outStream << label << "3 STRING-CONSTRUCTED SET has correct card"
              << theSet.toString() << endl;
  }
  else
  {
    outStream << label << "3 ERROR STRING-CONSTRUCTED SET has incorrect card"
              << theSet.toString() << endl;
    exit(0);
  }

  // test again for specific elements
  // again we assume that the vector and the string have the same values
  for (vector<int>::iterator iter = v2.begin(); iter != v2.end(); ++iter)
  {
    if (!theSet.containsElement(*iter))
    {
      outStream << label << "4 ERROR SET FROM STRING fails to have the proper element "
                << *iter << " " << theSet.toString() << endl;
      exit(0);
    }
  }

  // test the third set that is explicitly an empty set
  theSet = Set(str3);
  if (card3 == theSet.card())
  {
    outStream << label << "3 STRING-CONSTRUCTED SET has correct card"
              << theSet.toString() << endl;
  }
  else
  {
    outStream << label << "3 ERROR STRING-CONSTRUCTED SET has incorrect card"
              << theSet.toString() << endl;
    exit(0);
  }

  // test again for specific elements
  // again we assume that the vector and the string have the same values
  for (vector<int>::iterator iter = v3.begin(); iter != v3.end(); ++iter)
  {
    if (!theSet.containsElement(*iter))
    {
      outStream << label << "4 ERROR SET FROM STRING fails to have the proper element "
                << *iter << " " << theSet.toString() << endl;
      exit(0);
    }
  }

  // one blank line at the end of this test
  outStream << endl;

#ifdef EBUG
  Utils::logStream << TAG << "LEAVE TEST CONSTRUCTOR SET FROM STRING" << endl;
  Utils::logStream.flush();
#endif
} // void SetTester::testConstructorSetFromString(string label, ofstream& outStream)

/****************************************************************
 * Function to test the set from vector constructor.
**/
void SetTester::testConstructorSetFromVector(string label, ofstream& outStream)
{
  Set theSet;

  int card1 = 6;
  int arr1[] = {1, 4, 3, 2, 5, 6};
  vector<int> v1 (arr1, arr1 + sizeof(arr1)/sizeof(int));

  int card2 = 5;
  int arr2[] = {1, 9, 7, 3, 13};
  vector<int> v2 (arr2, arr2 + sizeof(arr2)/sizeof(int));

  int card3 = 0;
  int arr3[] = {};
  vector<int> v3 (arr3, arr3 + sizeof(arr3)/sizeof(int));

#ifdef EBUG
  Utils::logStream << TAG << "ENTER TEST CONSTRUCTOR SET FROM VECTOR " << endl;
  Utils::logStream.flush();
#endif

  outStream << label << "  TEST THE SET FROM VECTOR CONSTRUCTOR" << endl;
  outStream << label << "  INCLUDE 'card' IN THE TEST" << endl;
  outStream << label << "  INCLUDE 'containsElement' IN THE TEST" << endl;

  // test the first set
  theSet = Set(v1);
  if (card1 == theSet.card())
  {
    outStream << label << "1 VECTOR-CONSTRUCTED SET has correct card"
              << theSet.toString() << endl;
  }
  else
  {
    outStream << label << "1 ERROR VECTOR-CONSTRUCTED SET has incorrect card"
              << theSet.toString() << endl;
    exit(0);
  }

  // now we rely on the 'containsElement' function
  for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); ++iter)
  {
    if (!theSet.containsElement(*iter))
    {
      outStream << label << "2 ERROR SET FROM VECTOR fails to have the proper element "
                << *iter << " " << theSet.toString() << endl;
      exit(0);
    }
  }

  // test the second set
  theSet = Set(v2);
  if (card2 == theSet.card())
  {
    outStream << label << "3 VECTOR-CONSTRUCTED SET has correct card"
              << theSet.toString() << endl;
  }
  else
  {
    outStream << label << "3 ERROR VECTOR-CONSTRUCTED SET has incorrect card"
              << theSet.toString() << endl;
    exit(0);
  }

  // test again for specific elements
  for (vector<int>::iterator iter = v2.begin(); iter != v2.end(); ++iter)
  {
    if (!theSet.containsElement(*iter))
    {
      outStream << label << "4 ERROR SET FROM VECTOR fails to have the proper element "
                << *iter << " " << theSet.toString() << endl;
      exit(0);
    }
  }

  // test the third set that is explicitly an empty set
  theSet = Set(v3);
  if (card3 == theSet.card())
  {
    outStream << label << "3 VECTOR-CONSTRUCTED SET has correct card"
              << theSet.toString() << endl;
  }
  else
  {
    outStream << label << "3 ERROR VECTOR-CONSTRUCTED SET has incorrect card"
              << theSet.toString() << endl;
    exit(0);
  }

  // test again for specific elements
  // again we assume that the vector and the string have the same values
  for (vector<int>::iterator iter = v3.begin(); iter != v3.end(); ++iter)
  {
    if (!theSet.containsElement(*iter))
    {
      outStream << label << "4 ERROR SET FROM VECTOR fails to have the proper element "
                << *iter << " " << theSet.toString() << endl;
      exit(0);
    }
  }

  // one blank line at the end of this test
  outStream << endl;

#ifdef EBUG
  Utils::logStream << TAG << "LEAVE TEST CONSTRUCTOR SET FROM VECTOR" << endl;
  Utils::logStream.flush();
#endif
} // void SetTester::testConstructorSetFromString(string label, ofstream& outStream)

/****************************************************************
 * Function to test the set from set constructor.
**/
void SetTester::testConstructorSetFromSet(string label, ofstream& outStream)
{
  Set theSet;
  Set theSetFromVector;

  int arr1[] = {1, 4, 3, 2, 5, 6};
  vector<int> v1 (arr1, arr1 + sizeof(arr1)/sizeof(int));

  int arr2[] = {1, 9, 7, 3, 13};
  vector<int> v2 (arr2, arr2 + sizeof(arr2)/sizeof(int));

  int arr3[] = {};
  vector<int> v3 (arr3, arr3 + sizeof(arr3)/sizeof(int));

#ifdef EBUG
  Utils::logStream << TAG << "ENTER TEST CONSTRUCTOR SET FROM SET " << endl;
  Utils::logStream.flush();
#endif

  outStream << label << "  TEST THE SET FROM VECTOR CONSTRUCTOR" << endl;
  outStream << label << "  INCLUDE 'card' IN THE TEST" << endl;
  outStream << label << "  INCLUDE 'containsElement' IN THE TEST" << endl;
  outStream << label << "  INCLUDE 'setFromVector' IN THE TEST" << endl;

  // test the first set
  theSetFromVector = Set(v1);
  theSet = Set(theSetFromVector);
  if (theSetFromVector.card() == theSet.card())
  {
    outStream << label << "1 SET-CONSTRUCTED SET has correct card"
              << theSet.toString() << endl;
  }
  else
  {
    outStream << label << "1 ERROR SET-CONSTRUCTED SET has incorrect card"
              << theSet.toString() << endl;
    exit(0);
  }

  // now we rely on the 'containsElement' function
  for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); ++iter)
  {
    if (!theSet.containsElement(*iter))
    {
      outStream << label << "2 ERROR SET FROM SET fails to have the proper element "
                << *iter << " " << theSet.toString() << endl;
      exit(0);
    }
  }

  // test the second set
  theSetFromVector = Set(v2);
  theSet = Set(theSetFromVector);
  if (theSetFromVector.card() == theSet.card())
  {
    outStream << label << "3 SET-CONSTRUCTED SET has correct card"
              << theSet.toString() << endl;
  }
  else
  {
    outStream << label << "3 ERROR SET-CONSTRUCTED SET has incorrect card"
              << theSet.toString() << endl;
    exit(0);
  }

  // test again for specific elements
  for (vector<int>::iterator iter = v2.begin(); iter != v2.end(); ++iter)
  {
    if (!theSet.containsElement(*iter))
    {
      outStream << label << "4 ERROR SET FROM SET fails to have the proper element "
                << *iter << " " << theSet.toString() << endl;
      exit(0);
    }
  }

  // test the third set that is explicitly an empty set
  theSetFromVector = Set(v3);
  theSet = Set(theSetFromVector);
  if (theSetFromVector.card() == theSet.card())
  {
    outStream << label << "3 SET-CONSTRUCTED SET has correct card"
              << theSet.toString() << endl;
  }
  else
  {
    outStream << label << "3 ERROR SET-CONSTRUCTED SET has incorrect card"
              << theSet.toString() << endl;
    exit(0);
  }

  // test again for specific elements
  // again we assume that the vector and the string have the same values
  for (vector<int>::iterator iter = v3.begin(); iter != v3.end(); ++iter)
  {
    if (!theSet.containsElement(*iter))
    {
      outStream << label << "4 ERROR SET FROM SET fails to have the proper element "
                << *iter << " " << theSet.toString() << endl;
      exit(0);
    }
  }

  // one blank line at the end of this test
  outStream << endl;

#ifdef EBUG
  Utils::logStream << TAG << "LEAVE TEST CONSTRUCTOR SET FROM SET" << endl;
  Utils::logStream.flush();
#endif
} // void SetTester::testConstructorSetFromString(string label, ofstream& outStream)

/****************************************************************
 * Function to test the other functions
 *
 * We have already tested the following as part of constructor tests:
 *   addToSet(const int e)
 *   addToSet(vector<int> v)
 *   card
 *   containsElement
 *   getElements() const
 *   isEmpty
 *
 * We need to test the following now:
 *   containsSet(const Set& that) const
 *   equals(const Set& that) const
 *   isContainedIn(const Set& that) const
 *   removeFromSet(int e)
 *   setDifference(const Set& that) const
 *   setIntersection(const Set& that) const
 *   setSymmetricDifference(const Set& that) const
 *   setUnion(const Set& that) const
 *
**/
void SetTester::testFunctions(Scanner& inScanner, ofstream& outStream)
{
#ifdef EBUG
  Utils::logStream << TAG << "ENTER TEST FUNCTIONS" << endl;
  Utils::logStream.flush();
#endif

  this->testFunctionEquals("FA", outStream);

#ifdef EBUG
  Utils::logStream << TAG << "LEAVE TEST FUNCTIONS" << endl;
  Utils::logStream.flush();
#endif
} // void SetTester::testFunctions(Scanner& inScanner, ofstream& outStream)

/****************************************************************
 * Function to test the 'equals' function.
 *
**/
void SetTester::testFunctionEquals(string label, ofstream& outStream)
{
  Set setA;
  Set setB;

#ifdef EBUG
  Utils::logStream << TAG << "ENTER TEST EQUALS" << endl;
  Utils::logStream.flush();
#endif

  outStream << label << "  TEST THE EQUALS FUNCTION" << endl;

  // test two null sets independently constructed to be equal
  setA = Set();
  setB = Set();

  outStream << label << "  NULL SET A " << setA.toString() << endl;
  outStream << label << "  NULL SET B " << setB.toString() << endl;
  if (setA.equals(setB))
  {
    outStream << label << "  NULL SET A tests equals to NULL SET B"
              << endl;
  }
  else
  {
    outStream << label
              << "  ERROR NULL SET A does not test equals to NULL SET B"
              << endl;
    exit(0);
  }

  if (setB.equals(setA))
  {
    outStream << label << "  NULL SET B tests equals to NULL SET A"
              << endl;
  }
  else
  {
    outStream << label
              << "  ERROR NULL SET B does not test equals to NULL SET A"
              << endl;
    exit(0);
  }

  // one blank line at the end of this test
  outStream << endl;

#ifdef EBUG
  Utils::logStream << TAG << "LEAVE TEST EQUALS" << endl;
  Utils::logStream.flush();
#endif
} // void SetTester::testFunctionEquals(Scanner& inScanner, ofstream& outStream)

