#include "settester.h"

static const string kTag = "SETTESTER: ";

/****************************************************************
 * Class for testing sets.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 13 May 2016
**/

/****************************************************************
 * Constructor.
**/
SetTester::SetTester() {
}

/****************************************************************
 * Destructor.
**/
SetTester::~SetTester() {
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
void SetTester::dumpSet(string label, const Set& the_set,
                        ofstream& out_stream) {
#ifdef EBUG
  Utils::log_stream << kTag << "ENTER DUMPSET " << endl;
  Utils::log_stream.flush();
#endif

  out_stream << kTag << label << " (" << the_set.Card()
            << ")" << the_set.ToString() << endl;
  out_stream.flush();

#ifdef EBUG
  Utils::log_stream << kTag << "LEAVE DUMPSET " << endl;
  Utils::log_stream.flush();
#endif

}

/****************************************************************
 * Function to test constructors
**/
void SetTester::TestConstructors(Scanner& in_scanner,
                                 ofstream& out_stream) {
//  string line;
//  ScanLine scanline;

  this->TestConstructorsWhiteBox(out_stream);

} // void SetTester::testConstructors()

/****************************************************************
 * Function to test the constructors.
**/
void SetTester::TestConstructorsWhiteBox(ofstream& out_stream) {
#ifdef EBUG
  Utils::log_stream << kTag << "ENTER TEST CONSTRUCTORS WHITE BOX " << endl;
  Utils::log_stream.flush();
#endif

  out_stream << "TEST THE CONSTRUCTORS" << endl;

  TestConstructorDefault("A", out_stream);
  TestConstructorSingleton("B", out_stream);
  TestConstructorSetFromString("C", out_stream);
  TestConstructorSetFromVector("D", out_stream);
  TestConstructorSetFromSet("E", out_stream);

#ifdef EBUG
  Utils::log_stream << kTag << "LEAVE TEST CONSTRUCTORS WHITE BOX " << endl;
  Utils::log_stream.flush();
#endif

} // void SetTester::TestConstructorsWhiteBox(ofstream& out_stream)

/****************************************************************
 * Function to test the default constructor.
**/
void SetTester::TestConstructorDefault(string label,
                                       ofstream& out_stream) {
  Set the_set;
#ifdef EBUG
  Utils::log_stream << kTag << "ENTER TEST CONSTRUCTOR DEFAULT " << endl;
  Utils::log_stream.flush();
#endif

  out_stream << label << "  TEST THE DEFAULT CONSTRUCTOR" << endl;
  out_stream << label << "  INCLUDE 'isEmpty' IN THE TEST" << endl;

  for (int i = 1; i <= 5; ++i) {
    the_set = Set();
    out_stream << label << "  NULL SET " << the_set.ToString() << endl;
    if (the_set.IsEmpty()) {
      out_stream << label << "  NULL SET does test as empty"
                << the_set.ToString() << endl;
    }
    else {
      out_stream << label << "  ERROR NULL SET does not test as empty"
                << the_set.ToString() << endl;
      exit(0);
    }
  }

  // one blank line at the end of this test
  out_stream << endl;

#ifdef EBUG
  Utils::log_stream << kTag << "LEAVE TEST CONSTRUCTOR DEFAULT" << endl;
  Utils::log_stream.flush();
#endif
} // void SetTester::TestConstructorDefault(ofstream& out_stream)

/****************************************************************
 * Function to test the singleton constructor.
**/
void SetTester::TestConstructorSingleton(string label, ofstream& out_stream)
{
  Set the_set;
#ifdef EBUG
  Utils::log_stream << kTag << "ENTER TEST CONSTRUCTOR SINGLETON " << endl;
  Utils::log_stream.flush();
#endif

  out_stream << label << "  TEST THE SINGLETON CONSTRUCTOR" << endl;
  out_stream << label << "  INCLUDE 'card' IN THE TEST" << endl;
  out_stream << label << "  INCLUDE 'ContainsElement' IN THE TEST" << endl;

  for (int i = 1; i <= 5; ++i) {
    // create the set
    the_set = Set(i);

    // test cardinality
    if (1 == the_set.Card())
    {
      out_stream << "B  SINGLETON SET has card 1"
                << the_set.ToString() << endl;
    }
    else
    {
      out_stream << "B  ERROR SINGLETON SET has card not 1"
                << the_set.ToString() << endl;
      exit(0);
    }

    // now let's test the 'is an element of' function
    if (!the_set.ContainsElement(i))
    {
      out_stream << "B  ERROR SINGLETON SET fails to have the proper element "
                << i << " " << the_set.ToString() << endl;
      exit(0);
    }
  }

  // one blank line at the end of this test
  out_stream << endl;

#ifdef EBUG
  Utils::log_stream << kTag << "LEAVE TEST CONSTRUCTOR SINGLETON" << endl;
  Utils::log_stream.flush();
#endif
} // void SetTester::TestConstructorSingleton(ofstream& out_stream)

/****************************************************************
 * Function to test the set from string constructor.
**/
void SetTester::TestConstructorSetFromString(string label,
                                             ofstream& out_stream)
{
  Set the_set;

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
  Utils::log_stream << kTag << "ENTER TEST CONSTRUCTOR SET FROM STRING " << endl;
  Utils::log_stream.flush();
#endif

  out_stream << label << "  TEST THE SET FROM STRING CONSTRUCTOR" << endl;
  out_stream << label << "  INCLUDE 'card' IN THE TEST" << endl;
  out_stream << label << "  INCLUDE 'ContainsElement' IN THE TEST" << endl;

  // test the first set
  the_set = Set(str1);
  if (card1 == the_set.Card()) {
    out_stream << label << "1 STRING-CONSTRUCTED SET has correct card"
              << the_set.ToString() << endl;
  }
  else {
    out_stream << label << "1 ERROR STRING-CONSTRUCTED SET has incorrect card"
              << the_set.ToString() << endl;
    exit(0);
  }

  // now we rely on the 'ContainsElement' function
  for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); ++iter) {
    if (!the_set.ContainsElement(*iter)) {
      out_stream << label
                 << "2 ERROR SET FROM STRING fails to have the proper element "
                << *iter << " " << the_set.ToString() << endl;
      exit(0);
    }
  }

  // test the second set
  the_set = Set(str2);
  if (card2 == the_set.Card()) {
    out_stream << label << "3 STRING-CONSTRUCTED SET has correct card"
              << the_set.ToString() << endl;
  }
  else {
    out_stream << label << "3 ERROR STRING-CONSTRUCTED SET has incorrect card"
              << the_set.ToString() << endl;
    exit(0);
  }

  // test again for specific elements
  // again we assume that the vector and the string have the same values
  for (vector<int>::iterator iter = v2.begin(); iter != v2.end(); ++iter)
  {
    if (!the_set.ContainsElement(*iter))
    {
      out_stream << label << "4 ERROR SET FROM STRING fails to have the proper element "
                << *iter << " " << the_set.ToString() << endl;
      exit(0);
    }
  }

  // test the third set that is explicitly an empty set
  the_set = Set(str3);
  if (card3 == the_set.Card())
  {
    out_stream << label << "3 STRING-CONSTRUCTED SET has correct card"
              << the_set.ToString() << endl;
  }
  else
  {
    out_stream << label << "3 ERROR STRING-CONSTRUCTED SET has incorrect card"
              << the_set.ToString() << endl;
    exit(0);
  }

  // test again for specific elements
  // again we assume that the vector and the string have the same values
  for (vector<int>::iterator iter = v3.begin(); iter != v3.end(); ++iter)
  {
    if (!the_set.ContainsElement(*iter))
    {
      out_stream << label << "4 ERROR SET FROM STRING fails to have the proper element "
                << *iter << " " << the_set.ToString() << endl;
      exit(0);
    }
  }

  // one blank line at the end of this test
  out_stream << endl;

