#include "main.h"

static const string kTag = "MAIN: ";

/****************************************************************
 * Savitch 08-02 program.
 * Author: Savitch, mods by Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/
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

  if (sum_all_cents < 0) {
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
