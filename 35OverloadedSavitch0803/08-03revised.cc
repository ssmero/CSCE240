#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Class for amounts of money in U.S. currency.
class Money {
public:
 Money( );
 Money(double amount);
 Money(int dollars, int cents);
 Money(int dollars);
 double GetAmount( ) const;
 int GetDollars( ) const;
 int GetCents( ) const;
 void Input( ); //Reads the dollar sign as well as the amount number.
 void Output( ) const;
 friend const Money operator +(const Money& amount1, const Money& amount2);
 friend const Money operator -(const Money& amount1, const Money& amount2);
 friend bool operator ==(const Money& amount1, const Money& amount2);
 friend const Money operator -(const Money& amount);

private:
 int dollars_; //A negative amount is represented as negative dollars and
 int cents_; //negative cents. Negative $4.50 is represented as -4 and -50

 int DollarsPart(double amount) const;
 int CentsPart(double amount) const;
 int Round(double number) const;
};

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


const Money operator +(const Money& amount1, const Money& amount2) {
  int all_cents = amount1.cents_ + amount1.dollars_*100;
  int all_cents2 = amount2.cents_ + amount2.dollars_*100;
  int sum_all_cents = all_cents + all_cents2;
  int abs_all_cents = abs(sum_all_cents); //Money can be negative.
  int final_dollars = abs_all_cents/100;
  int final_cents = abs_all_cents%100;

  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }

  return Money(final_dollars, final_cents);
}

//Uses cstdlib:
const Money operator -(const Money& amount1, const Money& amount2) {
  int all_cents = amount1.cents_ + amount1.dollars_*100;
  int all_cents2 = amount2.cents_ + amount2.dollars_*100;
  int diff_all_cents = all_cents - all_cents2;
  int abs_all_cents = abs(diff_all_cents); 

  int final_dollars = abs_all_cents/100;
  int final_cents = abs_all_cents%100;

  if (diff_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }

  return Money(final_dollars, final_cents);
}

bool operator ==(const Money& amount1, const Money& amount2) {
  return ((amount1.dollars_ == amount2.dollars_) &&
          (amount1.cents_ == amount2.cents_));
}

const Money operator -(const Money& amount) {
  return Money(-amount.dollars_, -amount.cents_);
}

 
Money::Money( ): dollars_(0), cents_(0)
{/*Body intentionally empty.*/}

Money::Money(double amount)
              : dollars_(DollarsPart(amount)), cents_(CentsPart(amount))
{/*Body intentionally empty*/}

Money::Money(int theDollars)
              : dollars_(theDollars), cents_(0)
{/*Body intentionally empty*/}

//Uses cstdlib:
Money::Money(int theDollars, int theCents) {
  if ((theDollars < 0 && theCents > 0) ||
      (theDollars > 0 && theCents < 0)) {
    cout << "Inconsistent money data.\n";
    exit(1);
  }
  dollars_ = theDollars;
  cents_ = theCents;
}

double Money::GetAmount( ) const {
  return (dollars_ + cents_*0.01);
}

int Money::GetDollars( ) const {
  return dollars_;
}

int Money::GetCents( ) const {
  return cents_;
}

//Uses iostream and cstdlib:
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

//Uses iostream and cstdlib:
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

int Money::DollarsPart(double amount) const {
  return static_cast<int>(amount);
}

int Money::CentsPart(double amount) const {
  double double_cents = amount*100;

  // can misbehave on negatives
  int int_cents = (Round(fabs(double_cents)))%100;
  if (amount < 0)
    int_cents = -int_cents;
  return int_cents;
}

int Money::Round(double number) const {
  return static_cast<int>(floor(number + 0.5));
}




