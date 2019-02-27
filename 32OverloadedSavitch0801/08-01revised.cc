/****************************************************************
 * Savitch 08-01 program.
 * Author: Savitch, mods by Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

/****************************************************************
 * Class for amounts of money.
 *
 * The big deal here is that input is read with dollar signs and
 * that the value of money is kept with separate 'int' variables
 * 'dollars' and 'cents'.  Money is always delicate since the
 * binary/decimal conversion is inexact for the cents. 
**/
class Money {
public:
 Money( );
 Money(double amount);
 Money(int the_dollars, int the_cents);
 Money(int the_dollars);

 double GetAmount( ) const;
 int GetCents( ) const;
 int GetDollars( ) const;
 void Input( ); //Reads the dollar sign as well as the amount number.
 void Output( ) const;

private:
 int dollars_; // A negative amount is represented as negative dollars
 int cents_;   // and negative cents. Negative $4.50 is represented as
               // -4 and -50
               // NOTE TO 240 STUDENTS:  this (-4 and -50 instead of,
               // say, -5 and +50), is an example of a "gotcha" that
               // has to be documented.

 int DollarsPart(double amount) const;
 int CentsPart(double amount) const;
 int Round(double number) const;
};

/****************************************************************
 * Declaration of overloaded operators.
 * NOTE: These are *not* member functions of the 'Money' class. 
**/
const Money operator +(const Money& amount1, const Money& amount2);
const Money operator -(const Money& amount1, const Money& amount2);
bool operator ==(const Money& amount1, const Money& amount2);
const Money operator -(const Money& amount);

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
 * Overloaded '+' operator, not a 'Money' member function.
**/
const Money operator +(const Money& amount1, const Money& amount2) {
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
const Money operator -(const Money& amount1, const Money& amount2) {
    int all_cents1 = amount1.GetCents( ) + amount1.GetDollars( )*100;
    int all_cents2 = amount2.GetCents( ) + amount2.GetDollars( )*100;
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
 * Overloaded '==' operator, not a 'Money' member function.
**/
bool operator ==(const Money& amount1, const Money& amount2) {
    return ((amount1.GetDollars( ) == amount2.GetDollars( ))
           && (amount1.GetCents( ) == amount2.GetCents( )));
}

/****************************************************************
 * Member functions of the 'Money' class.
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
              : dollars_(DollarsPart(amount)),
                cents_(CentsPart(amount))
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
    int int_cents = (Round(fabs(double_cents))) % 100;
    if (amount < 0)
        int_cents = -int_cents;
    return int_cents;
}

/****************************************************************
 * Function to return only the 'dollars' from a 'double' amount.
**/
int Money::DollarsPart(double amount) const
{
    return static_cast<int>(amount);
}

/****************************************************************
 * Input function.
 * This uses iostream and cstdlib.
**/
void Money::Input( ) {
    char dollar_sign;
    cin >> dollar_sign; //hopefully [THIS IS BAD DOCUMENTATION (DAB)]
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
void Money::Output( ) const
{
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
 * NOTE THAT THIS ROUNDS NEGATIVE NUMBERS DOWN; IT IS THE ACTUAL
 * MATHEMATICAL 'INTEGER PART' FUNCTION.
**/
int Money::Round(double number) const {
    return static_cast<int>(floor(number + 0.5));
}


