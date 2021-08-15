#include "StaticObject.h"
#include <iostream>
using namespace std;

StaticObject::StaticObject()
{
}

StaticObject::StaticObject(string id, string name, int x, int y) : BaseObject(id, name, x, y) {
}

StaticObject::~StaticObject()
{
	//cout << "Static object deleted" << endl;
}

void StaticObject::move(int x, int y)
{
	cout << "Static object " << this->getName() << " can't be moved" << endl;
}
