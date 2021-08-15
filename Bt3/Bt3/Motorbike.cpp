#include "Motorbike.h"
#include <iostream>
using namespace std;
Motorbike::Motorbike()
{
}

Motorbike::Motorbike(string id, string name, int x, int y) : DynamicObject(id, name, x, y)
{
	cout << "Creating object Motorbike..." << endl;
}

Motorbike::~Motorbike()
{
	cout << "Object Motorbike deleted" << endl;
}
