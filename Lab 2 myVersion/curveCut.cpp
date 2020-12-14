#include <iostream>
#include "square.h"
#include "circle.h"
#include "shape.h"
#include "point.h"
#include "curveCut.h"
#include <math.h>
using namespace std;

//Caculate the area of the rectangle 
double CurveCut::area()
{
	return Rectangle::area() - Circle::area() / 4;
}
	
//Cacualate the perimeter the rectangle
double CurveCut::perimeter()
{
	return 2 * Rectangle::perimeter() - 2 * Circle::get_radius() + M_PI * Circle::get_radius() / 2;
}
	
//Display the information about the rectangle 
void CurveCut::display()
{
	cout<< "CurveCut Name: " << getName() <<endl;
	getOrigin().display();
	cout<<"Width: " << Rectangle::getA() <<endl;
	cout<<"Length: " << Rectangle::getB() <<endl;
	cout<<"Radius of the cut: " << Circle::get_radius() <<endl;
}
	