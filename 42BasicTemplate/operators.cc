#include "record.h"

/****************************************************************
 * Overloaded '<<' operator, not a member function.
**/
ostream& operator <<(ostream& output_stream, const Record& the_record) {
  output_stream << the_record.ToString();
  return output_stream;
}
