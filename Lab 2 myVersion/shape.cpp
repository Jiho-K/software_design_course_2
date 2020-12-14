/*
*  File Name: shape.cpp
*  Assignment: ENSF 480 - Lab 2 - Exercise A
*  Completed by: Jiho Kim, Garth Slaney
*  Submission Date: 
*/
#include <iostream>
#include <string.h>
#include "point.h"
#include "shape.h"
using namespace std;

//Initilaizes data members 
Shape::Shape(double x, double y, const char* name)
	:origin(Point(x,y)), shapeName(new char[strlen(name)+1])
{
	if(shapeName== NULL)
  {
		cerr<< "Memory not available...";
		exit(1);
	}
	strcpy(shapeName, name);
}
	
//Display the shape info 
void Shape::display()const
{
	cout<< "Shape Name: " << shapeName <<endl;
	origin.display();
}
	
//Caculates distance to another shape
double Shape::distance(Shape& other)
{
	return origin.distance(other.getOrigin());
}
	
//Caculates the distance bewteen two shapes 
double Shape::distance(Shape& the_shape, Shape& other)
{
	return Point::distance(the_shape.getOrigin(), other.getOrigin());
}
	
//Changes the postion of the shape 
void Shape::move (double dx, double dy)
{
	origin.setX(origin.getX() + dx);
	origin.setY(origin.getY() + dy);
}
	
Shape::~Shape()
{
	delete[] shapeName;
}

//Copy constructor 
Shape::Shape(const Shape& source):origin(source.origin), 
shapeName(new char[strlen(source.shapeName)+1])
{
	if(shapeName== NULL)
  {
		cerr<< "Memory not available...";
		exit(1);
	}
	strcpy(shapeName, source.shapeName);
}

//Assignment operator 
Shape& Shape::operator=(const Shape& rhs)
{
	if(this==&rhs)
		return*this;
	delete[] shapeName;
	shapeName= new char[strlen(rhs.shapeName)+1];
	if(shapeName== NULL)
	{
		cerr<< "Memory not available...";
		exit(1);
	}
	strcpy(shapeName, rhs.shapeName);
	origin= rhs.origin;
	return*this;
}
