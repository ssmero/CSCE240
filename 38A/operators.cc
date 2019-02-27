#include "money.h"

/****************************************************************
 * Overloaded '+' operator, not a 'Money' member function.
**/
const Money operator +(const Money& amount1, const Money& amount2) {
  return amount1.Plus(amount2);
}

/****************************************************************
 * Overloaded UNARY '-' operator, not a 'Money' member function.
**/
const Money operator -(const Money& amount) {
//    return Money(-amount.getDollars( ), -amount.getCents( ));
  return amount.Negate();
}

/****************************************************************
 * Overloaded BINARY '-' operator, not a 'Money' member function.
 * This uses 'cstdlib' for the 'abs' function.
**/
const Money operator -(const Money& amount1, const Money& amount2) {
  return amount1.Minus(amount2);
}

/****************************************************************
 * Overloaded '==' operator, not a 'Money' member function.
**/
bool operator ==(const Money& amount1, const Money& amount2) {
  return amount1.Equals(amount2);
}

/****************************************************************
 * Overloaded '<<' operator, not a 'Money' member function.
**/
ostream& operator <<(ostream& output_stream, const Money& amount2) {
  output_stream << amount2.ToString();
  return output_stream;
}
