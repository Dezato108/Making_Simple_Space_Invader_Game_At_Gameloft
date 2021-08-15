#include <string>
using std::string;

#ifndef __BaseObject_h__
#define __BaseObject_h__
class BaseObject
{
private:
	string id;
	string name;
	int position_x;
	int position_y;

public:
	BaseObject();
	BaseObject(string id, string name, int x, int y);
	virtual ~BaseObject();
	void setid(string x);
	void setname(string x);
	void setpos_x(int k);
	void setpos_y(int k);

	string getid();
	string getName();
	int getpos_x();
	int getpos_y();

	virtual void move(int x, int y);
	void printPosition();
};

#endif


