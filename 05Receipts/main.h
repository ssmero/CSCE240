/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 *
 * This is a basic boilerplate dot h file.
 * 
 * The inclusion of the 'iostream' allows you to read and write from input
 * and output "streams".
 *
 * The line above with the numbers can be used a a guide to make sure you
 * don't go beyond 80 characters across.
 *
 * The ifndef helps to define a symbol to the compiler that says you have
 * already done the 'include' on this file. Java is very forgiving about
 * letting you 'import' multiple times from multiple different classes.
 * If you have a class X that does an 'import yadayada' of another class,
 * but also imports class Y that does an 'import yadayada', then Java will
 * only do the import once. C++ will try to do the 'include' each time, and
 * this means you can wind up with duplicated symbols and error messages.
 * So this line defines a symbol to the compiler, and if the compiler tries
 * to do an 'include' a second time, the existence of the defined symbol
 * says that the file has already been included.
 *
 * One of the VERY BIG differences between C++ and Java is that the Java
 * 'interface' only says what MUST be implemented in order not to get errors.
 * In C++, it is (ALMOST) REQUIRED that all variables, function names,
 * and similar symbols be declared in the dot h file.
 *
 * Don't worry about the 'virtual' nonsense at this point.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
 *
**/

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
using namespace std;

class Main {
public:

private:

};

#endif // MAIN_H
