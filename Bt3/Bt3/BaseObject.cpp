#include "BaseObject.h"
#include <iostream>
using namespace std;

BaseObject::BaseObject() {
	this->id = "AAA";
	this->name = "None";
	this->position_x = 0;
	this->position_y = 0;
}
BaseObject::BaseObject(string id, string name, int x, int y) {
	this->id = id;
	this->name = name;
	this->position_x = x;
	this->position_y = y;
}
BaseObject::~BaseObject() {
	//cout << "Base Object deleted" << endl;
};
string BaseObject::getid() {
	return this->id;
}
string BaseObject::getName() {
	return this->name;
}
int BaseObject::getpos_x(){
	return this->position_x;
}
int BaseObject::getpos_y(){
	return this->position_y;
}
void BaseObject::setid(string x){
	this->id = x;
}
void BaseObject::setname(string x){
	this->name = x;
}
void BaseObject::setpos_x(int k){
	this->position_x = k;
}
void BaseObject::setpos_y(int k){
	this->position_y = k;
}
void BaseObject::move(int x, int y){
	this->position_x = x;
	this->position_y = y;
}
void BaseObject::printPosition(){
	cout << "Current Position: " << this->position_x << " " << this->position_y << endl;
}