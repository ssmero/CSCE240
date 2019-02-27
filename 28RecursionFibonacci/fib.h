/****************************************************************
 * Header for the 'Fib'onacci class
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/

#ifndef FIB_H
#define FIB_H

#include <vector>

using namespace std;

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class Fib {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
 Fib();
 virtual ~Fib();

/****************************************************************
 * General functions.
**/
 LONG DoFib(int& level, LONG n);
private:

/****************************************************************
 * General private functions.
**/
};

#endif // FIB_H
