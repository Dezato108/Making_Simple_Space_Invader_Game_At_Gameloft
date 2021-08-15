#pragma once
#include "StaticObject.h"
class Tree : public StaticObject
{
public:
	Tree();
	Tree(string id,string name,int x,int y);
	~Tree();
};

