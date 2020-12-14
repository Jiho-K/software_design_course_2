#include <iostream>
#include "circle.h"
#include "shape.h"
#include "point.h"
#include <math.h>
using namespace std;

//Caculate the area of the rectangle 
double Circle::area()
{
	return M_PI * pow(get_radius(), 2);
}
	
//Cacualate the perimeter the rectangle
double Circle::perimeter()
{
	return M_PI * 2 * get_radius();
}
	
//Display the information about the rectangle 
void Circle::display()
{
	cout<< "Circle Name: " << getName() <<endl;
	getOrigin().display();
	cout<<"radius: " << get_radius() <<endl;
	cout<<"Area: " << area() <<endl;
	cout<<"Perimeter: " << perimeter() <<endl;
}
	