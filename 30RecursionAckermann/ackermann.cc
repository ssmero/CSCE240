#include "ackermann.h"

static const string kTag = "ACKERMANN: ";

/****************************************************************
 * Class for doing Ackermann.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/

/****************************************************************
 * Constructor.
**/
Ackermann::Ackermann() {
}

/****************************************************************
 * Destructor.
**/
Ackermann::~Ackermann() {
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
 * Function to generate Ackermann.
 *
 * Parameter:
 *   level - the level of recursion so far
 *   m - the 'm' parameter
 *   n - the 'n' parameter
 *
 * Returns:
 *   the value of Ackermann(m, n)
**/
LONG Ackermann::DoAckermann(int& level, LONG m, LONG n) {
  ++level;
  string string_level = Utils::Format(level, 10);
  string string_m = Utils::Format(m, 10);
  string string_n = Utils::Format(n, 10);
  cout << "level, m, n " << string_level << " " << string_m << " "
       << string_m << endl;

  if(0L == m) {
//    cout << "Return " << Utils::Format(n+1L, 15) << " at level " << stringLevel << endl;
    --level;
    return n+1L;
  } else if((m > 0L) && (0L == n)) {
//    string stringMMinusOne = Utils::Format(m-1L, 15);
//    cout << "Return A(" << stringMMinusOne << ", 1) at level " << stringLevel << endl;
    --level;
    return this->DoAckermann(level, m-1L, 1L);
  } else {
//    cout << "Call at level " << stringLevel << endl;
    --level;
    return this->DoAckermann(level, m-1L, this->DoAckermann(level, m, n-1L));
  }
}
