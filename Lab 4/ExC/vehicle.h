#ifndef VEHICLE
#define VEHICLE

Class Vehicle: public Moveable, public Resizeable
{
	protected:
	string name;
	
	public:
	Vehicle(string name);
	virtual void move() = 0;
} 

#endif