#include "StaticObject.h"

#ifndef __House_h__
#define __House_h__

class House : public StaticObject {
public:
	House() {
		cout << "A House created" << endl;
	}
	~House() {
		cout << "A House deteted" << endl;
	}
};

#endif