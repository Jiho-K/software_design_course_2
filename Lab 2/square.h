/*
*  File Name: square.h
*  Assignment: ENSF 480 - Lab 2 - Exercise A
*  Completed by: Jiho Kim, Garth Slaney
*  Submission Date: 
*/
#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
#include <iostream>
using namespace std;

class Square: virtual public Shape
{
	public:
	
	//Constructor which calls the super of shape
	Square(double x, double y, double a, const char* name):Shape(x,y,name){side_a=a;}
	
	double getA(){return side_a;}
	
	void set_side_a(double a){side_a = a;}
	
	//Return area of square 
	double area();
	
	//Returns perimeter of square 
	double perimeter();
	
	//Display information of square 
	void display();
	
	private:
	double side_a;
};

#endif