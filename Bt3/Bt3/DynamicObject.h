#pragma once
#include "BaseObject.h"
class DynamicObject : public BaseObject
{
public:
	DynamicObject();
	DynamicObject(string id, string name, int x, int y);
	~DynamicObject();
	void move(int x, int y);
};