#ifdef EBUG
  Utils::log_stream << kTag << "LEAVE TEST CONSTRUCTOR SET FROM STRING" << endl;
  Utils::log_stream.flush();
#endif
} // void SetTester::TestConstructorSetFromString(string label, ofstream& out_stream)

/****************************************************************
 * Function to test the set from vector constructor.
**/
void SetTester::TestConstructorSetFromVector(string label, ofstream& out_stream)
{
  Set the_set;

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
  Utils::log_stream << kTag << "ENTER TEST CONSTRUCTOR SET FROM VECTOR " << endl;
  Utils::log_stream.flush();
#endif

  out_stream << label << "  TEST THE SET FROM VECTOR CONSTRUCTOR" << endl;
  out_stream << label << "  INCLUDE 'card' IN THE TEST" << endl;
  out_stream << label << "  INCLUDE 'ContainsElement' IN THE TEST" << endl;

  // test the first set
  the_set = Set(v1);
  if (card1 == the_set.Card()) {
    out_stream << label << "1 VECTOR-CONSTRUCTED SET has correct card"
              << the_set.ToString() << endl;
  }
  else {
    out_stream << label << "1 ERROR VECTOR-CONSTRUCTED SET has incorrect card"
              << the_set.ToString() << endl;
    exit(0);
  }

  // now we rely on the 'ContainsElement' function
  for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); ++iter) {
    if (!the_set.ContainsElement(*iter)) {
      out_stream << label << "2 ERROR SET FROM VECTOR fails to have the proper element "
                << *iter << " " << the_set.ToString() << endl;
      exit(0);
    }
  }

  // test the second set
  the_set = Set(v2);
  if (card2 == the_set.Card()) {
    out_stream << label << "3 VECTOR-CONSTRUCTED SET has correct card"
              << the_set.ToString() << endl;
  }
  else {
    out_stream << label << "3 ERROR VECTOR-CONSTRUCTED SET has incorrect card"
              << the_set.ToString() << endl;
    exit(0);
  }

  // test again for specific elements
  for (vector<int>::iterator iter = v2.begin(); iter != v2.end(); ++iter) {
    if (!the_set.ContainsElement(*iter)) {
      out_stream << label << "4 ERROR SET FROM VECTOR fails to have the proper element "
                << *iter << " " << the_set.ToString() << endl;
      exit(0);
    }
  }

  // test the third set that is explicitly an empty set
  the_set = Set(v3);
  if (card3 == the_set.Card()) {
    out_stream << label << "3 VECTOR-CONSTRUCTED SET has correct card"
              << the_set.ToString() << endl;
  }
  else {
    out_stream << label << "3 ERROR VECTOR-CONSTRUCTED SET has incorrect card"
              << the_set.ToString() << endl;
    exit(0);
  }

  // test again for specific elements
  // again we assume that the vector and the string have the same values
  for (vector<int>::iterator iter = v3.begin(); iter != v3.end(); ++iter) {
    if (!the_set.ContainsElement(*iter)) {
      out_stream << label << "4 ERROR SET FROM VECTOR fails to have the proper element "
                << *iter << " " << the_set.ToString() << endl;
      exit(0);
    }
  }

  // one blank line at the end of this test
  out_stream << endl;

