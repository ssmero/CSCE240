/****************************************************************
 * Header file for revised Savitch 08-02 program.
 * Author: Savitch, mods by Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/
#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

#include "../../Utilities/utils.h"

using namespace std;

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
class Money
{
public:
 Money( );
 Money(double amount);
 Money(int dollars, int cents);
 Money(int dollars);

 double GetAmount( ) const;
 int GetCents( ) const;
 int GetDollars( ) const;

 bool Equals(const Money& amount2) const;
 void Input(); //Reads the dollar sign as well as the amount number.
 Money Minus(const Money& amount2) const;
 Money Negate() const;
 void Output() const;
 Money Plus(const Money& amount2) const;
 string ToString() const;

/****************************************************************
 * These next four functions are the overloaded 'friend' operators.
**/
 friend const Money operator +(const Money& amount1,
                               const Money& amount2);
 friend const Money operator -(const Money& amount);
 friend const Money operator -(const Money& amount1,
                               const Money& amount2);
 friend bool operator ==(const Money& amount1, const Money& amount2);

 friend ostream& operator <<(ostream& output_stream, const Money& amount2);

private:
 int dollars_; //A negative amount is represented as negative dollars and
 int cents_; //negative cents. Negative $4.50 is represented as -4 and -50

 int DollarsPart(double amount) const;
 int CentsPart(double amount) const;
 int Round(double number) const;
};

#endif /*MONEY_H*/
