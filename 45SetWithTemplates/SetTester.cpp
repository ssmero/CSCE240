#include "SetTester.h"
/****************************************************************
 * Class for testing sets.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Date: 5 October 2013
 *
**/

static const string TESTERTAG = "SetTester: ";

/****************************************************************
 * Constructor.
**/
template<typename T> SetTester<T>::SetTester()
{
}

/****************************************************************
 * Destructor.
**/
template<typename T> SetTester<T>::~SetTester()
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
template<typename T> void SetTester<T>::dumpSet(string label, const Set<T>& theSet, ofstream& outStream)
{
#ifdef EBUG
  Utils::logStream << TESTERTAG << "ENTER DUMPSET " << endl;
  Utils::logStream.flush();
#endif

  outStream << TESTERTAG << label << " (" << theSet.card() << ")" << theSet.toString() << endl;
  outStream.flush();

#ifdef EBUG
  Utils::logStream << TESTERTAG << "LEAVE DUMPSET " << endl;
  Utils::logStream.flush();
#endif

}

/****************************************************************
 * Function to test constructors
**/
template<typename T> void SetTester<T>::testConstructors(Scanner& inScanner, ofstream& outStream)
{
  string line;
  ScanLine scanLine;

  Set<T> newSet;
  Set<T> oldSet;

  this->testConstructorsWhiteBox(outStream);

} // void SetTester<T>::testConstructors()

/****************************************************************
 * Function to test the constructors.
**/
template<typename T> void SetTester<T>::testConstructorsWhiteBox(ofstream& outStream)
{
#ifdef EBUG
  Utils::logStream << TESTERTAG << "ENTER TEST CONSTRUCTORS WHITE BOX " << endl;
  Utils::logStream.flush();
#endif

  outStream << "TEST THE CONSTRUCTORS" << endl;

  testConstructorDefault("A", outStream);
  testConstructorSingleton("B", outStream);
//  testConstructorSetFromString("C", outStream);
  testConstructorSetFromVector("D", outStream);
//  testConstructorSetFromSet("E", outStream);

#ifdef EBUG
  Utils::logStream << TESTERTAG << "LEAVE TEST CONSTRUCTORS WHITE BOX " << endl;
  Utils::logStream.flush();
#endif

} // void SetTester<T>::testConstructorsWhiteBox(ofstream& outStream)

