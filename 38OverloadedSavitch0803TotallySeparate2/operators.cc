#include "money.h"

/****************************************************************
 * Overloaded '+' operator, not a 'Money' member function.
**/
const Money operator +(const Money& amount1, const Money& amount2)
{
  int all_cents1 = amount1.GetCents( ) + amount1.GetDollars( )*100;
  int all_cents2 = amount2.GetCents( ) + amount2.GetDollars( )*100;
  int sum_all_cents = all_cents1 + all_cents2;
  int abs_all_cents = abs(sum_all_cents); //Money can be negative.
  int final_dollars = abs_all_cents/100;
  int final_cents = abs_all_cents%100;

  if (sum_all_cents < 0)
  {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }

  return Money(final_dollars, final_cents);
}

/****************************************************************
 * Overloaded UNARY '-' operator, not a 'Money' member function.
**/
const Money operator -(const Money& amount) {
  return Money(-amount.GetDollars( ), -amount.GetCents( ));
}

/****************************************************************
 * Overloaded BINARY '-' operator, not a 'Money' member function.
 * This uses 'cstdlib' for the 'abs' function.
**/
const Money operator -(const Money& amount1, const Money& amount2)
{
  int allCents1 = amount1.GetCents( ) + amount1.GetDollars( )*100;
  int allCents2 = amount2.GetCents( ) + amount2.GetDollars( )*100;
  int diff_all_cents = allCents1 - allCents2;
  int abs_all_cents = abs(diff_all_cents); 
  int final_dollars = abs_all_cents/100;
  int final_cents = abs_all_cents%100;

  if (diff_all_cents < 0)
  {
      final_dollars = -final_dollars;
      final_cents = -final_cents;
  }

  return Money(final_dollars, final_cents);
}

/****************************************************************
 * Overloaded '==' operator, not a 'Money' member function.
**/
bool operator ==(const Money& amount1, const Money& amount2) {
    return ((amount1.GetDollars( ) == amount2.GetDollars( ))
           && (amount1.GetCents( ) == amount2.GetCents( )));
}

/****************************************************************
 * Overloaded '<<' operator, not a 'Money' member function.
**/
ostream& operator <<(ostream& output_stream, const Money& amount2) {
    int abs_dollars = abs(amount2.dollars_);
    int abs_cents = abs(amount2.cents_);
    if (amount2.dollars_ < 0 || amount2.cents_ < 0)//accounts for dollars == 0 or cents == 0
      output_stream << "$-";
    else
      output_stream << '$';
    output_stream << abs_dollars;

    if (abs_cents >= 10)
      output_stream << '.' << abs_cents;
    else
      output_stream << '.' << '0' << abs_cents;

  return output_stream;
}
