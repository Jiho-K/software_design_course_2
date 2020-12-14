/*
*  File Name: shape.h
*  Assignment: ENSF 480 - Lab 2 - Exercise A
*  Completed by: Jiho Kim, Garth Slaney
*  Submission Date: 
*/
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include "point.h"
using namespace std;

// The base class of Rectangle, Square, Circle 
// Supports basic operations needed for the children of this class
class Shape{
	public:
	//Initilaizes data members 
	Shape(double x, double y,const char* name);
	~Shape();
	Shape& operator=(const Shape& rhs);
	Shape(const Shape& source);
	
	//Returns refrence to point that can't be changed
	const Point& getOrigin()const{return origin;};
	
	const char* getName()const{return shapeName;};
	
	//Display the shape info 
	void display()const;
	
	//Caculates distance to another shape
	double distance(Shape& other);
	
	//Caculates the distance bewteen two shapes 
	static double distance(Shape& the_shape, Shape& other);
	
	//Changes the postion of the shape 
	void move (double dx, double dy);
	
	virtual double area() = 0;
	
	virtual double perimeter() = 0;
	
	private:
	Point origin;  
	char* shapeName;
};

#endif