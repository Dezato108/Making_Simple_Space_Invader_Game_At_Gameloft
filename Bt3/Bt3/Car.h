#pragma once
#include "DynamicObject.h"
class Car : public DynamicObject
{
public:
	Car();
	Car(string id, string name, int x, int y);
	~Car();
};

