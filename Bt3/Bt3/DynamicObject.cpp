#include "DynamicObject.h"
#include<iostream>
using namespace std;
DynamicObject::DynamicObject() {
}

DynamicObject::DynamicObject(string id, string name, int x, int y) : BaseObject(id,name,x,y){
}

DynamicObject::~DynamicObject() {
	//cout << "Dynamic Object deleted" << endl;
}

void DynamicObject::move(int x, int y)
{
	cout << "Dynamic object " << this->getName() << "'s position has been moved to " <<x<<" "<<y<< endl;
	this->setpos_x(x);
	this->setpos_y(y);
}
