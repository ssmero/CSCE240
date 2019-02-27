#include "fib.h"

static const string kTag = "FIB: ";

/****************************************************************
 * Class for doing Fibonacci numbers.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/

/****************************************************************
 * Constructor.
**/
Fib::Fib() {
}

/****************************************************************
 * Destructor.
**/
Fib::~Fib() {
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
 * Function to generate Fibonacci numbers.
 * This computes using the two-step recursion.
 *
 * Parameter:
 *   n - the 'LONG' for which to compute the Fibonacci F(n)
 *
 * Returns:
 *   the value of F(n)
**/
LONG Fib::DoFib(int& level, LONG n) {
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
    string string_n_minus_one = Utils::Format(n-1L, 10);
    Utils::log_stream << "Call " << string_n_minus_one
                     << " at level " << string_level << endl;
    LONG fib_n_minus_one = this->DoFib(level, n-1L);

    string string_n_minus_two = Utils::Format(n-2L, 10);
    Utils::log_stream << "Call " << string_n_minus_two
                     << " at level " << string_level << endl;
    LONG fib_n_minus_two = this->DoFib(level, n-2L);

    --level;
    return fib_n_minus_one + fib_n_minus_two;
  }
}
