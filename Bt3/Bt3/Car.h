#include "DynamicObject.h"

#ifndef __Car_h__
#define __Car_h__

class Car : public DynamicObject {
public:
	Car() {
		cout << "A Car created" << endl;
	}
	~Car() {
		cout << "A Car deteted" << endl;
	}
};

#endif