#include "factorial.h"

static const string kTag = "FACTORIAL: ";

/****************************************************************
 * Class for doing Factorials.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/

/****************************************************************
 * Constructor.
**/
Factorial::Factorial() {
}

/****************************************************************
 * Destructor.
**/
Factorial::~Factorial() {
}

/****************************************************************
 * Accessors and mutators.
**/
/****************************************************************
 *
**/
/****************************************************************
 * General functions.
**/

/****************************************************************
 * Function to generate Factorials.
 *
 * Parameter:
 *   n - the 'LONG' for which to compute Factorial(n)
 *
 * Returns:
 *   the value of Factorial(n)
**/
LONG Factorial::DoFactorial(int& level, LONG n) {
  LONG return_value = 0L;

  ++level;
  string string_level = Utils::Format(level, 10);

  assert(n > 0);

  if((0L == n) || (1L == n))
  {
    Utils::log_stream << "Return 1 at level " << string_level << endl;
    Utils::log_stream << Utils::TimeCall(string_level);
    --level;
    return 1L;
  }
  else
  {
    string string_minus_one = Utils::Format(n-1L, 10);
    Utils::log_stream << "Call " << string_minus_one
                      << " at level " << string_level << endl;
    return_value = n * this->DoFactorial(level, n-1L);

    Utils::log_stream << "Return " << Utils::Format(return_value, 15)
                      << " at level " << string_level << endl;
    --level;
    return return_value;
  }
}
