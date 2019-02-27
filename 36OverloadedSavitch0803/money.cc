/****************************************************************
 * Savitch 08-02 program, 'Money' class.
 * Author: Savitch, mods by Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/
#include "money.h"

/****************************************************************
 * Constructors.
**/
/****************************************************************
 * Default constructor, with default zero values.
**/
Money::Money( ): dollars_(0), cents_(0)
{/*Body intentionally empty.*/}

/****************************************************************
 * Constructor, with 'double' value as parameter.
**/
Money::Money(double amount)
              : dollars_(DollarsPart(amount)), cents_(CentsPart(amount))
{/*Body intentionally empty*/}

/****************************************************************
 * Constructor, with 'int' dollars value as parameter, defaulting
 * to zero cents.
**/
Money::Money(int the_dollars)
              : dollars_(the_dollars), cents_(0)
{/*Body intentionally empty*/}

/****************************************************************
 * Constructor, with 'int' dollars and cents values as parameters.
 * This uses 'cstdlib' for the 'cout' function.
**/
Money::Money(int the_dollars, int the_cents)
{
  if ((the_dollars < 0 && the_cents > 0) ||
      (the_dollars > 0 && the_cents < 0))
  {
    cout << "Inconsistent money data.\n";
    exit(1);
  }
  dollars_ = the_dollars;
  cents_ = the_cents;
}

/****************************************************************
 * Accessors.
 * Note that there are no mutators; setting of all class values
 * is done by the constructors.
**/
double Money::GetAmount( ) const {
  return (dollars_ + cents_*0.01);
}

int Money::GetCents( ) const {
  return cents_;
}

int Money::GetDollars( ) const {
  return dollars_;
}

/****************************************************************
 * Overloaded operators.
**/
/****************************************************************
 * Overloaded '+' operator, as a 'Money' member function.
 * NOTE: here as also below, we can operate directly on the
 * 'dollars' and 'cents' variables.
const Money Money::operator +(const Money& secondOperand) const
{
    int allCents1 = cents + dollars*100;
    int allCents2 = secondOperand.cents + secondOperand.dollars*100;
    int sumAllCents = allCents1 + allCents2;
    int absAllCents = abs(sumAllCents); //Money can be negative.
    int finalDollars = absAllCents/100;
    int finalCents = absAllCents%100;

    if (sumAllCents < 0)
    {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }

    return Money(finalDollars, finalCents);
}
**/

/****************************************************************
 * Overloaded UNARY '-' operator, as a 'Money' member function.
const Money Money::operator -( ) const
{
    return Money(-dollars, -cents);
}
**/

/****************************************************************
 * Overloaded BINARY '-' operator, as a 'Money' member function.
const Money Money::operator -(const Money& secondOperand) const
{
    int allCents1 = cents + dollars*100;
    int allCents2 = secondOperand.cents 
                    + secondOperand.dollars*100;
    int diffAllCents = allCents1 - allCents2;
    int absAllCents = abs(diffAllCents); 
    int finalDollars = absAllCents/100;
    int finalCents = absAllCents%100;

    if (diffAllCents < 0)
    {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }

    return Money(finalDollars, finalCents);
}
**/

/****************************************************************
 * Overloaded '==' operator, as a 'Money' member function.
bool Money::operator ==(const Money& secondOperand) const
{
    return ((dollars == secondOperand.dollars)
            && (cents == secondOperand.cents));
}
**/

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function to return only the 'cents' from a 'double' amount.
**/
int Money::CentsPart(double amount) const {
  double double_cents = amount*100;
  // can misbehave on negatives
  int int_cents = (Round(fabs(double_cents)))%100;
  if (amount < 0)
    int_cents = -int_cents;
  return int_cents;
}

/****************************************************************
 * Function to return only the 'dollars' from a 'double' amount.
**/
int Money::DollarsPart(double amount) const {
  return static_cast<int>(amount);
}

/****************************************************************
 * Input function.
 * This uses iostream and cstdlib.
**/
void Money::Input( ) {
  char dollar_sign;
  cin >> dollar_sign; //hopefully
  if (dollar_sign != '$')
  {
    cout << "No dollar sign in Money input.\n";
    exit(1);
  }

  double amount_as_double;
  cin >> amount_as_double;
  dollars_ = DollarsPart(amount_as_double);
  cents_ = CentsPart(amount_as_double);
}

/****************************************************************
 * Output function.
 * This uses iostream and cstdlib.
**/
void Money::Output( ) const {
  int abs_dollars = abs(dollars_);
  int abs_cents = abs(cents_);
  if (dollars_ < 0 || cents_ < 0)//accounts for dollars == 0 or cents == 0
    cout << "$-";
  else
    cout << '$';
  cout << abs_dollars;

  if (abs_cents >= 10)
    cout << '.' << abs_cents;
  else
    cout << '.' << '0' << abs_cents;
}

/****************************************************************
 * Function to round a 'double' to the nearest 'int'.
**/
int Money::Round(double number) const {
  return static_cast<int>(floor(number + 0.5));
}
