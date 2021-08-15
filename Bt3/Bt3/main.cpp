#include <iostream>
#include <list>
using namespace std;

#include "Car.h"
#include "Motorbike.h"
#include "House.h"
#include "Tree.h"

int main() {
	std::list<BaseObject*> listObject;
	cout << "---Create obj1---" << endl;
	BaseObject *obj1 = new Car();
	obj1->setid("V01");	obj1->setname("VinFast"); obj1->setpos_x(1); obj1->setpos_y(2); 
	listObject.push_back(obj1);
	cout << endl;

	cout << "---Create obj2---" << endl;
	BaseObject *obj2 = new Motorbike();
	obj2->setid("E02");	obj2->setname("Exciter"); obj2->setpos_x(3); obj2->setpos_y(4);
	listObject.push_back(obj2);
	cout << endl;

	cout << "---Create obj3---" << endl;
	BaseObject *obj3 = new House();
	obj3->setid("H03");	obj3->setname("VinHome"); obj3->setpos_x(4); obj3->setpos_y(5);
	listObject.push_back(obj3);
	cout << endl;

	cout << "---Create obj4---" << endl;
	BaseObject *obj4 = new Tree();
	obj4->setid("T04");	obj4->setname("Blossom Tree"); obj4->setpos_x(7); obj4->setpos_y(6);
	listObject.push_back(obj4);
	cout << endl;

	cout << "---List Object---" << endl;
	for (auto obj : listObject) {
		cout<<"Object ID: "<<obj->getid()<<"; Object Name: "<<obj->getName()<< endl;
		obj->printPosition();
	}
	cout << endl;

	cout << "---Change object position---"<<endl;
	for (auto obj : listObject) {
		if (obj->getid() == "V01") obj->move(4,7);
		if (obj->getid() == "E02") obj->move(2,10);
		if (obj->getid() == "H03") obj->move(8,3);
		if (obj->getid() == "T04") obj->move(1,6);
	}
	cout << endl;

	cout << "---List Object after move position---" << endl;
	for (auto obj : listObject) {
		cout << "Object ID: " << obj->getid() << "; Object Name: " << obj->getName() << endl;
		obj->printPosition();
	}
	cout << endl;

	cout << "---Free memory---"<<endl;
	for (auto obj : listObject) {
		delete obj;
	}
	listObject.clear();
	//Dump memory leaks
	_CrtDumpMemoryLeaks();
	return 0;
}