/*
*  File Name: rectangle.h
*  Assignment: ENSF 480 - Lab 2 - Exercise A
*  Completed by: Jiho Kim, Garth Slaney
*  Submission Date: 
*/
#ifndef REC_H
#define REC_H
#include "square.h"
#include <iostream>
using namespace std;

class Rectangle: public Square
{
	public:
	
	Rectangle(double x, double y, double a, double b, const char* name)
		:Shape(x, y, name), Square(x, y, a, name) {side_b =b;}
	//Caculate the area of the rectangle 
	double area();
	
	//Cacualate the perimeter the rectangle
	double perimeter();
	
	double getB()const{return side_b;}
	
	void set_side_b(double b){side_b = b;}
	
	//Display the information about the rectangle 
	void display();
	
	private:
	double side_b;
};

#endif