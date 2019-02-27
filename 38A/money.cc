#include "money.h"

/****************************************************************
 * Savitch 08-02 program, 'Money' class.
 * Author: Savitch, mods by Duncan Buell
 * Date last modified: 28 September 2009
 *
**/
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
Money::Money(int the_dollars, int the_cents) {
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
 * General functions.
**/
/****************************************************************
 * Function to return only the 'cents' from a 'double' amount.
**/
int Money::CentsPart(double amount) const {
  double double_cents = amount*100;

  //% can misbehave on negatives
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
 * Equals function
**/
bool Money::Equals(const Money& second_operand) const {
  return ((dollars_ == second_operand.dollars_) &&
          (cents_ == second_operand.cents_));
}

/****************************************************************
 * Input function.
 * This uses iostream and cstdlib.
**/
void Money::Input( ) {
  char dollar_sign;
  cin >> dollar_sign; //hopefully
  if (dollar_sign != '$') {
    cout << "No dollar sign in Money input.\n";
    exit(1);
  }

  double amount_as_double;
  cin >> amount_as_double;
  dollars_ = DollarsPart(amount_as_double);
  cents_ = CentsPart(amount_as_double);
}

/****************************************************************
 * Binary minus function.
**/
Money Money::Minus(const Money& amount2) const
{
  int all_cents1 = cents_ + dollars_*100;
  int all_cents2 = amount2.GetCents( ) + amount2.GetDollars( )*100;
  int diff_all_cents = all_cents1 - all_cents2;
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
 * Negation function.
**/
Money Money::Negate() const {
  return Money(-dollars_, -cents_);
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
 * Addition function.
 * This adds a 'Money' value to 'this' value.
**/
Money Money::Plus(const Money& amount2 ) const {
  int all_cents1 = cents_ + dollars_*100;
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
 * Function to round a 'double' to the nearest 'int'.
**/
int Money::Round(double number) const {
    return static_cast<int>(floor(number + 0.5));
}


/****************************************************************
 * Usual 'ToString'
**/
string Money::ToString() const {
  string s = "";

  int abs_dollars = abs(dollars_);
  int abs_cents = abs(cents_);
  if (dollars_ < 0 || cents_ < 0)
    s += "$-";
  else
    s += "$";

  s += Utils::Format(abs_dollars);
    
  if (abs_cents >= 10)
    s += "." + Utils::Format(abs_cents);
  else
    s += ".0" + Utils::Format(abs_cents);

return s;
}

