/****************************************************************
 * Header for the 'Factorial' class
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/

#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <vector>

using namespace std;

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class Factorial {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
 Factorial();
 virtual ~Factorial();

/****************************************************************
 * General functions.
**/
 LONG DoFactorial(int& level, LONG n);
private:

/****************************************************************
 * General private functions.
**/
};

#endif // FACTORIAL_H