/****************************************************************
 * Function to test the default constructor.
**/
template<typename T> void SetTester<T>::testConstructorDefault(string label, ofstream& outStream)
{
  Set<T> theSet;
#ifdef EBUG
  Utils::logStream << TESTERTAG << "ENTER TEST CONSTRUCTOR DEFAULT " << endl;
  Utils::logStream.flush();
#endif

  outStream << label << "  TEST THE DEFAULT CONSTRUCTOR" << endl;
  outStream << label << "  INCLUDE 'isEmpty' IN THE TEST" << endl;

  for (int i = 1; i <= 5; ++i)
  {
    theSet = Set<T>();
    outStream << label << "  NULL SET " << theSet.toString() << endl;
    if (theSet.isEmpty())
    {
      outStream << label << "  NULL SET does test as empty" << theSet.toString() << endl;
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
  Utils::logStream << TESTERTAG << "LEAVE TEST CONSTRUCTOR DEFAULT" << endl;
  Utils::logStream.flush();
#endif
} // void SetTester<T>::testConstructorDefault(ofstream& outStream)

/****************************************************************
 * Function to test the singleton constructor.
**/
template<typename T> void SetTester<T>::testConstructorSingleton(string label, ofstream& outStream)
{
  Set<T> theSet;
#ifdef EBUG
  Utils::logStream << TESTERTAG << "ENTER TEST CONSTRUCTOR SINGLETON " << endl;
  Utils::logStream.flush();
#endif

  outStream << label << "  TEST THE SINGLETON CONSTRUCTOR" << endl;
  outStream << label << "  INCLUDE 'card' IN THE TEST" << endl;
  outStream << label << "  INCLUDE 'containsElement' IN THE TEST" << endl;

  for (int i = 1; i <= 5; ++i)
  {
    // create the set
    string element_i = Utils::Format(i);
    theSet = Set<T>(element_i);
//    theSet = Set<T>(i);

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
//    if (!theSet.containsElement(i))
    if (!theSet.containsElement(element_i))
    {
      outStream << "B  ERROR SINGLETON SET fails to have the proper element "
//                << i << " " << theSet.toString() << endl;
                << element_i << " " << theSet.toString() << endl;
      exit(0);
    }
  }

  // one blank line at the end of this test
  outStream << endl;

#ifdef EBUG
  Utils::logStream << TESTERTAG << "LEAVE TEST CONSTRUCTOR SINGLETON" << endl;
  Utils::logStream.flush();
#endif
} // void SetTester<T>::testConstructorSingleton(ofstream& outStream)

/****************************************************************
 * Function to test the set from string constructor.
template<typename T> void SetTester<T>::testConstructorSetFromString(string label, ofstream& outStream)
{
  Set<T> theSet;

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
  Utils::logStream << TESTERTAG << "ENTER TEST CONSTRUCTOR SET FROM STRING " << endl;
  Utils::logStream.flush();
#endif

  outStream << label << "  TEST THE SET FROM STRING CONSTRUCTOR" << endl;
  outStream << label << "  INCLUDE 'card' IN THE TEST" << endl;
  outStream << label << "  INCLUDE 'containsElement' IN THE TEST" << endl;

  // test the first set
  theSet = Set<T>(str1);
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
  theSet = Set<T>(str2);
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
  theSet = Set<T>(str3);
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
  Utils::logStream << TESTERTAG << "LEAVE TEST CONSTRUCTOR SET FROM STRING" << endl;
  Utils::logStream.flush();
#endif
} // void SetTester<T>::testConstructorSetFromString(string label, ofstream& outStream)
**/

/****************************************************************
 * Function to test the set from vector constructor.
**/
template<typename T> void SetTester<T>::testConstructorSetFromVector(string label, ofstream& outStream)
{
  Set<T> theSet;

  int card1 = 6;
//  int arr1[] = {1, 4, 3, 2, 5, 6};
//  vector<int> v1 (arr1, arr1 + sizeof(arr1)/sizeof(int));
  string arr1[] = {"one", "four", "three", "two", "five", "six"};
  vector<string> v1;
  for (int i = 0; i < 6; ++i)
    v1.push_back(arr1[i]);

  int card2 = 5;
//  int arr2[] = {1, 9, 7, 3, 13};
//  vector<int> v2 (arr2, arr2 + sizeof(arr2)/sizeof(int));
  string arr2[] = {"one", "nine", "seven", "three", "thirteen"};
  vector<string> v2;
  for (int i = 0; i < 5; ++i)
    v2.push_back(arr2[i]);

  int card3 = 0;
//  int arr3[] = {};
//  vector<int> v3 (arr3, arr3 + sizeof(arr3)/sizeof(int));
  string arr3[] = {};
  vector<string> v3;

#ifdef EBUG
  Utils::logStream << TESTERTAG << "ENTER TEST CONSTRUCTOR SET FROM VECTOR " << endl;
  Utils::logStream.flush();
#endif

  outStream << label << "  TEST THE SET FROM VECTOR CONSTRUCTOR" << endl;
  outStream << label << "  INCLUDE 'card' IN THE TEST" << endl;
  outStream << label << "  INCLUDE 'containsElement' IN THE TEST" << endl;

  // test the first set
  theSet = Set<T>(v1);
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
//  for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); ++iter)
  for (vector<string>::iterator iter = v1.begin(); iter != v1.end(); ++iter)
  {
    if (!theSet.containsElement(*iter))
    {
      outStream << label << "2 ERROR SET FROM VECTOR fails to have the proper element "
                << *iter << " " << theSet.toString() << endl;
      exit(0);
    }
  }

  // test the second set
  theSet = Set<T>(v2);
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
//  for (vector<int>::iterator iter = v2.begin(); iter != v2.end(); ++iter)
  for (vector<string>::iterator iter = v2.begin(); iter != v2.end(); ++iter)
  {
    if (!theSet.containsElement(*iter))
    {
      outStream << label << "4 ERROR SET FROM VECTOR fails to have the proper element "
                << *iter << " " << theSet.toString() << endl;
      exit(0);
    }
  }

  // test the third set that is explicitly an empty set
  theSet = Set<T>(v3);
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
//  for (vector<int>::iterator iter = v3.begin(); iter != v3.end(); ++iter)
  for (vector<string>::iterator iter = v3.begin(); iter != v3.end(); ++iter)
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
  Utils::logStream << TESTERTAG << "LEAVE TEST CONSTRUCTOR SET FROM VECTOR" << endl;
  Utils::logStream.flush();
#endif
} // void SetTester<T>::testConstructorSetFromString(string label, ofstream& outStream)

/****************************************************************
 * Function to test the set from set constructor.
template<typename T> void SetTester<T>::testConstructorSetFromSet(string label, ofstream& outStream)
{
  Set<T> theSet;
  Set<T> theSetFromVector;

  int arr1[] = {1, 4, 3, 2, 5, 6};
  vector<int> v1 (arr1, arr1 + sizeof(arr1)/sizeof(int));

  int arr2[] = {1, 9, 7, 3, 13};
  vector<int> v2 (arr2, arr2 + sizeof(arr2)/sizeof(int));

  int arr3[] = {};
  vector<int> v3 (arr3, arr3 + sizeof(arr3)/sizeof(int));

#ifdef EBUG
  Utils::logStream << TESTERTAG << "ENTER TEST CONSTRUCTOR SET FROM SET " << endl;
  Utils::logStream.flush();
#endif

  outStream << label << "  TEST THE SET FROM VECTOR CONSTRUCTOR" << endl;
  outStream << label << "  INCLUDE 'card' IN THE TEST" << endl;
  outStream << label << "  INCLUDE 'containsElement' IN THE TEST" << endl;
  outStream << label << "  INCLUDE 'setFromVector' IN THE TEST" << endl;

  // test the first set
  theSetFromVector = Set<T>(v1);
  theSet = Set<T>(theSetFromVector);
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
  theSetFromVector = Set<T>(v2);
  theSet = Set<T>(theSetFromVector);
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
  theSetFromVector = Set<T>(v3);
  theSet = Set<T>(theSetFromVector);
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
  Utils::logStream << TESTERTAG << "LEAVE TEST CONSTRUCTOR SET FROM SET" << endl;
  Utils::logStream.flush();
#endif
} // void SetTester<T>::testConstructorSetFromString(string label, ofstream& outStream)
**/

/****************************************************************
 * Function to test the other functions
 *
 * We have already tested the following as part of constructor tests:
 *   card
 *   containsElement
 *   isEmpty
 *   setFromVector
 *
 * We need to test the following now:
 *   addToSet(const int e)
 *   addToSet(vector<int> v)
 *   containsSet(const Set& that) const
 *   equals(const Set& that) const
 *   getElements() const
 *   isContainedIn(const Set& that) const
 *   removeFromSet(int e)
 *   compareValue(const Set& a, const Set& b)
 *   setDifference(const Set& that) const
 *   setIntersection(const Set& that) const
 *   setSymmetricDifference(const Set& that) const
 *   setUnion(const Set& that) const
 *
**/
template<typename T> void SetTester<T>::testFunctions(Scanner& inScanner, ofstream& outStream)
{
#ifdef EBUG
  Utils::logStream << TESTERTAG << "LEAVE TEST FUNCTIONS" << endl;
  Utils::logStream.flush();
#endif

//  this->testConstructorsWhiteBox(outStream);

#ifdef EBUG
  Utils::logStream << TESTERTAG << "LEAVE TEST FUNCTIONS" << endl;
  Utils::logStream.flush();
#endif
} // void SetTester<T>::testFunctions(Scanner& inScanner, ofstream& outStream)

