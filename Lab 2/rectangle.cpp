#include <iostream>
#include "square.h"
#include "shape.h"
#include "point.h"
#include "rectangle.h"

//Caculate the area of the rectangle 
double Rectangle::area()
{
	return getA()*side_b;
}
	
//Cacualate the perimeter the rectangle
double Rectangle::perimeter()
{
	return 2*side_b + 2*getA();
}
	
//Display the information about the rectangle 
void Rectangle::display()
{
	cout<< "Rectangle Name: " << getName() <<endl;
	getOrigin().display();
	cout<<"Side a: " << getA() <<endl;
	cout<<"Side b: " <<side_b <<endl;
	cout<<"Area: " << area() <<endl;
	cout<<"Perimeter: " << perimeter() <<endl;
}
	