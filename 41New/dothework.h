/****************************************************************
 * Header for the 'new' example code.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 9 July 2016
**/

#ifndef DOTHEWORK_H
#define DOTHEWORK_H

#include <iostream>
#include <map>
using namespace std;

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class DoTheWork {
public:
 DoTheWork();
 virtual ~DoTheWork();

 int* GetPtr();
 void TestNew1();
 void TestNew2();
 void TestNew3();
 string ToString() const;

private:
  int *saved_pointer_ = nullptr;
};

#endif
