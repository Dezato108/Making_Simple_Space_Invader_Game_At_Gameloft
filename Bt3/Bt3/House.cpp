#include "House.h"
#include <iostream>
using namespace std;
House::House()
{
}

House::House(string id, string name, int x, int y) : StaticObject(id,name,x,y)
{
	cout << "Creating object House..." << endl;
}

House::~House()
{
	cout << "Object House deleted" << endl;
}
