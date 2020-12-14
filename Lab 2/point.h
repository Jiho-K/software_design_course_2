/*
*  File Name: point.h
*  Assignment: ENSF 480 - Lab 2 - Exercise A
*  Completed by: Jiho Kim, Garth Slaney
*  Submission Date: 
*/
#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;

class Point{
	public:
	
	// Initializes the data members 
	Point(double x, double y);
	
	void setX(double x){this->x = x;}
	
	void setY(double y){this->y = y;}
	
	double getX()const{return x;}
	
	double getY()const{return y;}
	
  // Return the number of objects of class Point 
	int counter();
	
	// Displays the x and y coordinates of the point 
	void display()const;
	
	// Caculate distance to another point  
	double distance(const Point& p1);
	
	//Caculates the distance bewteen two points 
	static double distance(const Point& p1, const Point& p2);
	
	private: 
	double x;  //X-Coordinate
	double y;  //Y-Coordinate
	int id;  //Unique identification
	static int idGen;  //Static variable to generate id's
}; 

#endif