#ifdef EBUG
  Utils::log_stream << kTag << "LEAVE TEST CONSTRUCTOR SET FROM VECTOR" << endl;
  Utils::log_stream.flush();
#endif
} // void SetTester::TestConstructorSetFromString(string label, ofstream& out_stream)

/****************************************************************
 * Function to test the set from set constructor.
**/
void SetTester::TestConstructorSetFromSet(string label, ofstream& out_stream)
{
  Set the_set;
  Set the_set_from_vector;

  int arr1[] = {1, 4, 3, 2, 5, 6};
  vector<int> v1 (arr1, arr1 + sizeof(arr1)/sizeof(int));

  int arr2[] = {1, 9, 7, 3, 13};
  vector<int> v2 (arr2, arr2 + sizeof(arr2)/sizeof(int));

  int arr3[] = {};
  vector<int> v3 (arr3, arr3 + sizeof(arr3)/sizeof(int));

#ifdef EBUG
  Utils::log_stream << kTag << "ENTER TEST CONSTRUCTOR SET FROM SET " << endl;
  Utils::log_stream.flush();
#endif

  out_stream << label << "  TEST THE SET FROM VECTOR CONSTRUCTOR" << endl;
  out_stream << label << "  INCLUDE 'card' IN THE TEST" << endl;
  out_stream << label << "  INCLUDE 'ContainsElement' IN THE TEST" << endl;
  out_stream << label << "  INCLUDE 'setFromVector' IN THE TEST" << endl;

  // test the first set
  the_set_from_vector = Set(v1);
  the_set = Set(the_set_from_vector);
  if (the_set_from_vector.Card() == the_set.Card())
  {
    out_stream << label << "1 SET-CONSTRUCTED SET has correct card"
              << the_set.ToString() << endl;
  }
  else
  {
    out_stream << label << "1 ERROR SET-CONSTRUCTED SET has incorrect card"
              << the_set.ToString() << endl;
    exit(0);
  }

  // now we rely on the 'ContainsElement' function
  for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); ++iter)
  {
    if (!the_set.ContainsElement(*iter))
    {
      out_stream << label << "2 ERROR SET FROM SET fails to have the proper element "
                << *iter << " " << the_set.ToString() << endl;
      exit(0);
    }
  }

  // test the second set
  the_set_from_vector = Set(v2);
  the_set = Set(the_set_from_vector);
  if (the_set_from_vector.Card() == the_set.Card())
  {
    out_stream << label << "3 SET-CONSTRUCTED SET has correct card"
              << the_set.ToString() << endl;
  }
  else
  {
    out_stream << label << "3 ERROR SET-CONSTRUCTED SET has incorrect card"
              << the_set.ToString() << endl;
    exit(0);
  }

  // test again for specific elements
  for (vector<int>::iterator iter = v2.begin(); iter != v2.end(); ++iter)
  {
    if (!the_set.ContainsElement(*iter))
    {
      out_stream << label << "4 ERROR SET FROM SET fails to have the proper element "
                << *iter << " " << the_set.ToString() << endl;
      exit(0);
    }
  }

  // test the third set that is explicitly an empty set
  the_set_from_vector = Set(v3);
  the_set = Set(the_set_from_vector);
  if (the_set_from_vector.Card() == the_set.Card())
  {
    out_stream << label << "3 SET-CONSTRUCTED SET has correct card"
              << the_set.ToString() << endl;
  }
  else
  {
    out_stream << label << "3 ERROR SET-CONSTRUCTED SET has incorrect card"
              << the_set.ToString() << endl;
    exit(0);
  }

  // test again for specific elements
  // again we assume that the vector and the string have the same values
  for (vector<int>::iterator iter = v3.begin(); iter != v3.end(); ++iter)
  {
    if (!the_set.ContainsElement(*iter))
    {
      out_stream << label << "4 ERROR SET FROM SET fails to have the proper element "
                << *iter << " " << the_set.ToString() << endl;
      exit(0);
    }
  }

  // one blank line at the end of this test
  out_stream << endl;

