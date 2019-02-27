#include "main.h"

static const string kTag = "MAIN: ";

/****************************************************************
 * Savitch 08-03 program.
 * Author: Savitch, mods by Duncan Buell
 * Date last modified: 28 September 2009
 *
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

    cout << "zork amount is " << my_amount << endl;

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
