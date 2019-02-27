/****************************************************************
 * Header file for the grocery receipt program with a separate
 * class for doing the computation.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
**/

#ifndef DOTHEWORK_H
#define DOTHEWORK_H

#include <iostream>
#include <vector>
using namespace std;

#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

#include "xact.h"

class DoTheWork {
public:
 DoTheWork();
 virtual ~DoTheWork();

 void ProcessInput(Scanner& in_scanner);

private:
 int number_of_transactions_; // number of lines of input

 double running_total_cost_;

 vector<Xact> the_data_;

 void ReadData(Scanner& in_scanner);

};

#endif
