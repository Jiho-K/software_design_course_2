/*
*  File Name: circle.h
*  Assignment: ENSF 480 - Lab 2 - Exercise A
*  Completed by: Jiho Kim, Garth Slaney
*  Submission Date: October. 1. 2020
*/
#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include <iostream>
using namespace std;

class Circle: virtual public Shape
{
	public:
	// Constructor for Circle. x, y are the coordinates of the origin
	// r is the radius of the circle, name is the name of the shape
	Circle(double x, double y, double r, const char* name):Shape(x, y, name){radius = r;}
	
	double get_radius(){return radius;}
	
	void set_radius(double a){radius = a;}
	
	// returns area of the circle
	double area();
	
	//Returns perimeter of circle 
	double perimeter();
	
	//Display information of circle 
	void display();
	
	private:
	double radius;
	
};

#endif