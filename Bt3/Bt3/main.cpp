#include <iostream>
#include <list>
using namespace std;

#include "Car.h"
#include "Motorbike.h"
#include "House.h"
#include "Tree.h"

int main() {
	std::list<BaseObject*> listObject;
	cout << "---Creating list of Objects---" << endl;
	
	BaseObject* obj1 = new Car("V01","VinFast",1, 2);	
	listObject.push_back(obj1);	
	
	BaseObject* obj2 = new Motorbike("E02","Exciter",3, 4);	
	listObject.push_back(obj2);	
	
	BaseObject* obj3 = new House("H03","VinHome",4, 5);
	listObject.push_back(obj3);	
	
	BaseObject* obj4 = new Tree("T04","Blossom Tree",7, 6);
	listObject.push_back(obj4);
	cout << endl;

	cout << "---List of Object---" << endl;
	for (auto obj : listObject) {
		cout << "Object ID: " << obj->getid() << "; Object Name: " << obj->getName() << endl;
		obj->printPosition();
		cout << endl;
	}	

	cout << "---Change object position---" << endl;
	for (auto obj : listObject) {
		obj->move(9,6);
		cout << endl;
	}	

	cout << "---List of Object after move position---" << endl;
	for (auto obj : listObject) {
		cout << "Object ID: " << obj->getid() << "; Object Name: " << obj->getName() << endl;
		obj->printPosition();
		cout << endl;
	}	

	cout << "---Free memory---" << endl;
	for (auto obj : listObject) {
		delete obj;
	}
	listObject.clear();
	//Dump memory leaks
	_CrtDumpMemoryLeaks();
	return 0;
}