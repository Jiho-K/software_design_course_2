/*
*  File Name: curveCut.h
*  Assignment: ENSF 480 - Lab 2 - Exercise A
*  Completed by: Jiho Kim, Garth Slaney
*  Submission Date: October. 1. 2020
*/
#ifndef CURVECUT_H
#define CURVECUT_H
#include "rectangle.h"
#include "circle.h"
#include <iostream>
using namespace std;

class CurveCut: public Circle, public Rectangle
{
	public:
	// Constructor for CurveCut. x, y are the coordinates of the origin. a, b are the length/width of the rectangle.
	// r is the radius of the circle, name is the name of the shape
	CurveCut(double x, double y, double a, double b, double r, const char* name)
		:Shape(x, y, name), Circle(x, y, r, name), Rectangle(x, y, a, b, name) 
		{if(r>=a|| r>= b){cerr<< "Radius can not be bigger then width or length";exit(1);}}
	
	// returns area of the circle
	double area();
	
	//Returns perimeter of circle 
	double perimeter();
	
	//Display information of circle 
	void display();
	
	
};
#endif