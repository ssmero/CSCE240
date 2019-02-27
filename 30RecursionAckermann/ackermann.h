/****************************************************************
 * Header for the 'Ackermann' class
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/

#ifndef ACKERMANN_H
#define ACKERMANN_H

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

using namespace std;

class Ackermann {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
 Ackermann();
 virtual ~Ackermann();

/****************************************************************
 * General functions.
**/
 LONG DoAckermann(int& level, LONG m, LONG n);

private:

/****************************************************************
 * General private functions.
**/
};

#endif // ACKERMANN_H
