#include "BaseObject.h"

#ifndef __DynamicObject_h__
#define __DynamicObject_h__

class DynamicObject : public BaseObject {

public:
	DynamicObject() {
		cout << "Dynamic Object created" << endl;
	}
	~DynamicObject() {
		cout << "Dynamic Object deleted" << endl;
	}

};



#endif