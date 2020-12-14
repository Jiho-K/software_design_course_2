/*
*  File Name: square.cpp
*  Assignment: ENSF 480 - Lab 2 - Exercise A
*  Completed by: Jiho Kim, Garth Slaney
*  Submission Date: 
*/
#include <iostream>
#include "square.h"
#include "shape.h"
#include "point.h"

//Return area of square 
double Square::area()
{
	return side_a*side_a;
}
	
//Returns perimeter of square 
double Square::perimeter()
{
	return 4*side_a;
}
	
//Display information of square 
void Square::display()
{
	cout<< "Square Name: " << getName() <<endl;
	getOrigin().display();
	cout<<"Side a: " << side_a <<endl;
	cout<<"Area: " << area() <<endl;
	cout<<"Perimeter: " << perimeter() <<endl;
}
	