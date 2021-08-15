#include "BaseObject.h"

#ifndef __StaticObject_h__
#define __StaticObject_h__

class StaticObject : public BaseObject{
public:
	StaticObject() {
		cout << "Static Object created" << endl;
	}
	~StaticObject() {
		cout << "Static Object deteted" << endl;
	}
};

#endif