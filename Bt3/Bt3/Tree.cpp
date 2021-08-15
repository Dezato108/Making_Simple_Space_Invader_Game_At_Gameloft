#include "Tree.h"
#include <iostream>
using namespace std;
Tree::Tree()
{
}

Tree::Tree(string id, string name, int x, int y) : StaticObject(id,name,x,y)
{
	cout << "Creating object Tree..." << endl;
}

Tree::~Tree()
{
	cout << "Object Tree deleted" << endl;
}
