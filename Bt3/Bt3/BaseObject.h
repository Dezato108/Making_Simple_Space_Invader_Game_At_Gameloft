#include <iostream>
#include <string>
using std::string;
using namespace std;

#ifndef __BaseObject_h__
#define __BaseObject_h__

class BaseObject {

private:
	string id;
	string name;
	int position_x=0;
	int position_y=0;

public :
	BaseObject(){
		cout << "Base Object created"<<endl;
	}
	~BaseObject(){
		cout << "Base Object deleted"<<endl;
	}
	void setid(string x);
	void setname(string x);
	void setpos_x(int k);
	void setpos_y(int k);

	string getName();
	string getid();
	void move(int pos_x, int pos_y);	
	void printPosition();
};

void BaseObject::setid(string x)
{
	this->id = x;
}

void BaseObject::setname(string x)
{
	this->name = x;
}

void BaseObject::setpos_x(int k) {
	this->position_x = k;
}

void BaseObject::setpos_y(int k)
{
	this->position_y = k;
}

string BaseObject::getName() {
	return this->name;
}
string BaseObject::getid() {
	return this->id;
}
void BaseObject::move(int pos_x, int pos_y) {
	cout << "Object ID: " << this->getid() << endl;
	cout << "Move position from " << this->position_x << "," << this->position_y << " to " << pos_x << "," << pos_y << endl;
	this->position_x = pos_x;
	this->position_y = pos_y;
}
void BaseObject::printPosition() {
	cout << "Current Position: " << this->position_x << " " << this->position_y << endl;
}

#endif