#ifdef EBUG
  Utils::log_stream << kTag << "LEAVE TEST CONSTRUCTOR SET FROM SET" << endl;
  Utils::log_stream.flush();
#endif
} // void SetTester::testConstructorSetFromString(string label, ofstream& out_stream)

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
 * We have tested:
 *   equals(const Set& that) const
 *
 * We need to test the following now:
 *   containsSet(const Set& that) const
 *   isContainedIn(const Set& that) const
 *   removeFromSet(int e)
 *   setDifference(const Set& that) const
 *   setIntersection(const Set& that) const
 *   setSymmetricDifference(const Set& that) const
 *   setUnion(const Set& that) const
 *
**/
void SetTester::TestFunctions(Scanner& in_scanner, ofstream& out_stream)
{
#ifdef EBUG
  Utils::log_stream << kTag << "ENTER TEST FUNCTIONS" << endl;
  Utils::log_stream.flush();
#endif

  this->TestFunctionEquals("FA", out_stream);

#ifdef EBUG
  Utils::log_stream << kTag << "LEAVE TEST FUNCTIONS" << endl;
  Utils::log_stream.flush();
#endif
} // void SetTester::TestFunctions(Scanner& in_scanner, ofstream& out_stream)

/****************************************************************
 * Function to test the 'equals' function.
 *
**/
void SetTester::TestFunctionEquals(string label, ofstream& out_stream)
{
  Set nullSetA, nullSetB;
  Set setA, setB;

#ifdef EBUG
  Utils::log_stream << kTag << "ENTER TEST EQUALS" << endl;
  Utils::log_stream.flush();
#endif

  out_stream << label << "  TEST THE EQUALS FUNCTION" << endl;

  // test two null sets independently constructed to be equal
  nullSetA = Set();
  nullSetB = Set();
  setA = Set();
  setB = Set();

  out_stream << label << "  NULL SET nullSetA " << nullSetA.ToString() << endl;
  out_stream << label << "  NULL SET nullSetB " << nullSetB.ToString() << endl;
  if (nullSetA.Equals(nullSetB))
  {
    out_stream << label << "  NULL SET nullSetA tests equals to NULL SET nullsetB"
              << endl;
  }
  else
  {
    out_stream << label
              << "  ERROR NULL SET nullSetA does not test equals to NULL SET nullsetB"
              << endl;
    exit(0);
  }

  if (nullSetB.Equals(nullSetA))
  {
    out_stream << label << "  NULL SET nullsetB tests equals to nullSetA"
              << endl;
  }
  else
  {
    out_stream << label
              << "  ERROR NULL SET nullsetB does not test equals to nullSetA"
              << endl;
    exit(0);
  }

  int arr1[] = {1, 4, 3, 2, 5, 6};
  vector<int> v1 (arr1, arr1 + sizeof(arr1)/sizeof(int));
  setA = Set(v1);
  setB = Set(v1);
  out_stream << label << "  SET setA " << setA.ToString() << endl;
  out_stream << label << "  SET setB " << setB.ToString() << endl;
  if (!setA.Equals(nullSetA))
  {
    out_stream << label << "  SET setA tests unequal to nullSetA"
              << endl;
  }
  else
  {
    out_stream << label
              << "  ERROR SET setA does not test unequal to nullSetA"
              << endl;
    exit(0);
  }

  if (setA.Equals(setB))
  {
    out_stream << label << "  SET setA tests equal to setB"
              << endl;
  }
  else
  {
    out_stream << label
              << "  ERROR SET setA does not test equal to setB"
              << endl;
    exit(0);
  }

  // one blank line at the end of this test
  out_stream << endl;

#ifdef EBUG
  Utils::log_stream << kTag << "LEAVE TEST EQUALS" << endl;
  Utils::log_stream.flush();
#endif
} // void SetTester::TestFunctionEquals(Scanner& in_scanner, ofstream& out_stream)

