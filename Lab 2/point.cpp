/*
*  File Name: point.cpp
*  Assignment: ENSF 480 - Lab 2 - Exercise A
*  Completed by: Jiho Kim, Garth Slaney
*  Submission Date: 
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include "point.h"

int Point::idGen=1001;

// Initializes the data members 
Point::Point(double x, double y)
{
	this->x=x;
	this->y=y;
	id = idGen++;
}

// Return the number of objects of class Point 
int Point::counter(){
	return idGen - 1001;
}
	
// Displays the x and y coordinates of the point 
void Point::display()const
{
	cout<<"X-coordinate: " <<fixed <<setfill('0') <<setw(9) << setprecision(2) <<x <<endl;  
	cout<<"Y-coordinate: " <<fixed <<setfill('0') <<setw(9) << setprecision(2) <<y <<endl; 
}
	
// Caculate distance bewteen this point and another point  
double Point::distance(const Point& p1)
{
	return sqrt( pow((x - p1.getX()),2) + pow((y - p1.getY()),2));
}
	
//Caculates the distance bewteen two points 
double Point::distance(const Point& p1, const Point& p2)
{
	return sqrt( pow((p1.getX() - p2.getX()),2) + pow((p1.getY() - p2.getY()),2));
}

