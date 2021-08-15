#include "DynamicObject.h"

#ifndef __Motorbike_h__
#define __Motorbike_h__

class Motorbike : public DynamicObject {
public:
	Motorbike() {
		cout << "A Motorbike created" << endl;
	}
	~Motorbike() {
		cout << "A Motorbike deteted" << endl;
	}
};

#endif