#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

/****************************************************************
 * Savitch 08-02 program.
 * Author: Savitch, mods by Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/

/****************************************************************
 * Class for amounts of money.
 *
 * The big deal here is that input is read with dollar signs and
 * that the value of money is kept with separate 'int' variables
 * 'dollars' and 'cents'.  Money is always delicate since the
 * binary/decimal conversion is inexact for the cents. 
 *
 * The difference between this class and that of 08-01 is that
 * in this class the overloaded operators are done with member
 * functions.
**/
class Money {
public:
 Money( );
 Money(double amount);
 Money(int dollars, int cents);
 Money(int dollars);

 double GetAmount( ) const;
 int GetCents( ) const;
 int GetDollars( ) const;
 void Input( ); //Reads the dollar sign as well as the amount number.
 void Output( ) const;

/****************************************************************
 * These next four functions are the overloaded operators.
**/
 const Money operator +(const Money& amount2) const;
 const Money operator -(const Money& amount2) const;
 bool operator ==(const Money& amount2) const;
 const Money operator -( ) const;

private:
 int dollars_; //A negative amount is represented as negative dollars and
 int cents_; //negative cents. Negative $4.50 is represented as -4 and -50

 int DollarsPart(double amount) const;
 int CentsPart(double amount) const;
 int Round(double number) const;
};

/****************************************************************
 * The main function.
**/
int main( ) {
    Money your_amount, my_amount(10, 9);
    cout << "Enter an amount of money: ";
    your_amount.Input( );

    cout << "Your amount is "; 
    your_amount.Output( ); 
    cout << endl;
    cout << "My amount is "; 
    my_amount.Output( ); 
    cout << endl;

    if (your_amount == my_amount)
        cout << "We have the same amounts.\n";
    else
        cout << "One of us is richer.\n";

    Money our_amount = your_amount + my_amount;
    your_amount.Output( ); cout << " + "; my_amount.Output( ); 
    cout << " equals "; our_amount.Output( ); cout << endl;

    Money diff_amount = your_amount - my_amount;
    your_amount.Output( ); cout << " - "; my_amount.Output( ); 
    cout << " equals "; diff_amount.Output( ); cout << endl;

    return 0;
}

/****************************************************************
 * Overloaded '+' operator, as a 'Money' member function.
 * NOTE: here as also below, we can operate directly on the
 * 'dollars' and 'cents' variables.
**/
const Money Money::operator +(const Money& secondOperand) const {
    int all_cents1 = cents_ + dollars_*100;
    int all_cents2 = secondOperand.cents_ + secondOperand.dollars_*100;
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
 * Overloaded UNARY '-' operator, as a 'Money' member function.
**/
const Money Money::operator -( ) const {
    return Money(-dollars_, -cents_);
}

/****************************************************************
 * Overloaded BINARY '-' operator, as a 'Money' member function.
**/
const Money Money::operator -(const Money& second_operand) const {
    int all_cents1 = cents_ + dollars_*100;
    int all_cents2 = second_operand.cents_ +
                     second_operand.dollars_*100;
    int diff_all_cents = all_cents1 - all_cents2;
    int abs_all_cents = abs(diff_all_cents); 
    int final_dollars = abs_all_cents/100;
    int final_cents = abs_all_cents%100;

    if (diff_all_cents < 0) {
        final_dollars = -final_dollars;
        final_cents = -final_cents;
    }

    return Money(final_dollars, final_cents);
}

/****************************************************************
 * Overloaded '==' operator, as a 'Money' member function.
**/
bool Money::operator ==(const Money& second_operand) const {
    return ((dollars_ == second_operand.dollars_) &&
            (cents_ == second_operand.cents_));
}


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
              : dollars_(DollarsPart(amount)),
                cents_(CentsPart(amount))
{/*Body intentionally empty*/}

/****************************************************************
 * Constructor, with 'int' dollars value as parameter, defaulting
 * to zero cents.
**/
Money::Money(int the_dollars)
              : dollars_(the_dollars), cents_(0) {/*Body intentionally empty*/}

/****************************************************************
 * Constructor, with 'int' dollars and cents values as parameters.
 * This uses 'cstdlib' for the 'cout' function.
**/
Money::Money(int the_dollars, int the_cents) {
    if ((the_dollars < 0 && the_cents > 0) ||
        (the_dollars > 0 && the_cents < 0)) {
        cout << "Inconsistent money data.\n";
        exit(1);
    }
    dollars_ = the_dollars;
    cents_ = the_cents;
}

/****************************************************************
 * Accessors.
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
 * General functions.
**/
/****************************************************************
 * Function to return only the 'cents' from a 'double' amount.
**/
int Money::CentsPart(double amount) const {
    double double_cents = amount*100;

    // the following can misbehave on negatives
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
