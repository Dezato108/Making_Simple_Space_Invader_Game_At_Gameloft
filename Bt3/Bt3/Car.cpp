#include "Car.h"
#include <iostream>
using namespace std;
Car::Car()
{
	
}
Car::Car(string id, string name, int x, int y) : DynamicObject(id,name,x,y)
{
	cout << "Creating object Car..." << endl;
}
Car::~Car()
{
	cout << "Object Car deleted" << endl;
}
