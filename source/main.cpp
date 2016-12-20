/*
BriefDemoDestructors
(c) 2016
original authors: David I. Schwartz
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*	This tutorial is a brief tutorial about constructor and destructor.
*	It covers issues such as keyword new, definition and declaration of class.
*/

// copied from http://www.cplusplus.com/doc/tutorial/classes:
#include <iostream>  // for output
using namespace std; // for output

class CRectangle {  // define class CRectangle
	int *width, *height;  // declare two pointers point to int type variables as (private) members
public:
	CRectangle (int,int); // constructor
	~CRectangle ();       // destructor
	int area () {return (*width * *height);}  // declare member function area that returns to the product of the dereferences of width and height
};

CRectangle::CRectangle (int a, int b) {  // define constructor
	width = new int;     // allocate memory for width
	height = new int;    // allocate memory for height
	*width = a;          // put the parameter a to the pointee of the width
	*height = b;         // put the parameter b to the pointee of the height
}

CRectangle::~CRectangle () {  // define destructor
	delete width;       // deallocate memory
	delete height;      // deallocate memory
}

int main () {
	CRectangle rect (3,4), rectb (5,6);  // instantiate two CRectangle object rect and rectb, pass 3,4 and 5,6 as their arguments
	cout << "rect area: " << rect.area() << endl;   // output: rect area: 12
	cout << "rectb area: " << rectb.area() << endl; // output: rectb area: 30
	return 0;
}