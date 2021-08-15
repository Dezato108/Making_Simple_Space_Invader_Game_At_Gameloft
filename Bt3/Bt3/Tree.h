#include "StaticObject.h"

#ifndef __Tree_h__
#define __Tree_h__

class Tree : public StaticObject {
public:
	Tree() {
		cout << "A Tree created" << endl;
	}
	~Tree() {
		cout << "A Tree deteted" << endl;
	}
};

#endif